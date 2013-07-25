import sys

def verify(s):
    if not s: return False
    while s:
        if s%10 != 4 and s%10 != 7: return False
        s /= 10
    return True

def count(s):
    ret = 0
    while s:
        if s%10 == 4 or s%10 == 7: ret += 1
        s /= 10
    return ret

def main():
    s = int(raw_input())
    if verify(count(s)): print "YES"
    else: print "NO"

if __name__ == '__main__':
    main()
