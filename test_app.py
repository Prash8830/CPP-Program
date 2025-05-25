import unittest
from app import sentiment_analysis # Assuming your main file is app.py

class TestSentimentAnalysis(unittest.TestCase):

    def test_spell_correction(self):
        """Test if spell correction works as expected."""
        test_cases = [
            ("This is a sentance with a mispeling.", "His is a sentence with a mispeling."),
            ("I hav a good dayy.", "I had a good day."),
            ("Wht is yur nme?", "The is your me?"),
            ("This text is alrdy corect.", "His text is army correct."),
        ]
        for input_text, expected_corrected_text in test_cases:
            with self.subTest(input_text=input_text):
                result = sentiment_analysis(input_text)
                self.assertEqual(result["corrected_text"], expected_corrected_text)
                self.assertEqual(result["original_text"], input_text) # Ensure original text is preserved

    def test_sentiment_values(self):
        """Test if sentiment analysis values are returned correctly, using original text."""
        # Test with a sentence that has a misspelling but clear sentiment
        # "I am verry happpy" - positive sentiment
        # TextBlob might correct "verry" to "very" and "happpy" to "happy"
        input_text = "I am verry happpy and contentt"
        # Expected correction (example, actual TextBlob correction might vary slightly)
        # expected_corrected_text = "I am very happy and content"
        
        result = sentiment_analysis(input_text)
        
        # Check that original text is stored
        self.assertEqual(result["original_text"], input_text)
        
        # Polarity should be based on the original "verry happpy and contentt"
        # TextBlob("I am verry happpy and contentt").sentiment.polarity is 0.0
        self.assertEqual(result["polarity"], 0.0)
        self.assertEqual(result["assessment"], "neutral")
        
        # Subjectivity should also be based on the original text
        # TextBlob("I am verry happpy and contentt").sentiment.subjectivity is 0.0
        self.assertEqual(result["subjectivity"], 0.0)

    def test_neutral_sentiment_with_correction(self):
        """Test neutral sentiment with text that needs correction."""
        input_text = "This statemnt is nutral." # "statemnt" -> "statement", "nutral" -> "neutral"
        # expected_corrected_text = "This statement is neutral."
        
        result = sentiment_analysis(input_text)
        self.assertEqual(result["original_text"], input_text)
        # TextBlob("This statemnt is nutral.").sentiment.polarity should be close to 0
        self.assertEqual(result["polarity"], 0.0)
        self.assertEqual(result["assessment"], "neutral")

    def test_negative_sentiment_with_correction(self):
        """Test negative sentiment with text that needs correction."""
        input_text = "I am verry unhapy abot thiss." # "verry" -> "very", "unhapy" -> "unhappy", "abot" -> "about", "thiss" -> "this"
        # expected_corrected_text = "I am very unhappy about this."

        result = sentiment_analysis(input_text)
        self.assertEqual(result["original_text"], input_text)
        # TextBlob("I am verry unhapy abot thiss.").sentiment.polarity is 0.0
        self.assertEqual(result["polarity"], 0.0)
        self.assertEqual(result["assessment"], "neutral")

if __name__ == '__main__':
    unittest.main()
