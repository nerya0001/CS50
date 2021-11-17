from cs50 import get_string
import math

letters = 0
words = 0
sentences = 0

text = get_string("Text: ")

textlen = len(text)

for i in range(textlen):
    if str.isalpha(text[i]):
        letters += 1

    if str.isspace(text[i]):
        words += 1

    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentences += 1
words += 1
avg_letters = float(letters)  * 100 // float(words)
avg_sentences = float(sentences)  * 100 // float(words)
grade = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8)

if grade >= 1 and grade < 16:
    print(f"Grade {grade}")
else:
    if grade < 1:
        print("Before Grade 1")
    if grade >= 16:
        print("Grade 16+")



