data=[1,2,3,2,5]

M=8

#시작점과 끝점을 모두  0 가리킴
start=0
end=0

count=0

while start <len(data):
    # if start >= len(data):
    #     break
    if start==end:
        slice_data=[]
        slice_data.append(data[start])
    else:
        slice_data=data[start:end]

    sub_sum=sum(slice_data)

    if sub_sum < M: #합이 주어진  서브합보다 작으면  end++
        if end >= len(data):
            break
        end +=1
    elif sub_sum==M: #같으면 count ++
        print(slice_data)
        count+=1
        start +=1
    elif sub_sum > M: #서브합보다 크면  start++
        start +=1

print(count)

