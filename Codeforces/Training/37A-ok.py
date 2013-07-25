import sys

def main():
    n =int(raw_input())
    s = raw_input()
    lista = s.split()
    maximo = 1
    d = {}
    for el in lista:
        if el in d:
            d[el] += 1
            if d[el] > maximo: maximo = d[el]
        else: d[el] = 1
    print maximo, len(d)

if __name__ == '__main__':
    main()
