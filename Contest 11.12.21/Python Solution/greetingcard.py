from math import sqrt
from sys import stdin


def distance(a, b): return sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2)


num_pairs = int(stdin.readline().strip())

points = set()
for i in range(num_pairs):
    pair = tuple(map(int, stdin.readline().strip().split()))
    points.add(pair)

offsets = [
    (0, 2018),
    (1118, 1680),
    (1680, 1118),
    (2018, 0),
    (1680, -1118),
    (1118, -1680),
    (0, -2018),
    (-1118, -1680),
    (-1680, -1118),
    (-2018, 0),
    (-1680, 1118),
    (-1118, 1680),
]

num_connections = 0
done = set()
for point in points:
    done.add(point)
    for offset in offsets:
        neighbor = (point[0] + offset[0], point[1] + offset[1])
        if neighbor in done:
            continue
        if neighbor in points:
            num_connections += 1

print(num_connections)
