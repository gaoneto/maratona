import sys

def verify(s):
    for i in range(1, len(s)):
        if s[i] == str.lower(s[i]): return False
    return True

def main():
    s = raw_input()
    if verify(s):
        if s[0] == str.upper(s[0]): ret = str.lower(s[0])
        else: ret = str.upper(s[0])
        for i in range(1, len(s)):
            ret += str.lower(s[i])
        print ret
    else: print s

if __name__ == '__main__':
    main()
