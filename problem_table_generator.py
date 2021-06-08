# Script to create tables to paste into README's.
# A `problem` object in the `data.json` file looks like so:
# {
#     "id": 0,
#     "name": "Contains Duplicate",
#     "url": "https://leetcode.com/problems/contains-duplicate/",
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

difficulty_map = dict(
    Easy=1,
    Medium=2,
    Hard=3
)

def difficulty_comparator_key(p):
    return difficulty_map[p["difficulty"]]

with open('data.json') as f:
    data = list(json.load(f))

# CLear contents of file
open('dump.txt', 'w').close()

part = "part-01"
print("## Problems\n", file=open("dump.txt", "a"))
print("|Serial number|Difficulty|Problem|Solution(s)|", file=open("dump.txt", "a"))
print("|-|-|-|-|", file=open("dump.txt", "a"))

data.sort(key=difficulty_comparator_key)
serial_number = 1

problem_tags_wanted = [
    "Arrays",
    "Binary Search",
    "Bit Manipulation",
    "Sorting",
]

for problem in data:
    if  len(set(problem_tags_wanted) & set(problem["pattern"])) > 0:
        problem_name = problem["name"]
        problem_url = problem["url"]
        difficulty = problem["difficulty"]
        hyphenated_problem_name = str(problem_name).lower().replace(" ", "-")
        display_number = str(serial_number).zfill(2)
        solution_url = f"/{part}/{difficulty_map[difficulty]}_{display_number}_{hyphenated_problem_name}.cpp"

        print(f"|{display_number}|{difficulty}|[{problem_name}]({problem_url})|[Solution]({solution_url})|", file=open("dump.txt", "a"))
        serial_number+=1
