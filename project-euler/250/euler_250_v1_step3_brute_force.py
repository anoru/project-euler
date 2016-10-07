#!/usr/bin/env python

import os
import sys

if sys.version_info > (3,):
    long = int
    xrange = range

MOD = int(os.environ["MOD"])

mods = []

with open('mod_groups.txt') as f:
    for l in f:
        nums = [long(i) for i in l.rstrip('\n').split(' ')]
        count = nums.pop(0)
        for n in nums:
            for i in xrange(0,count):
                mods.append(n)

l = len(mods)
ret = 0

def rec(depth, m, stack):
    if depth == l:
        if m == 0:
            global ret
            print(stack)
            ret += 1
    else:
        rec(depth+1, m, stack)
        rec(depth+1, (m+mods[depth])%MOD, stack + [mods[depth]])
    return

rec(0,0, [])
ret -= 1
print ("Num = %d" % (ret))