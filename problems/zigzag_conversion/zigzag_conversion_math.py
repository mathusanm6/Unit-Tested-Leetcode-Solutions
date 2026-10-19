def convert(s: str, num_rows: int) -> str:
    if num_rows == 1 or num_rows >= len(s):
        return s

    res = []
    cycle_len = 2 * (num_rows - 1)

    for r in range(num_rows):
        for i in range(r, len(s), cycle_len):
            res.append(s[i])  # Vertical step

            # Diagonal step for inner rows
            diag_idx = i + cycle_len - 2 * r
            if 0 < r < num_rows - 1 and diag_idx < len(s):
                res.append(s[diag_idx])

    return "".join(res)
