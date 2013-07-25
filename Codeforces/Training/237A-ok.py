import sys

def main():
    n = int(raw_input())
    d = {}
    maximo = 1
    for i in range(n):
        s = raw_input()
        if s in d:
            d[s] += 1
            if d[s] > maximo:
                maximo = d[s]
        else: d[s] = 1
    print maximo

if __name__ == '__main__':
    main()
