num_judges, num_graded = map(int, input().split())

grades = []
for i in range(num_graded):
    grades.append(int(input()))

sum_graded = sum(grades)
num_missing = num_judges - num_graded


max_poss = (sum_graded + 3 * num_missing) / num_judges
min_poss = (sum_graded -3 * num_missing) / num_judges

print(min_poss, max_poss)