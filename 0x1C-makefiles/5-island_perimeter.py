#!/usr/bin/python3
"""Rpresents an island perimeter measuring function."""


def island_perimeter(grid):
    """This returns the perimiter of an island.
    The grid represents:
    water by 0,
    land by 1.
    Args:
        grid (list):
        A list of list of integers representing an island.
    Return:
        perimeter of the island defined.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for k in range(height):
        for m in range(width):
            if grid[k][m] == 1:
                size += 1
                if (m > 0 and grid[k][m - 1] == 1):
                    edges += 1
                if (k > 0 and grid[k - 1][m] == 1):
                    edges += 1
    return size * 4 - edges * 2
