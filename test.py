#!/usr/local/bin/python3

import os
import sys
import random as rng

def make_input():
    file = open('input.txt', 'w')
    for i in range(30):
        line = ""
        for j in range(30):
            line += "%d " % rng.randint(1, 100)
        line.strip
        file.write(line + "\n")
    file.close()

def run_test():
    make_input()
    os.system('./a.out < input.txt > output.txt 2> result.txt')
    ret = int(open('result.txt').readline())
    return 100000 - ret

seed = 0
coefficient1 = 3.0
coefficient2 = 1.0
coefficient2 = 1.0
if len(sys.argv) != 1:
    seed = int(sys.argv[1])
    coefficient1 = float(sys.argv[2])
    coefficient2 = float(sys.argv[3])
    coefficient3 = float(sys.argv[4])

os.system("g++ -std=c++11 -O2 A.cpp -D""COEFFICIENT1=%f"" -D""COEFFICIENT2=%f"" -D""COEFFICIENT3=%f""" % (coefficient1, coefficient2, coefficient3))

#print("seed = %d, coefficient1 = %f, coefficient2 = %f" % (seed, coefficient1, coefficient2))

rng.seed(seed)
score = 0
for i in range(10):
    s = run_test()
    score += s

print("%d, %f, %f, %f, %d" % (seed, coefficient1, coefficient2, coefficient3, score))
#print("total: %d" % score)


