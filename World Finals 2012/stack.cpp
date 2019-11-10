#include <bits/stdc++.h>

using namespace std;

int t[55], st[55][55];
map <int,int> sizes;

int main() {
    int T = 1;
    int n, h;
    while(scanf("%d", &n) != EOF) {
        memset(t,0,sizeof(t));
        sizes.clear();
        for(int i=0;i<n;i++) {
            scanf("%d", &h);
            for(int j=0;j<h;j++) {
                scanf("%d", &st[i][t[i]]);
                if(i && st[i][t[i]] == st[i][t[i-1]]) continue;
                sizes[st[i][t[i]++]]++;
            }
        }
        int q = n;
        int splits = 0;
        while(q) {
            map<int,int>::iterator it = --sizes.end();
            int mm = (it->first);
            // mm é o proximo a ser colocado.
            it--;
            int nn = (it->first);
            // nn é o depois do mm; 
            vector <int> div;
            int qs = 0;
            // tira o maior do map
            sizes.erase(--sizes.end());
            for(int i=0;i<n;i++) {
                if(t[i] < 0) continue;
                // se tiver um cara com mm e depois nn ele é candidato a divisor
                if(st[i][t[i]] == mm) {
                    if(t[i] == 0) continue;
                    qs++;
                    if(st[i][t[i]-1] == nn) div.push_back(i);
                    t[i]--;
                    if(t[i] < 0) q--;
                }
            }
            // analisar todos os possíveis divisores
            // ninguem é bizu -> corto todos
            if(div.size() == 0) {
                splits += qs;
            }
            // se existe só um -> usa ele e continua testando
            else if(div.size() == 1) {
                int u = div[0];
                if(it->second > 1) {
                    t[u]--;
                    if(t[u] < 0) q--;
                } else {
                    while((it->first) == st[u][t[u]]) {
                        if(it->second > 1) {
                            t[u]--;
                            if(t[u] < 0) q--;
                            break;
                        }
                        t[u]--;
                        sizes.erase(it--);
                    }
                }
                splits += qs;
            }
            // se existem mais de 2 -> escolhe o mais bizu (não precisa continuar testando)
            else {
                int chos = -1;
                // se tem uma pilha de tamanho 2 escolhe ele
                for(int i=1;i<div.size();i++) {
                    int u = div[i];
                    if(t[u] == 0) {
                        chos = u;
                        qs--;
                        splits += qs;
                        t[u]--;
                        if(t[u] < 0) q--;
                        break;
                    }
                }
                if(chos != -1) break;
                // se não existe nenhum de tamanho 2 -> escolhe o que tem menor terceiro
                chos = 0;
                for(int i=1;i<div.size();i++) {
                    int u = div[i];
                    if(st[u][t[u]-1] < st[chos][t[chos]-1]) chos = u;
                }
                splits += qs;
                t[chos]--;
            }
        }
        printf("Case %d: %d\n", T++, 2*splits+n-1);
    }
    return 0;
}
