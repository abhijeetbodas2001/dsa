def solve():
    n, m = [int(x) for x in input().split()]
    words = [input() for _ in range(n)]

    # words.sort(key=lambda x: len(x))
    total_len = 0
    for idx, word in enumerate(words):
        total_len += len(word)
        if total_len == m:
            print(idx + 1)
            return
        if total_len > m:
            print(idx)
            return

    print(len(words))


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
