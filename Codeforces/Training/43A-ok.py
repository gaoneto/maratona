import sys

def main():
    n = int(raw_input())
    d = {}
    maximo = 0
    winner = ''
    for i in range(n):
        s = raw_input()
        if s in d:
            d[s] += 1
            if d[s] > maximo:
                maximo = d[s]
                winner = s
        else:
            d[s] = 1
            if d[s] > maximo:
                maximo = d[s]
                winner = s
    print winner

if __name__ == '__main__':
    main()
