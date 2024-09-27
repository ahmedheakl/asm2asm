import streamlit as st
import json
import difflib
from pygments import highlight
from pygments.lexers import DiffLexer
from pygments.formatters import HtmlFormatter
import random


def load_json(file):
    with open(file, "r") as f:
        return json.load(f)


def display_diff(gt, pred):
    d = difflib.unified_diff(
        gt.splitlines(),
        pred.splitlines(),
        fromfile="Ground Truth",
        tofile="Predicted",
        lineterm="",
        n=10000,
    )
    diff_with_breaks = "\n".join([line for line in d])

    formatter = HtmlFormatter(style="friendly")
    lexer = DiffLexer()

    highlighted_diff = highlight(diff_with_breaks, lexer, formatter)

    st.markdown(
        """
    <style>
    .gd { background-color: #fdd; }
    </style>
    """,
        unsafe_allow_html=True,
    )
    st.markdown(
        f'<style>{formatter.get_style_defs(".highlight")}</style>',
        unsafe_allow_html=True,
    )
    st.markdown(
        f'<div style="background-color: #f0f0f0; white-space: pre-wrap;">{highlighted_diff}</div>',
        unsafe_allow_html=True,
    )


def sample_with_ed(data, ed_range):
    return random.choice(
        [i for i, ed in enumerate(data["ed"]) if ed in range(ed_range[0], ed_range[1])]
    )


def main():
    st.title("x86 to ARM Assembly Conversion Diff Viewer")

    uploaded_file = st.file_uploader("Choose a JSON file", type="json")

    if uploaded_file is not None:
        data = json.load(uploaded_file)
        samples = []
        required_ed = [[0, 1], [1, 30], [30, 100], [100, 500], [500, 8000]]
        for i, ed_range in enumerate(required_ed):
            samples.append(sample_with_ed(data, ed_range))
        for i in samples:

            st.header(f"Sample {i + 1}")

            st.subheader("Input (x86)")
            st.code(data["input"][i], language="nasm")

            st.subheader(
                f"Diff (Ground Truth vs Predicted) | Edit distance {data['ed'][i]}"
            )
            display_diff(data["gt"][i], data["pred"][i])

            st.markdown("---")


if __name__ == "__main__":
    main()
