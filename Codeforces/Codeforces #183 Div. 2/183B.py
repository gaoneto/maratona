import sys
import datetime

def main():
    s = raw_input()
    t = raw_input()
    a = s.split(':')
    b = t.split(':')
    t1 = datetime.date(int(a[0]), int(a[1]), int(a[2]))
    t2 = datetime.date(int(b[0]), int(b[1]), int(b[2]))
    if t1 > t2: print (t1 - t2).days
    else: print (t2 - t1).days


if __name__ == '__main__':
    main()
