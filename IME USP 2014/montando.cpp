#include <bits/stdc++.h>
using namespace std;

double dp[1111][1111];

int main() {
    int n1, n2, m1, m2, w1, w2;
    while(scanf("%d%d%d%d%d%d", &n1, &n2, &m1, &m2, &w1, &w2) != EOF) {
        double p1 = 1.0 * w1/(w1+w2);
        double p2 = 1 - p1;
        double sum = 1 - p1*p1*p1;
        for(int i=0;i<=m1;i++) for(int j=0;j<=m2;j++) {
        	double pback=0;
            dp[i][j]=0;
            if(i==0 && j==0) continue;
            for(int mask=0;mask<7;mask++) {
                double prob=1;
                int nd=0, nc=0;
                for(int pos=0;pos<3;pos++) {
                    if(mask & (1<<pos)) {
                        prob *= p1;
                        nd++;
                    }
                    else {
                        prob *= p2;
                        nc++;
                    }
                }
                prob /= sum;
                for(int st1=0;st1<1<<nd;st1++) {
                    double probst1=1;
                    int ii = i;
                    for(int pos1=0;pos1<nd;pos1++) {
                        if(st1 & (1<<pos1)) {
                            probst1 *= 1.0*ii/n1;
                            ii--;
                        }
                        else {
                            probst1 *= 1.0*(n1-ii)/n1;
                        }
                    }
                    for(int st2=0;st2<1<<nc;st2++) {
                        double probst2 = probst1;
                        int jj = j;
                        for(int pos2=0;pos2<nc;pos2++) {
                            if(st2 & (1<<pos2)) {
                                probst2 *= 1.0*jj/n2;
                                jj--;
                            }
                            else {
                                probst2 *= 1.0*(n2-jj)/n2;
                            }
                        }
                        if(ii == i && jj == j) {
							pback += probst2 * prob;
						}
                        else if(ii >= 0 && jj >= 0) {
                            dp[i][j] += probst2 * prob * (1 + dp[ii][jj]);
                        }
                    }
                }
            }
            dp[i][j] = (dp[i][j] + pback) / (1 - pback);
        }
        printf("%.3lf\n", dp[m1][m2]);
    }
    return 0;
}
