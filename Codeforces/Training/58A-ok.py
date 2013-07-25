import sys
import re
    
def hello(s):
    match = re.search(r'h\w*?e\w*?l\w*?l\w*?o', s)
    if match: return True
    return False

def main():
    s = raw_input()
    if hello(s): print "YES"
    else: print "NO"

if __name__ == '__main__':
    main()
