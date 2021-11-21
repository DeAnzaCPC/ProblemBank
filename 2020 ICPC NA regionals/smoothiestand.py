import sys
def max_smoothies(supply, recipe):
    min_ratio = sys.maxsize
    for i in range(len(supply)):
        if recipe[i] != 0:
            min_ratio = min(supply[i] // recipe[i], min_ratio)
    return min_ratio 

num_ingredients, num_recipes = map(int, input().split())
supply = list(map(int, input().split()))

recipes = []
for i in range(num_recipes):
    recipes.append(list(map(int, input().split())))

max_sale = 0
for recipe in recipes:
    num_smoothies = max_smoothies(supply, recipe)
    sale = num_smoothies * recipe[-1]
    if sale > max_sale:
        max_sale = sale
print(max_sale)

