#!/usr/local/bin/python3

import os

seed = 10
params = [0.1, 0.3, 0.5, 0.7, 1.0]
for param1 in params:
    for param2 in params:
        os.system("./test.py %d %f %f" % (seed, param1, param2))


