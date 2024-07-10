def solve():
    n = int(input())

    while n != 1:
        print(n, end=" ")
        if n % 2 == 1:
            n = 3 * n + 1
        else:
            n = int(n / 2)

    print(n)


if __name__ == "__main__":
    solve()
  
