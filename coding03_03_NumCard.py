m,n = map(int, input().split())

for i in range(m):
    row=list(map(int, input().split()))
    if i == 0:
        min_value=min(row)
    if min_value < min(row):
        min_value = min(row)
print(min_value)