#!/usr/bin/env python
# encoding: utf-8


n = int(input())
v = list(map(int, input().split()))
uns = dict()
for i in range(n):
    uns[i + 1] = -1
for i in range(n):
    if v[i] != 1 and uns[v[i] - 1] != -1:
        uns[v[i]] = uns[v[i] - 1] + 1
    else:
        uns[v[i]] = 1
print (n - max(uns.values()))
