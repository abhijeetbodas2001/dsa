def solve():
    n = int(input())
    nums = [int(num) for num in input().split(" ")]
    assert len(nums) == n - 1

    print(int(n * (n + 1) / 2) - sum(nums))


if __name__ == "__main__":
    solve()
