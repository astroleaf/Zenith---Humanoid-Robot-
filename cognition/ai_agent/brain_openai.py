import openai

class OpenAIBrain:
    def __init__(self, api_key):
        openai.api_key = api_key

    def query(self, prompt):
        response = openai.ChatCompletion.create(
            model="gpt-4",
            messages=[{"role": "user", "content": prompt}],
            max_tokens=200
        )
        return response['choices'][0]['message']['content']
