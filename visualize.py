import matplotlib.pyplot as plt
import math
import subprocess
from ast import literal_eval as make_tuple

with open('large_data.txt', 'r') as file:
    lines = file.readlines()

file.close()
count = int(lines[0])
coords = []

for i in range(1, count):
    points = lines[i].split(' ')
    coords.append([float(points[0]), float(points[1])])

xs, ys = zip(*coords)

max_x = math.ceil(max(xs)) + 500
max_y = math.ceil(max(ys)) + 500

plt.plot(xs, ys, 'ro')
plt.axis([-500, max_x, -500, max_y])

result = subprocess.run(['./chull'], stdin=open('large_data.txt', 'r'), stdout=subprocess.PIPE).stdout.decode('utf-8')

result = result.split('\n')
hull = result[1].split('  ')
hull = hull[:-1]
new_cords = []
for p in hull:
    x = make_tuple(p)
    new_cords.append([x[0], x[1]])

new_cords.append(new_cords[0])

newxs, newys = zip(*new_cords)

lines = plt.plot(newxs, newys)

plt.setp(lines, color='b')
plt.show()
