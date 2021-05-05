# <2> 큰 수의 법칙
n,m,k = map(int, input().split())
data = list(map(int, input().split()))

# Option1 ______________________________________
# data.sort(reverse=True)
# first=data[0]
# second=data[1]
#
# sum=0
#
# while True:
#     for i in range(k):
#         if not m:
#             break
#         sum += first
#         m -=1
#     if not m:
#         break
#     sum +=second
#     m -=1
#
# print(sum)

#Option 2 ________________________________________
data.sort(reverse=True)
first = data[0]
second = data[1]

cycle = m//(k+1)
cycle_sum = first*k + second
residue_sum=(m%(k+1))*first

total_sum=cycle_sum*cycle + residue_sum
print(total_sum)
