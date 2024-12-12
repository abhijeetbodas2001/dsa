from collections import deque, Counter
import time
from copy import copy


class Node:
    def __init__(self, val, proc):
        self.val = val
        self.next = None
        self.proc = proc


def solve():
    with open("./input.txt", "r") as f:
        arr = f.read().splitlines()[0]
    ll = list(map(int, arr.split(" ")))
    for blink in range(0):
        print(blink)
        idx = 0
        while idx < len(ll):
            if ll[idx] == 0:
                ll[idx] = 1
                idx += 1
                continue

            s = str(ll[idx])
            n = len(s)
            if n % 2 == 0:
                part1, part2 = int(s[: n // 2]), int(s[n // 2 :])
                ll[idx] = part1
                ll.insert(idx + 1, part2)
                idx += 2
                continue

            ll[idx] *= 2024
            idx += 1

    print("Part 1", len(ll))

    # Part 2
    # ll = list(map(int, arr.split(" ")))
    # head = Node(ll[0], 0)
    # prev = head
    # for idx in range(1, len(ll)):
    #     curr = Node(ll[idx], 0)
    #     prev.next = curr
    #     prev = curr
    #
    # print(time.time())
    # curr = head
    # ans = 0
    # while curr:
    #     while curr.proc < 75:
    #         curr.proc += 1
    #
    #         if curr.val == 0:
    #             curr.val = 1
    #             continue
    #
    #         s = str(curr.val)
    #         n = len(s)
    #         if n % 2 == 0:
    #             part1, part2 = int(s[: n // 2]), int(s[n // 2 :])
    #             curr.val = part1
    #             tmp = curr.next
    #             new_node = Node(part2, curr.proc)
    #             curr.next = new_node
    #             new_node.next = tmp
    #             continue
    #
    #         curr.val *= 2024
    #
    #     tmp = curr.next
    #     curr.next = None
    #     curr = tmp
    #
    #     ans += 1
    #
    # print("Part 2:", ans)
    # print(time.time())


def part2():
    gives: dict[int, Counter] = {}  # map from value to counter
    ll = [9694820, 93, 54276, 1304, 314, 664481, 0, 4]
    print(ll)

    def cache(num: int) -> dict[int, int]:
        if num in gives:
            return gives[num]

        g = {}
        res = 0
        s = str(num)
        n = len(s)
        if num == 0:
            res = [1]
        elif n % 2 == 0:
            res = [int(s[: n // 2]), int(s[n // 2 :])]
        else:
            res = [num * 2024]

        gives[num] = Counter(res)
        return gives[num]

    curr = Counter(ll)
    for idx in range(200):
        new = {}
        for num, count in curr.items():
            for x, y in cache(num).items():
                new[x] = new.get(x, 0) + count * y
        curr = new

    print(sum(v for v in curr.values()))


if __name__ == "__main__":
    part2()
