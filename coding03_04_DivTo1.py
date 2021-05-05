m,k=map(int, input().split())

cnt=0

while True:
    target=(m//k)*k
    cnt += m-target
    if m<k:
        cnt += m
        m=1
    else:
        m = int(target/k)
        cnt +=1

    if m==1:
        break
print(cnt)