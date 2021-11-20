from sys import stdin
 
n = int(stdin.readline().strip())
arr = [int(x) for x in input().split()]
res = 1e5 + 5

arr.sort()

for i in range(n):
    if i + 1 < arr[i]:
        print("impossible")
        quit()
    res = min(res, arr[i] / (i + 1))

print('%.8f'%res)
    









