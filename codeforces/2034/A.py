import math


def solve():
    a, b = [int(x) for x in input().split()]
    # m must be >= max(a,b)
    print(math.lcm(a, b))


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
