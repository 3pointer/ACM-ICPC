#!/usr/bin/env python
# coding=utf-8

if __name__=='__main__':

    n = input()

    a = {}
    p = []
    for i in xrange(2, n + 1):
        if i not in a:
            p.append(i)
        for j in xrange(len(p)):
            a[p[j] * i] = 1
            if i % p[j] == 0:
                break


    flag = 0
    if n not in a:
        print 1
        print n
        flag = 1
    if flag == 0:
        d = p
        ans = map(lambda x : n - x, d)
        for i in p:
            if i in ans:
                print 2
                print i, n - i
                flag = 2
                break
    if flag == 0:
        print 3
        d = p
        ans = map(lambda x : n - x, d)
        for k in xrange(len(ans), 0):
            if flag == 2:
                break
            l = 0
            r = k
            while(l <= r):
                tmp = p[r] + p[l]
                if tmp == ans[k]:
                    print p[l],p[r],n-p[l]-p[r]
                    flag = 2
                    break
                elif tmp > ans[k]:
                    r -= 1
                else:
                    l += 1
    
        
        





