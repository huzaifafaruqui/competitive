for x in xrange(int(raw_input())):
    n = int(raw_input())
    har = map(int , raw_input().split())
    a,b,c,cnt = 0,0,0,0
    for i in har:
        if i == 0:a += 1
        elif i == 1:b += 1
        elif i == -1:c += 1
        else:cnt += 1
    if n == 1:print 'yes'
    elif cnt > 1:
        print 'no'
    elif c > 1 and b == 0:
        print 'no'
    else:
        if c + b == n and b != 0:
            print 'yes'
        elif c + a == n and a != 0:
            print 'yes'
        elif a + b == n:
            print 'yes'
        elif a + b + c == n and c < n:
            print 'yes'
        elif a + b == n-1:
            print 'yes'
        else:
            print 'no'
