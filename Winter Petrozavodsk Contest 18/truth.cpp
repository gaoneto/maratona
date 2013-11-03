#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n, dp[555][555][2];  
string s;

string build(int i, int f, int v) {
    if(i==f) return s.substr(i, 1);
    if(s[i] == '!' && dp[i+1][f][1-v]) return "!(" + build(i+1, f, 1-v) + ")";
    for(int m=i;m<=f;m++) {
        if(s[m]=='|') {
            if(v==1) {
                if(dp[i][m-1][1]) {
                    if(dp[m+1][f][0]) return "("+build(i, m-1, 1)+ ")|(" +build(m+1, f, 0)+ ")";
                    if(dp[m+1][f][1]) return "("+build(i, m-1, 1)+ ")|(" +build(m+1, f, 1)+ ")";
                }
                if(dp[m+1][f][1]) {
                    if(dp[i][m-1][0]) return "("+build(i, m-1, 0)+ ")|(" +build(m+1, f, 1)+ ")";
                    if(dp[i][m-1][1]) return "("+build(i, m-1, 1)+ ")|(" +build(m+1, f, 1)+ ")";
                }
            }
            if(v==0) {
                if(dp[i][m-1][0] && dp[m+1][f][0]) return "("+build(i, m-1, 0)+ ")|(" +build(m+1, f, 0)+ ")";
            }
        }
        if(s[m]=='&') {
            if(v==0) {
                if(dp[i][m-1][0]) {
                    if(dp[m+1][f][0]) return "("+build(i, m-1, 0)+ ")&(" +build(m+1, f, 0)+ ")";
                    if(dp[m+1][f][1]) return "("+build(i, m-1, 0)+ ")&(" +build(m+1, f, 1)+ ")";
                }
                if(dp[m+1][f][0]) {
                    if(dp[i][m-1][0]) return "("+build(i, m-1, 0)+ ")&(" +build(m+1, f, 0)+ ")";
                    if(dp[i][m-1][1]) return "("+build(i, m-1, 1)+ ")&(" +build(m+1, f, 0)+ ")";
                }
            }
            if(v==1) {
                if(dp[i][m-1][1] && dp[m+1][f][1]) return "("+build(i, m-1, 1)+ ")&(" +build(m+1, f, 1)+ ")";
            }
        }
    }
}

int main() {
    ifstream in("truth.in");
    ofstream out("truth.out");
    while(in>>s && !in.eof()) {
        memset(dp, 0, sizeof(dp));
        n = s.size();
        for(int i=0;i<n;i++) {
            if(s[i]=='0') dp[i][i][0]=1;
            if(s[i]=='1') dp[i][i][1]=1;
        }
        for(int tam=2;tam<=n;tam++) for(int i=0;i<n;i++) {
            int f = i+tam-1;
            if(f>=n) break;
            if(s[i]=='!') {
                if(dp[i+1][f][0]) dp[i][f][1]=1;
                if(dp[i+1][f][1]) dp[i][f][0]=1;
            }
            for(int m=i;m<=f;m++) {
                if(s[m]=='|') {
                    if(dp[i][m-1][1] || dp[m+1][f][1]) dp[i][f][1]=1;
                    if(dp[i][m-1][0] && dp[m+1][f][0]) dp[i][f][0]=1;
                }
                if(s[m]=='&') {
                    if(dp[i][m-1][0] || dp[m+1][f][0]) dp[i][f][0]=1;
                    if(dp[i][m-1][1] && dp[m+1][f][1]) dp[i][f][1]=1;
                }
            }
        }
        if(!dp[0][n-1][1]) out << "Impossible" << endl;
        else out << build(0, n-1, 1) << endl;
    }
    return 0;
}
