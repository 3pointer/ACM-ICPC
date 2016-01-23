#!/usr/bin/env python
# encoding: utf-8


if __name__=='__main__':

    x = raw_input().split(" ")
    bx = raw_input().split(" ")
    sb = "".join(bx)
    an1 = int(sb, int(x[-1]))
    y = raw_input().split(" ")
    by = raw_input().split(" ")
    sy = "".join(by)
    an2 = int(sy, int(y[-1]))

    if (an1 == an2):
        print "="
    elif an1 < an2:
        print "<"
    else:
        print ">"





