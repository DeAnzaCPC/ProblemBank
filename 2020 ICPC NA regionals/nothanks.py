num_cards = int(input())
cards = list(map(int, input().split()))
cards.sort()
score = cards[0]
for i in range(1, num_cards):
    if cards[i] - 1 != cards[i - 1]:
        score += cards[i]
print(score)