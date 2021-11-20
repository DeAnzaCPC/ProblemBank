from sys import stdin

s, c, k = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]
arr.sort()

res = 1
curr = 1
minn = arr[0]

for i in range (1, s):
    if arr[i] - minn > k or curr == c:
        res += 1
        minn = arr[i]
        curr = 1
    else:
        curr += 1

print(res)
