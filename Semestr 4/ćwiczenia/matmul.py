import random
import time

def makeMatrix(n):
    return [[random.random() for _ in range(n)] for _ in range(n)]

def makeZeroMatrix(n):
    return [[0.0 for _ in range(n)] for _ in range(n)]

def mulMatrix(n, a, b, c):
    for i in range(n):
        for j in range(n):
            for k in range(n):
                c[i][j] += a[i][k] * b[k][j]
                
if(__name__ == '__main__'):
    for n in range(1,101):
        avgtime = 0.0
        for _ in range(10):
            a = makeMatrix(n)
            b = makeMatrix(n)
            c = makeZeroMatrix(n)
            start = time.time()
            mulMatrix(n, a, b, c)
            end = time.time()
            avgtime += 0.1 * (end - start)
        print(n, avgtime)    
        
            