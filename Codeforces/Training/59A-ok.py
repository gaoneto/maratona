import sys

def modify(s):
    low = 0
    for c in s:
        if c == str.lower(c): low += 1
    if 2*low >= len(s): return str.lower(s)
    return str.upper(s)

def main():
    s = raw_input()
    print modify(s)

if __name__ == '__main__':
    main()
