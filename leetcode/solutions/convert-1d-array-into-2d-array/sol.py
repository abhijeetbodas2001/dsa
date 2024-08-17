# https://leetcode.com/problems/convert-1d-array-into-2d-array/


class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m * n != len(original):
            return []

        ans = []
        it = iter(original)
        for _ in range(m):
            arr = [next(it) for _ in range(n)]
            ans.append(arr)

        return ans
