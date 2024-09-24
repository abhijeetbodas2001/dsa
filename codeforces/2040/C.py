def solve():
    n, k = [int(x) for x in input().split()]

    if k > 2 ** (n - 1):
        print(-1)
        return

    if n == 1:
        print(1)
        return

    k = k - 1
    # format(k, "b") is MUCH slower than this for some reason. Gives TLE
    bits = []
    while k:
        bits.append(str(k % 2))
        k //= 2

    while len(bits) < n - 1:
        bits.append("0")
    bits.reverse()

    left, right = [], []
    for num, bit in enumerate(bits):
        if bit == "0":
            left.append(num + 1)
        else:
            right.append(num + 1)

    print(*left, n, *reversed(right))


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
