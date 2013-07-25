import sys

def lucky(s):
    if not s: return False
    while s:
        if s%10 != 4 and s%10 != 7: return False
        s /= 10
    return True

def verify(n):
    for i in range(n+1):
        if lucky(i) and n%i == 0: return True
    return False

def main():
    n = int(raw_input())
    if verify(n): print "YES"
    else: print "NO"

if __name__ == '__main__':
    main()
