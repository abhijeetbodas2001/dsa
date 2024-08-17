# INCOMPLETE!!

import itertools
import math


def do_circles_intersect(
    circle1: tuple[int, int, int], circle2: tuple[int, int, int]
) -> bool:
    return (
        math.sqrt((circle1[0] - circle2[0]) + (circle1[1] - circle2[1]))
        <= circle1[2] + circle2[2]
    )


def solve(x: int, y: int, circles: list[tuple[int, int, int]]) -> bool:
    # circle is defined by a (centre_x, center_y, radius) tuple

    num_circles = len(circles)

    # every circle is a parent of itself
    parent = list(range(num_circles))

    parent.append(num_circles)      # U
    parent.append(num_circles+1)    # R
    parent.append(num_circles+2)    # D
    parent.append(num_circles+3)    # L

    def find_parent(a: int):
        if parent[a] == a:
            return a
        return find_parent(parent[a])


    def union_sets(a: int, b: int):
        a = find_parent(a)
        b = find_parent(b)
        if a != b:
            parent[a] = b

    for c1, c2 in itertools.product(range(num_circles), range(num_circles)):
        if not do_circles_intersect(circles[c1], circles[c2]):
            continue

        union_sets(c1, c2)

    for c in range(num_circles):
        if circle_intersects_top_edge(circles[c]):
            union_sets(num_circles, c)
