from cs50 import get_string
from math import ceil
lettercount = 0
letterbuffer = 0
wordcount = 0
sentencecount = 0
text = get_string("Text: ")
for n in range(len(text)):
    if text[n] == "." or text[n] == "!" or text[n] == "?":
        sentencecount += 1
        wordcount += 1
        lettercount += letterbuffer
        letterbuffer = 0
    elif text[n-1].isalpha() == True and text[n].isalpha() == False:
        wordcount += 1
        lettercount += letterbuffer
        letterbuffer = 0
    elif text[n].isalpha() == True:
        letterbuffer += 1
    elif text[n].isalpha() == False:
        lettercount += letterbuffer
        letterbuffer = 0
    elif text[n-1].isalpha() == True and text[n].isalpha() == False:
        wordcount += 1
L = (lettercount / wordcount) * 100
S = (sentencecount / wordcount) * 100
index = ceil(0.0588 * L - 0.296 * S - 15.8)
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
