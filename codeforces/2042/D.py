# TODO


def solve():
    n = int(input())
    likes = []
    for idx in range(n):
        likes.append([idx] + [int(x) for x in input().split()])

    starts_sorted = [x[0] for x in sorted(likes, key=lambda y: y[1])]
    starts_sorted_inv = {num: idx for num, idx in enumerate(starts_sorted)}

    ends_sorted = [x[0] for x in sorted(likes, key=lambda y: y[2])]
    ends_sorted_inv = {num: idx for num, idx in enumerate(ends_sorted)}

    likes = [(x[1], x[2]) for x in likes]

    print(f"{starts_sorted=} {starts_sorted_inv=}")
    print(f"{ends_sorted=} {ends_sorted_inv=}")
    for idx in range(n):
        starts_before = starts_sorted[: starts_sorted_inv[idx]]
        ends_after = (
            ends_sorted[ends_sorted_inv[idx] + 1 :]
            if ends_sorted_inv[idx] < n - 1
            else []
        )

        print(f"{idx} {starts_before=} {ends_after=}")


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
