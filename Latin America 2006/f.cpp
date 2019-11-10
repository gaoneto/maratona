#include <iostream>

using namespace std;

int min(int a, int b)
{
    if(a>=b)
        return b;
    else return a;
}

int main()
{
    int n, i, x, mpar, mimpar, jpar, jimpar, num;
    do
    {
        mpar=mimpar=jpar=jimpar=0;
        cin >> n;
        if(n!=0)
        {
            for(i=0; i<n; i++)
            {
                cin >> x;
                x%2==0 ? mpar++ : mimpar++;
            }
            for(i=0; i<n; i++)
            {
                cin >> x;
                x%2==0 ? jpar++ : jimpar++;
            }
            num=n-min(mpar, jimpar)-min(mimpar, jpar);
            cout << num << endl;
        }
    }while(n!=0);
    return 0;    
}
