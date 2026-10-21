def fullJustify(words: list[str], max_width: int) -> list[str]:
    res = []
    line, length = [], 0

    for w in words:
        if length + len(line) + len(w) > max_width:
            # Distribute spaces across slots (or slot 0 if 1 word)
            slots = max(1, len(line) - 1)
            for i in range(max_width - length):
                line[i % slots] += " "

            res.append("".join(line))
            line, length = [], 0  # reset

        line.append(w)
        length += len(w)

    # Last line
    last_line = " ".join(line)
    res.append(last_line + " " * (max_width - len(last_line)))

    return res
