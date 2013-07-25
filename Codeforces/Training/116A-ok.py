import sys

def main():
    n = int(raw_input())
    maximo = 0
    total = 0
    for i in range(n):
        s = raw_input()
        l = s.split()
        a = int(l[0])
        b = int(l[1])
        total += (b - a)
        if total > maximo: maximo = total
    print maximo

if __name__ == '__main__':
    main()
