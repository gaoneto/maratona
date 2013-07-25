import sys

def verify(l, k):
    ret = 0
    for s in l:
        count = 0
        while s:
            if s%10 == 4 or s%10 == 7: count += 1
            s /= 10
        if count <= k: ret += 1
    return ret

def main():
    s = raw_input()
    l = s.split()
    n = int(l[0])
    k = int(l[1])
    s = raw_input()
    l = s.split()
    li = [ int(s) for s in l ]
    print verify(li, k)

if __name__ == '__main__':
    main()
