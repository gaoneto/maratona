import sys

def main():
    s = raw_input()
    l = s.split()
    n = int(l[0])
    m = int(l[1])
    resp = 0
    for a in range(1001):
        for b in range(1001):
            if a*a+b == n and a+b*b == m: resp += 1
    print resp

if __name__ == '__main__':
    main()
