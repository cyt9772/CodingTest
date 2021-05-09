import math

#check the number is prime
def is_prime(n):
    for i in range(2,int(math.sqrt(n))+1):
        if n%i ==0:
            return False
    return True

#check multi-number prime
n=1000
array=[True for i in range(n+1)]
array[0]=False
array[1]=False

for i in range(2,int(math.sqrt(n)+1)):
    if array[i]==True:
        j=2
        while i*j <=n:
            array[i*j]=False
            j +=1


print(is_prime(4))
print(is_prime(7))
for i in range(2,n+1):
    if array[i]:
        print(i, end=' ')
