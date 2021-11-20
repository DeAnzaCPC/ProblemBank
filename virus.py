from collections import deque
original = deque(input())
mutated = deque(input())

i = 0
while i < len(original) and i < len(mutated) and original[i] == mutated[i]:
    original.popleft()
    mutated.popleft()
i = 1
while i <= len(original) and i <= len(mutated) and  original[-i] == mutated[-i]:
    original.pop()
    mutated.pop()

print(len(mutated))