def solve():
    n, m, k = [int(x) for x in input().split()]
    arr = [int(c) for c in input()]
    assert len(arr) == n

    # Start from the left, do greedy
    idx = 0
    curr_zeros = 0
    ans = 0
    while idx < n:
        if arr[idx] == 1:
            idx += 1
            curr_zeros = 0
            continue

        curr_zeros += 1
        if curr_zeros == m:
            # only when things get bad, use the hammer
            ans += 1
            curr_zeros = 0
            for _ in range(k):
                arr[idx] = 1
                idx += 1
                if idx == n:
                    break
        else:
            idx += 1

    print(ans)


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
