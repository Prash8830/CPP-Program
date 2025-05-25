import gradio as gr
from textblob import TextBlob

def sentiment_analysis(text: str) -> dict:
    """
    Analyze the sentiment of the given text, after performing spell correction.

    Args:
        text (str): The text to analyze

    Returns:
        dict: A dictionary containing original_text, corrected_text, polarity, subjectivity, and assessment
    """
    original_blob = TextBlob(text)
    corrected_text = str(original_blob.correct())
    sentiment = original_blob.sentiment
    
    return {
        "original_text": text,
        "corrected_text": corrected_text,
        "polarity": round(sentiment.polarity, 2),  # -1 (negative) to 1 (positive)
        "subjectivity": round(sentiment.subjectivity, 2),  # 0 (objective) to 1 (subjective)
        "assessment": "positive" if sentiment.polarity > 0 else "negative" if sentiment.polarity < 0 else "neutral"
    }

def sentiment_analysis_gradio_wrapper(text: str) -> tuple[str, dict]:
    """
    Wrapper for sentiment_analysis to format output for Gradio interface.
    """
    results = sentiment_analysis(text) # This is your existing function
    corrected_text = results.pop("corrected_text") # Extract corrected text
    # The rest of the results go to the JSON output
    return corrected_text, results

# Create the Gradio interface
demo = gr.Interface(
    fn=sentiment_analysis_gradio_wrapper,
    inputs=gr.Textbox(placeholder="Enter text to analyze..."),
    outputs=[
        gr.Textbox(label="Corrected Text"),
        gr.JSON(label="Sentiment Analysis")
    ],
    title="Text Sentiment Analysis",
    description="Analyze the sentiment of text using TextBlob"
)

# Launch the interface and MCP server
if __name__ == "__main__":
    demo.launch(mcp_server=True)
