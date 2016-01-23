#!/usr/bin/env python
# coding=utf-8

if __name__== '__main__':
    x = raw_input()
    x = x.split(" ")
    n = int(x[0])
    t = int(x[-1])
    
    
    for i in xrange(n):
        x = ''
        for j in xrange(10):
            x += chr(j + 48)
        print x
    


