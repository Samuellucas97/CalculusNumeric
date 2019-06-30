import numpy, random, math

v = [0]
while numpy.std(v) <= 3:
    v = [int(random.gauss(0, 3)) for i in range(8)]
    for i in range(8):
        if v[i] == 0:
            v[i] = 1

for i in range(8):
    print( -math.pi+i*math.pi/4, v[i])
