t=int(raw_input())

for i in range(t):
    num=0
    b=map(int,raw_input().split())
    
    a=map(int,raw_input().split())
 
    for j in a:
        ans=1
        column=j%b[1]
        if column==0:
            column=b[1]
        row=(j-column)/b[1]+1
       
        ans*=row
        ans*=b[0]-row+1
        ans*=column
        ans*=b[1]-column+1
        num+=ans
    den=b[0]*b[1]*(b[0]+1)*(b[1]+1)/4
 
    fans=num*1.0/den
    print("%.16f"%fans)    
    
