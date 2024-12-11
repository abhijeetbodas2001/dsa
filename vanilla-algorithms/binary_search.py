# https://cp-algorithms.com/num_methods/binary_search.html


def solve():
    arr = list(map(int, input().split()))
    target = int(input())

    n = len(arr)

    # ASSUMED: arr[-1] = -inf and arr[n] = +inf
    left, right = -1, n

    # INVARIANT: arr[left] <= target < arr[right]
    while right - left > 1:
        mid = (left + right) // 2

        if target < arr[mid]:
            # mid can be the new right according to the constraint
            right = mid
        else:
            # Here, arr[mid] <= target, so mid can be the new "left"
            # according to the constraint
            left = mid

    # If target is present in the array, left would have settled on it
    # In any case, left will settle on the largest number in the array
    # which is not greater than target
    # If target is smaller than the smallest number in the array, left
    # will stay at -1
    if left >= 0 and arr[left] == target:
        print(left)
    else:
        print(left)


if __name__ == "__main__":
    solve()
