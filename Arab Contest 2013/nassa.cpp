#include <bits/stdc++.h>
using namespace std;

char s[111111];
char c[]={'U', 'R', 'D', 'L'};
int x, y;

void move(char t) {
    if(t=='U') y++;
    else if(t=='R') x++;
    else if(t=='D') y--;
    else x--;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int xmin=1e9, ymin=1e9, xmax=-1e9, ymax=-1e9;
		scanf("%s", s);
        for(int j=0; j<4; j++) {
            x=0, y=0;
            for(int i=0; s[i]; i++) {
                if(s[i]=='?') move(c[j]);
                else move(s[i]);
            }
            xmin=min(xmin, x);
            ymin=min(ymin, y);
            xmax=max(xmax, x);
            ymax=max(ymax, y);
        }
        printf("%d %d %d %d\n", xmin, ymin, xmax, ymax);
    }
    return 0;
}
