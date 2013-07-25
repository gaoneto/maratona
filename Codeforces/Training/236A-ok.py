import sys

def main():
    s = raw_input()
    d = {}
    for c in s:
        if c not in d: d[c] = 1
    if len(d) % 2 == 0: print "CHAT WITH HER!"
    else: print "IGNORE HIM!"

if __name__ == '__main__':
    main()
