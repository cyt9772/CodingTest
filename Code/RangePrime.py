import math

n,m=map(int, input().split())

array=[True for i in range(1000001)]
array[0]=False
array[1]=False

for i in range(2,int(math.sqrt(m)+1)):
    if array[i]==True:
        j=2
        while i*j<=m:
            array[i*j]=False
            j +=1
for i in range(n,m+1):
    if array[i]:
        print(i)
