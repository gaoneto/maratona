import sys

def verify(s):
    for c in s:
        if c == 'H' or c == 'Q' or c == '9': return True
    return False

def main():
    s = raw_input()
    if verify(s): print "YES"
    else: print "NO"

if __name__ == '__main__':
    main()
