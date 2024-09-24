from collections import Counter


def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    assert len(arr) == n

    counts = Counter(arr)

    # Alice and Bob both will take those colors first which appear
    # only once, since taking them gives 2 points.
    # Once such numbers are exhausted, they will take all other colors
    # one time.
    # Bob will never allow Alice to take ALL the instances of any
    # particular color.
    ones = sum(1 for count in counts.values() if count == 1)
    two_or_more = sum(1 for count in counts.values() if count > 1)

    ans = 2 * ((ones + 1) // 2) + two_or_more
    print(ans)


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
