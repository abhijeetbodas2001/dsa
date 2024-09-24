# Works but not always in <= n moves
# Gives WA

# This is kinof like the Dutch National Flag problem:
# https://leetcode.com/problems/sort-colors/description/


def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]

    ans = []  # store moves
    zeros = sum(1 for x in arr if x == 0)
    ones = sum(1 for x in arr if x == 1)
    twos = sum(1 for x in arr if x == 2)
    assert zeros + ones + twos == len(arr)
    assert ones > 0

    left = 0  # store leftmost 1
    while arr[left] != 1:
        left += 1
    right = n - 1  # stores rightmost 1
    while arr[right] != 1:
        right -= 1

    for idx in list(range(n)) * 2:
        if arr[idx] == 1:
            continue

        if arr[idx] == 0 and idx >= zeros and left < idx:
            ans.append((idx, left))
            arr[idx], arr[left] = arr[left], arr[idx]
            right = idx
            while arr[left] != 1:
                left += 1

        if arr[idx] == 2 and idx < zeros + ones and right > idx:
            ans.append((idx, right))
            arr[idx], arr[right] = arr[right], arr[idx]
            left = idx
            while arr[right] != 1:
                right -= 1

    print(len(ans))
    for i, j in ans:
        print(f"{i+1} {j+1}")


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
