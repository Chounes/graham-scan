"""
gen_point_data.py - (c) Tyler Burdsall 2018

Given a number as an argument, this script will generate random
point data to test the convex hull C program
"""
import random
import sys

if len(sys.argv) != 2:
    print("Requires count")
    exit(-1)

COUNT = int(sys.argv[1])
MIN = 0
MAX = 10000
with open('large_data.txt', 'w') as f:
    f.write(str(COUNT) + '\n')
    for i in range(COUNT):
        x = random.uniform(MIN, MAX + 1)
        y = random.uniform(MIN, MAX + 1)
        f.write("{0} {1}\n".format(str(x), str(y)))
f.close()
