#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int T;
    char s[100], t[100];
    double x, y, z, x0, y0, z0;
    scanf("%d", &T);
    while(T--) {
        getchar();
        scanf("%[^\n]", s);
        getchar();
        scanf("%lf %lf %lf", &x0, &y0, &z0);
        getchar();
        scanf("%[^\n]", t);
        getchar();
        scanf("%lf %lf %lf", &x, &y, &z);
        printf("%s to %s: ", s, t);
        printf("%.2lf\n", sqrt((x0-x)*(x0-x) + (y0-y)*(y0-y) + (z0-z)*(z0-z)));
    }
    return 0;
}
