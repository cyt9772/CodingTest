"""
4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1
"""
N,M=map(int, input().split())

dx=[-1,0,1,0]
dy=[0,1,0,-1]

d=[[0]*M for _ in range(N)]
x,y,direction=map(int, input().split())

d[x][y]=1
count=1

array=[]
for _ in range(N):
    array.append(list(map(int,input().split())))



def turn_left():
    global direction
    direction -=1
    if direction == -1:
        direction=3

#simulation
while True:
    valid_flag = False
    for i in range(4):
        turn_left()
        nx=x+dx[direction]
        ny=y+dy[direction]

        if d[nx][ny]==1:
            continue
        #valid area
        if nx <0 or nx>=N or ny<0 or ny>=M:
            continue

        #check sea or continent
        if array[nx][ny]==0:
            x=nx
            y=ny
            d[nx][ny]=1
            count +=1
            valid_flag=True
            break
    #backward
    if not valid_flag:
        nx=x-dx[direction]
        ny=y-dy[direction]

        if array[nx][ny]==0:
            x=nx
            y=ny
        else:
            break

print(count)
