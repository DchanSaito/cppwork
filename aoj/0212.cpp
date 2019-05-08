#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <stack>
#include <list>

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,b,n) for(int i=b;i<n;i++)
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

const float PI = 3.1415926;
static const int INFTY = (1<<30);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int MAX = 100;

using namespace std;

typedef long long ll;
typedef long double ld;

int c, n, m, s, d;
int C[101][101];

  int D[MAX]; // d[v]始点startからvまでの最短コスト
  int P[MAX]; // P[v]頂点vの親を記憶

void dijkstra(int start) {
  int minv;
  int color[MAX];

  for(int i=0; i < n; i++) {
    D[i] = INFTY;
    color[i] = WHITE;
  }

  D[start] = 0;
  P[start] = -1;

  while(1) {
    minv = INFTY;
    int u = -1;
    rep(i, n) {
      if (minv > D[i] && color[i] != BLACK) {
        u = i;
        minv = D[i];
      }
    }

    if( u == -1 ) break;

    color[u] = BLACK;

    rep(v, n) {
      if(color[v] != BLACK && C[u][v] != INFTY) {
        if(D[v] > D[u] + C[u][v]) {
          D[v] = D[u] + C[u][v];
          color[v] = GRAY;
          P[v] = u;
        }
        if(D[v] > D[u] + C[u][v]/2) {
          D[v] = D[u] + C[u][v];
          color[v] = GRAY;
          P[v] = u;
        }
      }
    }
  }
}

int main() {
  while (cin >> c >> n >> m >> s >> d, c) {
    rep(i, n) rep(j, n) {
      C[i][j] = INFTY;
    }
    rep(i, m) {
      int a,b,f;
      cin >> a >> b  >> f;
      C[a-1][b-1] = f;
      C[b-1][a-1] = f;
    }
    
    dijkstra(s-1);
    cout << D[d-1] << endl;
  }
  return 0;
}
