#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

typedef pair< int, int > pii;
const int MAX = 1024;
const int INF = 0x3f3f3f3f;


vector< pii > G[MAX];
int d[MAX];

void dijkstra(int start) {
    int u, v, i, c, w;

    priority_queue< pii, vector< pii >, greater< pii > > Q;
    memset(d, 0x3f, sizeof d);
    Q.push(pii(0, start));
    d[start] = 0;
   while(!Q.empty()) {
        u = Q.top().second; // node
        c = Q.top().first; // node cost
        Q.pop(); // remove the top item.
        if(d[u] < c) continue;
        for(i = 0; i < G[u].size(); i++) {
            v = G[u][i].first; // node
            w = G[u][i].second; // edge weight

            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(pii(d[v], v));
            }
        }
    }
}

int main() {
    int n, e, i, u, v, w, start;
    int apsp[MAX][MAX];
    while(scanf("%d %d", &n, &e) == 2) {

        for(i = 1; i <= n; i++) G[i].clear();

        for(i = 0; i < e; i++) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(pii(v, w));
            G[v].push_back(pii(u, w)); // only if bi-directional
        }

        char 
        for(int i=1;i<=n;i++)
        {
          dijkstra(i);   
          for(int j=1;j<=n;j++)
          {
            apsp[i][j]=d[j];
          }
          memset(d, 0x3f, sizeof d);
        }

        for(int i=1;i<=n;i++)
        {
            cout<<i<<"->";
            for(int j=1;j<=n;j++)
            {
                cout<<apsp[i][j]<<" ";
            }
            cout<<endl;
        }   
    }
    return 0;
}