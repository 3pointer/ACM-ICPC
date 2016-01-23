#!/usr/bin/env python
# encoding: utf-8


def gcd(a, b):
    return b == 0 and a or gcd(b, a % b)


def min(a, b):
    return a < b and a or b

if __name__ == '__main__':
    x = raw_input()
    x = x.split(" ")
    t = int(x[0])
    w = int(x[1])
    b = int(x[2])

    g = gcd(w, b)
    bg = w * b / g

    ans = 0
    ans = t / bg
    ans2 = 0
    n = t % bg
    if (n != 0):
        ans2 = min(n, min(w, b) - 1)
    ans *= (min(w, b))

    print "%s/%s" %((ans+ans2)/gcd(ans+ans2, t),t/gcd(ans+ans2,t))
