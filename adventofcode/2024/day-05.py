import itertools


def solve():
    edges = set()
    orders = []

    with open("./input.txt", "r") as f:
        # files are iterators
        for line in f:
            line = line[:-1]  # last chars will be \n, remove them
            if not line:
                break

            edges.add(tuple(int(x) for x in line.split("|")))

        # the iterator "f" remembers its position
        for line in f:
            line = line[:-1]
            orders.append(tuple(int(x) for x in line.split(",")))

    part_one_total = 0
    bad_orders = []
    for order in orders:
        n = len(order)
        is_valid = True
        for first in range(n):
            for second in range(first + 1, n):
                if (order[second], order[first]) in edges:
                    is_valid = False

        if is_valid:
            part_one_total += order[n // 2]
        else:
            bad_orders.append(order)
    print(f"Part 1: {part_one_total}")

    part_two_total = 0
    for order in bad_orders:
        n = len(order)

        # NOTE: both ends of the edges should be in the order, not just one
        applicable_edges = [
            edge for edge in edges if edge[0] in order and edge[1] in order
        ]

        # create adjacency list
        all_nodes = set(itertools.chain.from_iterable(applicable_edges))

        # defaultdict of set is not OK, because we need to keep
        # track of nodes with no incoming applicable_edges also
        outgoing = {node: set() for node in all_nodes}
        indegree = {node: 0 for node in all_nodes}

        for frm, to in applicable_edges:
            outgoing[frm].add(to)
            indegree[to] += 1

        # create levels of the toposort
        all_levels = []
        level = [node for node in all_nodes if indegree[node] == 0]
        while level:
            all_levels.append(level)
            next_level = []
            for node in level:
                assert indegree[node] == 0
                for child in outgoing[node]:
                    indegree[child] -= 1

                    if indegree[child] == 0:
                        next_level.append(child)

            level = next_level

        # Given the edges involved, there should be no cycles,
        # and the ordering should be unique
        assert all(len(level) == 1 for level in all_levels)
        corrected_order = list(itertools.chain.from_iterable(all_levels))
        assert len(corrected_order) % 2 == 1
        part_two_total += corrected_order[n // 2]

    print(f"Part 2: {part_two_total}")


if __name__ == "__main__":
    solve()

