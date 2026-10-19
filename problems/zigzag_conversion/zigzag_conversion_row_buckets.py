def convert(s: str, num_rows: int) -> str:
    if num_rows == 1 or num_rows >= len(s):
        return s

    rows: list[list[str]] = [[] for _ in range(num_rows)]
    curr_row = 0
    step = 1  # 1 for moving down, -1 for moving diagonally up

    for char in s:
        rows[curr_row].append(char)

        # Reverse direction at the top or bottom boundary
        if curr_row == 0:
            step = 1
        elif curr_row == num_rows - 1:
            step = -1

        curr_row += step

    return "".join("".join(row) for row in rows)
