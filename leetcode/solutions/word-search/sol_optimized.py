from typing import List


class Solution:
    def _find_starting(self, idx: int, row: int, col: int) -> bool:
        if idx >= len(self.word):
            return True

        if not (0 <= row < len(self.board)) or not (0 <= col < len(self.board[0])):
            return False

        if self.visited[row][col]:
            return False

        if self.board[row][col] != self.word[idx]:
            return False

        self.visited[row][col] = True
        found = False
        neighbors = (
            (row, col + 1),
            (row, col - 1),
            (row - 1, col),
            (row + 1, col),
        )
        for next_row, next_col in neighbors:
            if self._find_starting(idx + 1, next_row, next_col):
                found = True
                break

        self.visited[row][col] = False
        return found

    def exist(self, board: List[List[str]], word: str) -> bool:
        if len(board) == 0 or len(board[0]) == 0:
            return False
        rows, cols = len(board), len(board[0])

        visited = [[False for _ in range(cols)] for _ in range(rows)]
        self.board = board
        self.word = word
        self.visited = visited
        idx = 0

        # Pass index to string, because slicing will create copies
        for row in range(rows):
            for col in range(cols):
                if self._find_starting(idx, row, col):
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
    "abfs",
    "sabf",
]:
    assert Solution().exist(board=board, word=word), word

for word in [
    "bb",
    "absf",
    "afc",
    "absfa",
]:
    assert not Solution().exist(board=board, word=word), word
