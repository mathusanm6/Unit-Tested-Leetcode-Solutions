def reverseWords(s: str) -> str:
    words = []
    i = len(s) - 1

    while i >= 0:
        # Skip trailing/consecutive spaces
        while i >= 0 and s[i] == " ":
            i -= 1
        if i < 0:
            break

        # Find the start of the word
        j = i
        while i >= 0 and s[i] != " ":
            i -= 1

        words.append(s[i + 1 : j + 1])

    return " ".join(words)
