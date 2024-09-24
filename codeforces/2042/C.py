def solve():
    n, k = [int(x) for x in input().split()]

    # Because we care about the difference between points of
    # A and B, make an array of 1's and -1's, so that the
    # difference in points becomes the sum of elements in the
    # array (after multiplying by the value)
    arr = [1 if x == "1" else -1 for x in input()]
    assert len(arr) == n

    # The problem is equivalent to choosing suffix_sum's
    # Example: if there is a partition done between index
    # 3 and 4, then we are effectively adding the suffix_sum
    # starting from index 4 to the total
    suffix_sum = [0] * n
    suffix_sum[n - 1] = arr[n - 1]
    for idx in range(n - 2, -1, -1):
        suffix_sum[idx] = suffix_sum[idx + 1] + arr[idx]

    # There is a partition before the 0th index by default (because
    # there has to be at least one group)
    # However, because the "value"/multiplier of the groups starts
    # from 0 (and not 1), we should not consider the partition which
    # exist before the 0th element in the final total becos the suffix
    # sum for it is multiplied by 0
    # All other suffix_sum's are multiplied by 1
    suffix_sum = suffix_sum[1:]

    suffix_sum.sort(reverse=True)
    suffix_sum = [x for x in suffix_sum if x > 0]
    if sum(suffix_sum) < k:
        print(-1)
        return

    total = 0
    for idx, num in enumerate(suffix_sum):
        total += num
        if total >= k:
            print(idx + 2)
            return


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
