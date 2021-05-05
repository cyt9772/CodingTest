# <1> 당장 좋은 것만 선택하는 그리디
# money = int(input('input money: '))
money=1260
coin_cnt=[]
coin_types=[500,100,50,10]

remain_money=money
for coin in coin_types:
    coin_num=remain_money//coin
    coin_cnt.append(coin_num)
    remain_money=remain_money-coin*coin_num

print(coin_cnt)

# <2> 큰 수의 법칙
n,m,k = map(int, input().split())
data = list(map(int, input().split()))

data.sort(reverse=True)
first=data[0]
second=data[1]

sum=0

while True:
    for i in range(k):
        if not m:
            break
        sum += first
        m -=1
    if not m:
        break
    sum +=second
    m -=1

print(sum)

