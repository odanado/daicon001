#!/usr/local/bin/python3

import os

seed = 10

# -3.5, -5.5
for param1 in range(-55, -35, 1):
    #print(param1/100.0)
    os.system("./test.py %d %f %f %f" % (seed, 3, 1, param1/100.0))

