def solve():
    n = int(input())
    nums = [int(num) for num in input().split(" ")]
    assert len(nums) == n

    if n == 1:
        print(0)
        return

    ans = 0
    for i in range(1, n):
        if nums[i] > nums[i - 1]:
            continue

        ans = ans + nums[i - 1] - nums[i]
        nums[i] = nums[i - 1]

    print(ans)


if __name__ == "__main__":
    solve()
