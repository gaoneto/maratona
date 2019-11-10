#include <iostream>
#include <algorithm>

bool compara(int a, int b)
{
     return(a<b);
}

using namespace std;

int main()
{
    int a, d, i, b[11], c[11];
    do
    {
        cin >> a >> d;
        if(a!=0 || d!=0)
        {
             for(i=0; i<a; i++)
                 cin >> b[i];
             for(i=0; i<d; i++)
                 cin >> c[i];
             sort(b, b+a, compara);
             sort(c, c+d, compara);
             if(b[0]<c[1])
                 cout << "Y" << endl;
             else
                 cout << "N" << endl;
        }
    }while(a!=0 || d!=0);
    return 0;    
}
