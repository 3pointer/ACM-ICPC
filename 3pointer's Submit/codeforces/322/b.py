#!/usr/bin/env python
# coding=utf-8


if __name__ == '__main__':
    a = []
    n = input()
    x = raw_input().split(" ")

    x.reverse()
    ma = x[0]
    a.append(0)
    x[0] = int(x[0])
    for i in range(1, len(x)):
        ma = ma > x[i - 1] and ma or x[i - 1]
        x[i] = int(x[i])
        ma = int(ma)
        a.append(ma + 1 - x[i])
    a.reverse()
    for i in a:
        print i,

