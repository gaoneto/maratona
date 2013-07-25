import sys

def main():
    s = raw_input()
    f = raw_input()
    ret = ''
    for i in range(len(s)):
        ret += str(int(s[i]) ^ int(f[i]))
    print ret

if __name__ == '__main__':
    main()
