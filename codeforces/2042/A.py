def solve():
    n, k = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    assert len(arr) == n

    if sum(arr) <= k:
        # In this case, he takes all chests
        print(k - sum(arr))
        return

    arr.sort(reverse=True)
    total = 0
    for num in arr:
        total += num
        if total < k:
            continue

        if total == k:
            print(0)
            return

        if total > k:
            # We overshot
            # Add to the previous number, instead of taking
            # the current number
            prev_total = total - num
            print(k - prev_total)
            return

    raise AssertionError()


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
