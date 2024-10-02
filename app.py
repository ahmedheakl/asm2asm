import streamlit as st
import json
import difflib
from pygments import highlight
from pygments.lexers import DiffLexer, CLexer, NasmLexer
from pygments.formatters import HtmlFormatter
import random

def load_json(file):
    with open(file, "r") as f:
        return json.load(f)

def display_highlighted_code(code, lexer, title):
    formatter = HtmlFormatter(style="monokai")
    highlighted_code = highlight(code, lexer, formatter)
    
    # Remove any trailing newlines and extra div tags from the highlighted code
    highlighted_code = highlighted_code.rstrip().rstrip('</div>').rstrip()
    
    st.markdown(
        f'<style>{formatter.get_style_defs(".highlight")}</style>',
        unsafe_allow_html=True,
    )
    st.markdown(
        f"""
        <div style="background-color: #272822; padding: 10px; border-radius: 5px;">
            <h4 style="color: #f8f8f2; margin-bottom: 10px;">{title}</h4>
            <div style="background-color: #272822; white-space: pre-wrap; font-family: 'Courier New', monospace;">
                {highlighted_code}
            </div>
        </div>
        """,
        unsafe_allow_html=True,
    )

def display_diff(gt, pred):
    d = difflib.unified_diff(
        gt.splitlines(),
        pred.splitlines(),
        fromfile="Ground Truth",
        tofile="Predicted",
        lineterm="",
        n=10000,
    )
    diff_with_breaks = "\n".join(d)
    formatter = HtmlFormatter(style="monokai")
    lexer = DiffLexer()
    highlighted_diff = highlight(diff_with_breaks, lexer, formatter)
    
    # Remove any trailing newlines and extra div tags from the highlighted diff
    highlighted_diff = highlighted_diff.rstrip().rstrip('</div>').rstrip()
    
    st.markdown(
        """
        <style>
        .diff-header { color: #75715e; font-weight: bold; }
        .diff-add { background-color: #46830c; }
        .diff-remove { background-color: #8b0807; }
        </style>
        """,
        unsafe_allow_html=True,
    )
    st.markdown(
        f'<style>{formatter.get_style_defs(".highlight")}</style>',
        unsafe_allow_html=True,
    )
    st.markdown(
        f"""
        <div style="background-color: #272822; padding: 10px; border-radius: 5px;">
            <h4 style="color: #f8f8f2; margin-bottom: 10px;">Diff (Ground Truth vs Predicted)</h4>
            <div style="background-color: #272822; white-space: pre-wrap; font-family: 'Courier New', monospace;">
                {highlighted_diff}
            </div>
        </div>
        """,
        unsafe_allow_html=True,
    )

def sample_with_ed(data, ed_range):
    valid_indices = [i for i, ed in enumerate(data["ed"]) if ed_range[0] <= ed < ed_range[1]]
    return random.choice(valid_indices) if valid_indices else None

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
        data = json.load(uploaded_file)
        samples = []
        required_ed = [[0, 1], [1, 30], [30, 100], [100, 500], [500, 8000]]
        for ed_range in required_ed:
            sample = sample_with_ed(data, ed_range)
            if sample is not None:
                samples.append(sample)
        
        for i, sample_index in enumerate(samples):
            with st.expander(f"Sample {i + 1} (Edit Distance: {data['ed'][sample_index]})", expanded=True):
                st.markdown(f"<h3 style='text-align: center; color: #1E90FF;'>Sample {i + 1}</h3>", unsafe_allow_html=True)
                
                col1, col2 = st.columns(2)
                
                with col1:
                    display_highlighted_code(data["files"][sample_index], CLexer(), "C Code")
                    display_highlighted_code(data["input"][sample_index], NasmLexer(), "Input (x86)")
                
                with col2:
                    display_diff(data["gt"][sample_index], data["pred"][sample_index])
            
            st.markdown("<hr style='margin: 2em 0;'>", unsafe_allow_html=True)

if __name__ == "__main__":
    main()