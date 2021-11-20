from math import sqrt

class Sprinkler:
    def __init__(self, x, r, start, end):
        self.x = x
        self.r = r
        self.start = start
        self.end = end

def intersection(x, r):
    # there is no intersection
    if (r**2 - (w/2)**2) < 0:
        return (-1, -1)

    start = -sqrt(r**2 - (w/2)**2) + x
    end =  sqrt(r**2 - (w/2)**2) + x
    if end > l:
        end = l
    if start < 0:
        start = 0
    return (start, end)


while True:
    try:
        n, l, w = map(int, input().split())
    except EOFError:
        break
    
    sprinklers = []


    for i in range(n):
        x, r = map(int, input().split())
        start, end = intersection(x, r)
        if start == -1 and end == -1:
            continue
        sprinkler = Sprinkler(x, r, start, end)
        
        sprinklers.append(sprinkler)

    
    #Sort by start
    sprinklers.sort(key=lambda sprinkler: sprinkler.start)

    covered = 0
    sprinklers_needed = 0
    i = 0

    while covered < l:
        
        best_end=covered
        while i < len(sprinklers):
            if sprinklers[i].start > covered:
                break
            if sprinklers[i].end > best_end:
                best_end = sprinklers[i].end
            i += 1
        if covered == best_end:
            break
        covered = best_end
        sprinklers_needed += 1


        
    print(-1 if covered < l else sprinklers_needed)
        

     
        
        


  


