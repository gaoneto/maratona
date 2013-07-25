import sys

def main():
    s = raw_input()
    d = {}
    lista = s.split()
    for i in lista:
        if i in d: d[i] += 1
        else: d[i] = 1
    print 4 - len(d)

if __name__ == '__main__':
    main()
