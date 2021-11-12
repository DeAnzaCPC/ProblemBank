from sys import stdin

while True:
    n, m = map(int, stdin.readline().strip().split())
    if n == 0 and m == 0:
        break

    jack_cds = set()
    jill_cds = set()

    for i in range(n):
        jack_cds.add(int(stdin.readline().strip()))

    for i in range(m):
        jill_cds.add(int(stdin.readline().strip()))

    print(len(jack_cds.intersection(jill_cds)))
