import sys

def main():
    s = raw_input()
    l = s.split()
    n = int(l[0])
    a = int(l[1])
    b = int(l[2])
    print n-max(a+1, n-b)+1

if __name__ == '__main__':
    main()
