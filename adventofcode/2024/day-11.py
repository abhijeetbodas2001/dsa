from collections import deque
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
    ll = list(map(int, arr.split(" ")))
    head = Node(ll[0], 0)
    prev = head
    for idx in range(1, len(ll)):
        curr = Node(ll[idx], 0)
        prev.next = curr
        prev = curr

    print(time.time())
    curr = head
    ans = 0
    while curr:
        while curr.proc < 75:
            curr.proc += 1

            if curr.val == 0:
                curr.val = 1
                continue

            s = str(curr.val)
            n = len(s)
            if n % 2 == 0:
                part1, part2 = int(s[: n // 2]), int(s[n // 2 :])
                curr.val = part1
                tmp = curr.next
                new_node = Node(part2, curr.proc)
                curr.next = new_node
                new_node.next = tmp
                continue

            curr.val *= 2024

        tmp = curr.next
        curr.next = None
        curr = tmp

        ans += 1

    print("Part 2:", ans)
    print(time.time())


if __name__ == "__main__":
    solve()
