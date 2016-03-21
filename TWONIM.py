t=int(raw_input())
for i in xrange(t):
    n=int(raw_input())
    a=map(int,raw_input().split())
    b=[0]*n
    s=0
    for j in a:
       s=s^j
    if s==0:
        flag=0
    else:
        flag=1
    count=1
    while flag==1:
        count+=1
        flag=0
        for j in xrange(len(a)): 
            if b[j]==0:
                if s^a[j]!=0:
                    b[j]=1
                    
                    s=s^a[j]
                    flag=1
                    break
    if count%2==0:
        print "Second"
    else:
        print "First"
        
                    
