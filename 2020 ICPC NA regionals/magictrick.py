d = {}
letters = list(input())

possible = True
for letter in letters:
    if letter in d:
        possible = False
        break
    d[letter] = True

print(int(possible))