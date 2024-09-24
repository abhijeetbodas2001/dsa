import re


def solve():
    with open("./input.txt", "r") as f:
        lines = f.readlines()

    muls = []
    for line in lines:
        muls.extend(re.findall("mul\([0-9]*\,[0-9]*\)", line))

    total = 0
    for mul in muls:
        match = re.search("([0-9]*)\,([0-9]*)", mul)
        a, b = int(match.group(1)), int(match.group(2))
        total += a * b

    print("Part 1:", total)

    with open("./input.txt", "r") as f:
        lines = f.read().splitlines()

    # ASSUME: "do" and "don't" will apply across lines
    line = "".join(lines)

    total = 0
    # remove all things in the string which lie between "don't()" and "do()"
    # NOTE: this match has to be non-greedy, hence .*? and not only .*
    line = re.sub(r"don't\(\).*?do\(\)", "", line)

    # now, remove everything after the last don't, if there is
    line = re.sub(r"don't\(\).*$", "", line)

    muls = re.findall(r"mul\([0-9]*\,[0-9]*\)", line)

    for mul in muls:
        match = re.search(r"([0-9]*)\,([0-9]*)", mul)
        a, b = int(match.group(1)), int(match.group(2))
        total += a * b

    print("Part 2:", total)


if __name__ == "__main__":
    solve()
