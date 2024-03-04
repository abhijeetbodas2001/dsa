# Script to create tables to paste into README's.
# A `problem` object in the `data.json` file looks like so:
# {
#     "id": 0,
#     "title": "Contains Duplicate",
#     "slug": "contains-duplicate",
#     "pattern": [
#         "Arrays"
#     ],
#     "difficulty": "Easy",
#     "premium": false,
#     "companies": [
#         "Apple",
#         "Microsoft",
#         "Adobe"
#     ]
# }

import json

# Editable data
problem_tags_wanted = [
    # Part 1
    #"Arrays",
    #"Binary Search",
    #"Bit Manipulation",
    #"Sorting",

    # Part 2
    #"Fast & Slow Pointers",
    #"In-place reversal of a linked list",
    #"Two Pointers",

    # Part 3
    #"BFS",
    #"DFS",
    #"Graph",
    #"Topological Sort",

    # Part 4
    "Heap",
    "Greedy",
    "Dynamic Programming",
]
part = "part-01"


# Fixed stuff
difficulty_map = dict(
    Easy=1,
    Medium=2,
    Hard=3
)
def difficulty_comparator_key(p):
    return difficulty_map[p["difficulty"]]

# Load data
with open('data.json') as f:
    data = list(json.load(f))
data.sort(key=difficulty_comparator_key)

# Clear contents of file
open('dump.txt', 'w').close()

# Print contents
print("## Contents\n", file=open("dump.txt", "a"))
print("This part contains problems on these topics:", file=open("dump.txt", "a"))
for tag in problem_tags_wanted:
    print(f"- {tag}", file=open("dump.txt", "a"))

print("\n\n## Notes\n", file=open("dump.txt", "a"))

# Print table header
print("\n\n## Problems\n", file=open("dump.txt", "a"))
print("|Serial number|Difficulty|Problem|Solution(s)|", file=open("dump.txt", "a"))
print("|-|-|-|-|", file=open("dump.txt", "a"))

# Print table rows
serial_number = 1
for problem in data:
    if  len(set(problem_tags_wanted) & set(problem["pattern"])) > 0:
        problem_name = problem["title"]
        problem_url = "https://leetcode.com/problems/" + problem["slug"]
        difficulty = problem["difficulty"]
        hyphenated_problem_name = str(problem_name).lower().replace(" ", "-")
        display_number = str(serial_number).zfill(2)

        print(f"|{display_number}|{difficulty}|[{problem_name}]({problem_url})|", file=open("dump.txt", "a"))
        serial_number+=1
