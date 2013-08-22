#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int m[10][7] = { {1,0,0,1,1,1,1},
                 {1,0,1,0,1,1,1},
                 {1,0,1,1,0,1,1},
                 {1,0,1,1,1,0,1},
                 {1,0,1,1,1,1,0},
                 {0,1,0,1,1,1,1},
                 {0,1,1,0,1,1,1},
                 {0,1,1,1,0,1,1},
                 {0,1,1,1,1,0,1},
                 {0,1,1,1,1,1,0} };

int main()
{
    int n;
    char c[11];
    string s;
    while(scanf("%d", &n) != EOF)
    {
        sprintf(c, "%d", n);
        s = "";
        int len = strlen(c);
        for(int i=9;i>len;i--) s += '0'; 
        s += c;
        for(int i=0;i<7;i++)
        {
            if(i == 2) cout << "---------" << endl;
            for(int j=0;j<9;j++)
            {
                cout << m[s[j]-'0'][i]; 
            }
            cout << endl;
        }
        cout << endl;
    }
}
