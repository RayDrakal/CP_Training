T = int(input())
count = [0]*10
while T > 0:
    count[T%10] += 1
    T = T // 10
print(' '.join(map(str, [i for i in range(10)])))
print(' '.join(map(str, count)))