n = int(input())
arr = [1]*1000005
for i in range(2, 1000000):
    if(arr[i]==1):
        for j in range(i*i, 1000000, i):
            arr[j]=0


for i in range(n):
    a, b = [int(x) for x in input().split()]
    if(a<=1):
        a=2
    output = 0
    for i in range(2, b):
        if(arr[i]==1):
            cntb = 0
            cnta = 0
            index_b = b
            index_a = a-1
            while(index_a>0):
                index_a = index_a//i
                cnta+=1
            while(index_b>0):
                index_b = index_b //i
                cntb+=1
            cntb-=1
            cnta -=1
            output += cntb - cnta
            if(a<=i  and i<=b):
                output-=1
    print(output)

