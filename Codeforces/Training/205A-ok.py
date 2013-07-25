import sys

def main():
    n = int(raw_input())
    s = raw_input()
    l = s.split()
    li = [ int(s) for s in l ]
    minimo = 10000000000
    ind = None
    i = 1
    for el in li:
        if el < minimo:
            minimo = el
            cont = 1
            ind = i
        elif el == minimo:
            cont += 1
        i += 1
    if cont == 1: print ind
    else: print "Still Rozdil"

if __name__ == '__main__':
    main()
