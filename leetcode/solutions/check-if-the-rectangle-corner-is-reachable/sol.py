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
    intersecting_circles = [set()] * num_circles
    for i, j in itertools.product(range(num_circles), range(num_circles)):
        if do_circles_intersect(circles[i], circles[j]):
            intersecting_circles[i].add(j)
            intersecting_circles[j].add(i)



    pass
