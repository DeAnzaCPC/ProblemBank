n = int(input())

seeds = list(map(int, input().split()))
seeds.sort(reverse=True)

time_to_party = 0
PLANT_TIME = 1


for day, seed in enumerate(seeds):
    time_to_growth = seed + PLANT_TIME + day
    if time_to_party < time_to_growth:
        time_to_party = time_to_growth

time_to_party += 1

print(time_to_party)