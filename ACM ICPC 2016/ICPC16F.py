for x in xrange(int(raw_input())):
    n , m , d , D  = map(int , raw_input().split())
    if n * d <= m and m <= n*D:
        left = {i:dict() for i in xrange(n)}
        right = {j:dict() for j in xrange(n)}
        edges = []
        cnt = 0
        for k in xrange(n):
            for i in xrange(n):
                #i -> i + k
                left[i][(i+k)%n] = 1
                #print  i , (i+k)%n
                cnt += 1
                if cnt == m:break
            if cnt == m:break
        for i in left:
            for j in left[i]:
                print i+1 , j+1
    else:
        print -1
