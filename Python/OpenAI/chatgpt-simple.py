import openai

openai.api_key = "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"
completion = openai.ChatCompletion.create(model="gpt-3.5-turbo", messages=[{"role": "user", "content": "Give me 3 ideas for apps I could build with openai apis "}])
print(completion.choices[0].message.content)