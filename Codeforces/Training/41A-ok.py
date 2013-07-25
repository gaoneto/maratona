import sys

def reverse(s):
    ret = ''
    for i in range(len(s)):
        ret += s[len(s)-i-1]
    return ret

def verify(s, t):
    if s == reverse(t): return True
    return False

def main():
    s = raw_input()
    t = raw_input()
    if verify(s, t): print "YES"
    else: print "NO"

if __name__ == '__main__':
    main()
