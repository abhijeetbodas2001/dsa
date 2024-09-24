from collections import Counter


def solve():
    n, k = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    assert len(arr) == n

    rem_count = Counter([x % k for x in arr])
    ans = "no"

    def print_elem(rem: int):
        for idx, num in enumerate(arr):
            if num % k == rem:
                print(idx + 1)
                break

    for rem in range(k):
        if rem not in rem_count:
            continue

        if rem_count[rem] == 1:
            print("yes")
            print_elem(rem)
            return

    print("no")


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
