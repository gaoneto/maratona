import sys

def main():
    a = str.lower(raw_input())
    b = str.lower(raw_input())
    if a < b: print -1
    elif a > b: print 1
    else : print 0

if __name__ == '__main__':
    main()
