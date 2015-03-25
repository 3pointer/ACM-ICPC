#!/usr/bin/env python
# coding=utf-8
import random

N = 20

def f():
    print N 
    a = [chr(random.randint(97, 122)) for _ in range(N)]
    print ''.join(a)
    b = [chr(random.randint(97, 122)) for _ in range(N)]
    print ''.join(b)
'''
    for i in range(200000):
        print "%s"%chr(random.randint(97, 122))
    for i in range(200000):
        print chr(random.randint(97, 122)),
'''

f()
