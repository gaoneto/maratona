import sys

def lucky(n):
    for s in n:
        if s != '4' and s != '7': return False
    return True

def count(s):
    first = 0
    last = 0
    for i in range(len(s)/2):
        first += int(s[i])
        last += int(s[len(s)-i-1])
    if first == last: return True
    return False

def main():
    n = int(raw_input())
    s = raw_input()
    if lucky(s) and count(s): print "YES"
    else: print "NO"

if __name__ == '__main__':
    main()
