import streamlit as st
import json
import difflib
from pygments import highlight
from pygments.lexers import DiffLexer, CLexer, NasmLexer
from pygments.formatters import HtmlFormatter
import re
import uuid

def load_data(uploaded_file):
    if uploaded_file is not None:
        try:
            content = uploaded_file.getvalue().decode('utf-8')
            return json.loads(content)
        except json.JSONDecodeError:
            st.error("Invalid JSON file. Please upload a valid JSON file.")
        except Exception as e:
            st.error(f"An error occurred while loading the file: {str(e)}")
    return None

def trim_code(code):
    lines = code.split('\n')
    non_empty_lines = [line for line in lines if line.strip()]
    return '\n'.join(non_empty_lines)

def remove_html_tags(code):
    return re.sub(r'(\s*</div>\s*)+$', '', code)

def display_highlighted_code(code, lexer):
    code = trim_code(code)
    formatter = HtmlFormatter(style="default")
    highlighted_code = highlight(code, lexer, formatter)
    highlighted_code = remove_html_tags(highlighted_code)
    
    st.markdown(
        f"""
        <style>
        {formatter.get_style_defs('.highlight')}
        .highlight {{ background-color: #f8f8f8; }}
        </style>
        """,
        unsafe_allow_html=True,
    )
    st.markdown(
        f"""
        <div style="background-color: #f8f8f8; padding: 10px; border-radius: 5px; margin-bottom: 20px;">
            <div style="background-color: #f8f8f8; white-space: pre-wrap; font-family: 'Courier New', monospace;">
                {highlighted_code}
            </div>
        </div>
        """,
        unsafe_allow_html=True,
    )

def display_diff(gt, pred):
    gt = trim_code(gt)
    pred = trim_code(pred)
    d = difflib.unified_diff(
        pred.splitlines(),
        gt.splitlines(),
        fromfile="Predicted",
        tofile="Ground Truth",
        lineterm="",
        n=10000,
    )
    diff_with_breaks = "\n".join(d)
    formatter = HtmlFormatter(style="default")
    lexer = DiffLexer()
    highlighted_diff = highlight(diff_with_breaks, lexer, formatter)
    highlighted_diff = remove_html_tags(highlighted_diff)
    
    st.markdown(
        """
        <style>
        .highlight { background-color: #f8f8f8; }
        .diff-header { color: #998; font-weight: bold; }
        .diff-add { background-color: #e6ffed; }
        .diff-remove { background-color: #ffeef0; }
        </style>
        """,
        unsafe_allow_html=True,
    )
    st.markdown(
        f"""
        <div style="background-color: #f8f8f8; padding: 10px; border-radius: 5px; margin-bottom: 20px;">
            <div style="background-color: #f8f8f8; white-space: pre-wrap; font-family: 'Courier New', monospace;">
                {highlighted_diff}
            </div>
        </div>
        """,
        unsafe_allow_html=True,
    )

def side_by_side_diff(gt, pred):
    gt_lines = gt.splitlines()
    pred_lines = pred.splitlines()
    
    differ = difflib.Differ()
    diff = list(differ.compare(pred_lines, gt_lines))
    
    gt_formatted = []
    pred_formatted = []
    
    for line in diff:
        if line.startswith('  '):  # unchanged
            gt_formatted.append(f'<span>{line[2:]}</span>')
            pred_formatted.append(f'<span>{line[2:]}</span>')
        elif line.startswith('- '):  # in pred, not in gt
            pred_formatted.append(f'<span style="background-color: #ffeef0;">{line[2:]}</span>')
            gt_formatted.append('<span>&nbsp;</span>')
        elif line.startswith('+ '):  # in gt, not in pred
            gt_formatted.append(f'<span style="background-color: #e6ffed;">{line[2:]}</span>')
            pred_formatted.append('<span>&nbsp;</span>')
    
    return gt_formatted, pred_formatted

def display_side_by_side(gt, pred):
    gt_formatted, pred_formatted = side_by_side_diff(gt, pred)
    
    st.markdown(
        f"""
        <style>
        .diff-container {{
            display: flex;
            font-family: 'Courier New', monospace;
        }}
        .diff-column {{
            flex: 1;
            padding: 10px;
            background-color: #f8f8f8;
            border-radius: 5px;
            margin: 5px;
            white-space: pre-wrap;
        }}
        </style>
        <div class="diff-container">
            <div class="diff-column">
                <h4>Ground Truth</h4>
                {'<br>'.join(gt_formatted)}
            </div>
            <div class="diff-column">
                <h4>Predicted</h4>
                {'<br>'.join(pred_formatted)}
            </div>
        </div>
        """,
        unsafe_allow_html=True
    )


def main():
    st.set_page_config(layout="wide", page_title="x86 to ARM Assembly Converter", page_icon="🔄")
    
    st.markdown(
        """
        <style>
        .main > div {
            padding-top: 2rem;
        }
        .stExpander {
            border: 1px solid #ddd;
            border-radius: 5px;
            margin-bottom: 1rem;
        }
        .stExpander > div > div > div > div {
            background-color: #f8f8f8;
        }
        </style>
        """,
        unsafe_allow_html=True,
    )
    
    st.title("🔄 x86 to ARM Assembly Conversion Viewer")
    
    uploaded_file = st.file_uploader("Choose a JSON file", type="json")
    
    if uploaded_file is not None:
        data = load_data(uploaded_file)
        if data:
            # Separate problems into categories
            correct_problems = [p for p in data if p['is_success']]
            incorrect_problems = [p for p in data if not p['is_success']]
            perfect_problems = [p for p in correct_problems if p['ed'] == 0]
            imperfect_problems = [p for p in correct_problems if p['ed'] > 0]

            # Add a sidebar with categories
            st.sidebar.title("Problem Selection")
            category = st.sidebar.radio(
                "Select Category",
                ["Correct (ED = 0)", "Correct (ED > 0)", "Incorrect"]
            )

            if category == "Correct (ED = 0)":
                problems = perfect_problems
            elif category == "Correct (ED > 0)":
                problems = imperfect_problems
            else:
                problems = incorrect_problems

            if problems:
                problem_index = st.sidebar.selectbox(
                    f"Select {category} Problem",
                    range(len(problems)),
                    format_func=lambda x: f"Problem {problems[x]['file'].split('/')[-2].lstrip('problem')} - ED {problems[x]['ed']}"
                )
                
                problem = problems[problem_index]
                
                # Display problem number and edit distance on the same line
                problem_number = problem['file'].split('/')[-2].lstrip('problem')
                st.markdown(f"<h2>Problem {problem_number} <span style='float: right;'>Edit Distance: {problem['ed']}</span></h2>", unsafe_allow_html=True)
                
                with st.expander("C Code", expanded=False):
                    display_highlighted_code(problem['c_code'], CLexer())
                
                with st.expander("x86 Assembly", expanded=False):
                    display_highlighted_code(problem['input'], NasmLexer())
                
                # Display result message for incorrect problems
                if category == "Incorrect":
                    with st.expander("Result Message", expanded=False):
                        st.error(problem['result_message'])
                
                st.subheader("ARM Assembly")
                if category == "Correct (ED = 0)":
                    # For ED=0, show ground truth ARM assembly in a clickable expander
                    with st.expander("Show Ground Truth ARM Assembly", expanded=False):
                        display_highlighted_code(problem['gt'], NasmLexer())
                else:
                    # For ED>0 and Incorrect, show diff and side-by-side comparison
                    with st.expander("Show Difference", expanded=False):
                        display_diff(problem['pred'], problem['gt'])
                    
                    with st.expander("Side-by-Side Comparison", expanded=False):
                        display_side_by_side(problem['gt'], problem['pred'])
            else:
                st.info(f"No problems in the '{category}' category.")
        else:
            st.error("Failed to load the JSON file. Please make sure it's in the correct format.")
    else:
        st.info("Please upload a JSON file to begin.")

if __name__ == "__main__":
    main()