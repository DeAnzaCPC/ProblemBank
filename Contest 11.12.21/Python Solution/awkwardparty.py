num_guests = min_awk = int(input())
seating = list(map(int, input().split()))

d = {}

for i, lang in enumerate(seating):
    if lang not in d:
        d[lang] = [i]
    else:
        d[lang].append(i)
        awk_lvl = d[lang][-1] - d[lang][-2]
        if awk_lvl < min_awk:
            min_awk = awk_lvl


print(min_awk)
