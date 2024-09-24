from typing import List


class Solution:
    def _generate_words(self, board: List[List[str]], visited: List[List[bool]], row: int, col: int, curr: str) -> None:
        if curr in self.word_set:
            self.possible_words.add(curr)

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.word_set = set(words)
        self.possible_words = set()

        return list(self.possible_words)

