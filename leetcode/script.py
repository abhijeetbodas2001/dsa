import json
import os

problem_tags_wanted = [
    # Part 1
    # "Arrays",
    # "Binary Search",
    # "Bit Manipulation",
    # "Sorting",
    #
    # Part 2
    # "Fast & Slow Pointers",
    # "In-place reversal of a linked list",
    # "Two Pointers",
    #
    # Part 3
    # "BFS",
    # "DFS",
    # "Graph",
    # "Topological Sort",
    #
    # Part 4
    # "Heap",
    # "Greedy",
    # "Dynamic Programming",
]

# Source for data file is https://github.com/seanprashad/leetcode-patterns/blob/main/src/data/questions.json
with open("/home/apb/code/dsa/leetcode/data.json") as f:
    data = json.load(f)["data"]

import glob
for d in data:
    # Create directories for each problem
    os.mkdir(f'/home/apb/code/dsa/leetcode/solutions/{d["slug"]}')
