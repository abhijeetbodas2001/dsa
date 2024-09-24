def solve():
    test_values, numbers = [], []
    with open("./input.txt", "r") as f:
        for line in f.read().splitlines():
            components = line.split(": ")
            test_values.append(int(components[0]))
            numbers.append(list(map(int, components[1].split())))

    def recurse(target: int, nums: list[int], idx: int, curr_val: int) -> bool:
        if idx == len(nums):
            return curr_val == target

        if curr_val > target:
            return False

        return (
            recurse(target, nums, idx + 1, curr_val * nums[idx])
            or recurse(target, nums, idx + 1, curr_val + nums[idx])
            # Third condition only for part 2 of the problem, for part 1,
            # keep only the above two conditions
            or recurse(target, nums, idx + 1, int(str(curr_val) + str(nums[idx])))
        )

    total = 0
    for test_value, nums in zip(test_values, numbers):
        assert nums
        if recurse(test_value, nums, 1, nums[0]):
            total += test_value

    print(f"{total=}")


if __name__ == "__main__":
    solve()
