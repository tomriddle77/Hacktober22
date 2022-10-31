# -*- coding: utf-8 -*-


import random

s = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()?"

passlen = 8

p = "".join(random.sample(s,passlen))

print(p)
