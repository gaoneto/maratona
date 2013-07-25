import sys

def is_vowel(c):
    if c[0] == 'a' or c[0] == 'o' or c[0] == 'y' or c[0] == 'e' or c[0] == 'u' or c[0] == 'i': return True
    return False

def main():
    s = raw_input()
    ret = ''
    for c in s:
        if not is_vowel(str.lower(c)):
            ret += '.'
            ret += str.lower(c)
    print ret

if __name__ == '__main__':
    main()
