import re

from typing import List


def braceExpansion(s: str) -> List[str]:
    results: List[str] = []

    def backtrack(prefixes: List[str], remaining: str) -> None:
        """
        Recursive helper that expands the string.

        prefixes : partial expansions built so far
        remaining: the remaining part of the string to process
        """
        nonlocal results

        # Regex captures:
        # 1) leading literal before {   ([^{}]*)
        # 2) choices inside {}          ([^}]*)
        # 3) literal after }            ([^{}]*)
        # 4) remaining tail             (.*)
        match = re.search(r"([^{}]*)\{([^}]*)\}([^{}]*)(.*)", remaining)

        if not match:
            # Base case: no more braces left
            if prefixes:
                # Append remaining to each existing prefix
                results.extend(prefix + remaining for prefix in prefixes)
            else:
                # No prefix: just add the raw remaining string
                results.append(remaining)
            return

        lead, choices_str, mid, tail = match.groups()
        choices = sorted(choices_str.split(","))  # expand into sorted list of choices

        # If no prefixes yet, start from empty string
        base_prefixes = prefixes if prefixes else [""]
        new_prefixes: List[str] = []

        # Build new partial expansions by combining each prefix with each choice
        for prefix in base_prefixes:
            for choice in choices:
                new_prefixes.append(prefix + lead + choice + mid)

        # Recurse on the tail of the string
        backtrack(new_prefixes, tail)

    # Start recursion with empty prefix and full string
    backtrack([], s)

    return results
