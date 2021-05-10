"""
4 6
a t c i s w
"""
from itertools import combinations

vowels=['a','e','i','o','u']
l,c=map(int, input().split())

chars=input().split(' ')
chars.sort()

for passwd in combinations(chars,l):
    count=0
    for i in passwd:
        if i in vowels:
            count +=1
    if count >=1 and count <=l-2:
        print(''.join(passwd))