import sys

def main():
    T = int(raw_input())
    for i in xrange(1, T+1):
        s = raw_input()
        l = s.split()
        r = int(l[0])
        t = int(l[1])
        lo = 1
        hi = 1000000000000000000
        mid = (lo+hi)/2
        while lo < hi:
            if mid*(2*r+2*mid-1) > t: hi = mid
            else: lo = mid+1
            mid = (lo+hi)/2
        print "Case #" + str(i) +":", mid-1

if __name__ == '__main__':
    main()
