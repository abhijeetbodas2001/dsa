class Solution:
    def _generate_splits(self, s: str, start: int, curr_split: list[str]) -> None:
        if start == len(s):
            # Brute force: check at each leaf node
            # More pruning can also be done by maintaining a set while traversing
            # the tree
            if len(set(curr_split)) == len(curr_split):
                assert len("".join(curr_split)) == len(s)
                self.max_split_len = max(self.max_split_len, len(curr_split))

            return

        for idx in range(start + 1, len(s) + 1):
            # take a substring [start, idx)
            substr = s[start:idx]
            assert len(substr) > 0

            curr_split.append(substr)
            self._generate_splits(s, idx, curr_split)
            curr_split.pop()

    def maxUniqueSplit(self, s: str) -> int:
        curr_split = []
        self.max_split_len = 0

        self._generate_splits(s, 0, curr_split)
        return self.max_split_len


answers = [
    Solution().maxUniqueSplit("a"),
    Solution().maxUniqueSplit("ababccc"),
    Solution().maxUniqueSplit("ab"),
    Solution().maxUniqueSplit("aa"),
]

for ans in answers:
    print(ans)
