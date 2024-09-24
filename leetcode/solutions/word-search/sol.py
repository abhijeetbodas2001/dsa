from typing import List


class Solution:
    def _find_starting(
        self,
        board: List[List[int]],
        visited: List[List[bool]],
        word: str,
        idx: int,
        row: int,
        col: int,
    ) -> bool:
        if idx >= len(word):
            return True

        if not (0 <= row < len(board)) or not (0 <= col < len(board[0])):
            return False

        if visited[row][col]:
            return False

        if board[row][col] != word[idx]:
            return False

        visited[row][col] = True
        found = False
        neighbors = (
            (row, col + 1),
            (row, col - 1),
            (row - 1, col),
            (row + 1, col),
        )
        for next_row, next_col in neighbors:
            if self._find_starting(board, visited, word, idx + 1, next_row, next_col):
                found = True
                break

        visited[row][col] = False
        return found

    def exist(self, board: List[List[str]], word: str) -> bool:
        if len(board) == 0 or len(board[0]) == 0:
            return False

        rows, cols = len(board), len(board[0])
        visited = [[False for _ in range(cols)] for _ in range(rows)]
        idx = 0

        # Pass index to string, because slicing will create copies
        for row in range(rows):
            for col in range(cols):
                if self._find_starting(board, visited, word, idx, row, col):
                    return True

        return False


board = [
    ["a", "b", "c"],
    ["s", "f", "e"],
]

for word in [
    "ab",
    "bc",
    "abc",
    "sf",
    "f",
    "e",
    "sfe",
    "fe",
    "as",
]:
    assert Solution().exist(board=board, word=word), word
