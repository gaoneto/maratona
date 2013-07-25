import sys

def main():
    p = ['Sheldon', 'Leonard', 'Penny', 'Rajesh', 'Howard']
    n = int(raw_input())
    i = 5
    cont = 1
    while n > i:
        n -= i
        i *= 2
        cont *= 2
    print p[(n-1)/cont]

if __name__ == '__main__':
    main()
