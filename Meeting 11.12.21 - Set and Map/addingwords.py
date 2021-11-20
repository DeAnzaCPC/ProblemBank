
words = {}

def calculate():

    if data[1] not in words:
        return 'unknown'
    sum = words[data[1]]

    for i in range(2, len(data) - 1, 2):
        operator, word = data[i], data[i + 1]

        if word not in words:
            return 'unknown'

        sum += words[word] if operator == "+" else -words[word]


    for word, num in words.items():
        if num == sum:
            return word

    return 'unknown'



output = ''
try:
    while True:
        line = input().strip()
        if line == '':
            break

        data = line.split()

        command = data[0]

        if command == 'def':
            word, num = data[1], data[2]
            words[word] = int(num)

        elif command == 'calc':
            output += ' '.join(data[1:]) + ' ' + calculate() + '\n'

        elif command == 'clear':
            words.clear()



except EOFError:
    pass

print(output[:-1])
