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

os.system('g++ -std=c++11 -O2 A.cpp')
seed = 0
if len(sys.argv) != 1:
    seed = int(sys.argv[1])

rng.seed(seed)
score = 0
for i in range(10):
    s = run_test()
    score += s
    print("%d: %d" % (i, s))

print("total: %d" % score)


