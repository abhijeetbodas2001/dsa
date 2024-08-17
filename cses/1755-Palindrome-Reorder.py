from collections import Counter


def solve():
    counts = Counter(input())

    odd_chars = [char for char, count in counts.items() if count % 2 == 1]
    if len(odd_chars) > 1:
        print("NO SOLUTION")
        return

    if len(odd_chars) == 0:
        # Pseudo character to make logic ahead simpler
        counts[""] = 1
        odd_chars.append("")

    fronts = []
    for char, count in counts.items():
        fronts.append(char * (count // 2))

    print(
        "".join(
            [
                *fronts,
                odd_chars[0],
                *(fronts[::-1]),    # Characters in front, reversed
            ]
        )
    )


if __name__ == "__main__":
    solve()
