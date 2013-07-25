import sys
    
def insert(s):    
    d = {}
    for c in s:
        if c in d: d[c] += 1
        else: d[c] = 1
    return d

def main():
    s = raw_input() + raw_input()
    r = raw_input()
    ds = insert(s)
    dr = insert(r)
    if ds == dr: print "YES"
    else: print "NO"

if __name__ == '__main__':
    main()
