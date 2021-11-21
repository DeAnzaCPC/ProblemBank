from sys import stdin 

def action1(n, arr):
    set_num = set()
    for i in arr:
        if 7777 - i in set_num:
            print("Yes")
            return
        else:
            set_num.add(i)
    print("No")

"""
arr = [1 7770 3 4 5 6 7]

i = 1
s.count(7776 [7777 - 1]) == 0
s.insert(1) // set s = {1}

i = 7770
s.count(7 [7777 - 7770]) == 0
s.insert(7770) // set s = {1, 7770}

...

// set = {1, 7770, 3, 4, 5, 6}
s = 7 
s.count(7770 [7777 - 7]) == 1
--> print("Yes")

"""


def action2(arr):
    set_num = set()
    for i in arr:
        if i in set_num:
            print("Contains duplicate")
            return
        set_num.add(i)
    print("Unique")



def action3(n, arr):
    dict_num = dict()
    for i in arr:
        if i in dict_num:
            dict_num[i] = dict_num[i] + 1
        else:
            dict_num[i] = 1
        if dict_num[i] > n / 2:
            print(i)
            return
    print(-1)

    
def action4(n, arr):
    arr.sort()
    if len(arr) % 2 == 0:
        print(arr[n // 2 - 1], arr[n // 2])
    else:
        print(arr[(n - 1) // 2])


def action5(arr):
    arr.sort()
    for i in arr:
        if i < 100:
            continue
        if i > 999:
            break
        print(i, end=" ")
    

n, t = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

if t == 1:
    action1(n, arr)
elif t == 2:
    action2(arr)
elif t == 3:
    action3(n, arr)
elif t == 4:
    action4(n, arr)
else:
    action5(arr)
