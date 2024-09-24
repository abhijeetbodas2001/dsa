class Solution:
    def _generate_partitions(
        self,
        s,
        curr_part: list[str],
        curr_substr: str,
        all_parts: list[list[str]],
        start: int,
    ) -> None:
        if start == len(s):
            all_parts.append(curr_part.copy())
            return

        for idx in range(start, len(s)):
            curr_substr = curr_substr + s[idx]

            # doing this check everytime is extremely slow. can we optimize?
            # reversed returns an iterator
            if curr_substr == "".join(reversed(curr_substr)):
                curr_part.append(curr_substr)
                self._generate_partitions(s, curr_part, "", all_parts, idx + 1)
                curr_part.pop()

    def partition(self, s: str) -> list[list[str]]:
        curr_part = []
        all_parts = []
        curr_substr = ""

        self._generate_partitions(s, curr_part, curr_substr, all_parts, 0)

        return all_parts


answers = [
    Solution().partition("ab"),
    Solution().partition("aba"),
    Solution().partition("abba"),
    Solution().partition("ababa"),
]

for ans in answers:
    print(ans)
