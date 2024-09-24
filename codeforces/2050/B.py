def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    if sum(arr) % n != 0:
        print("no")
        return

    target = sum(arr) // n

    odds = arr[0:n:2]
    evens = arr[1:n:2]
    if (sum(evens) % len(evens) == 0 == sum(odds) % len(odds)) and (
        sum(evens) // len(evens) == sum(odds) // len(odds)
    ):
        print("yes")
        return

    print("no")


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
