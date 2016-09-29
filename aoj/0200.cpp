#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <stack>

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,b,n) for(int i=b;i<n;i++)
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

const float PI = 3.1415926;
static const int INFTY = (1<<27);

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m, p, q, r;
int C[101][101], V[101][101];

void floyd() {
  rep(k,m) rep(i,m) rep(j,m) {
    C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
    V[i][j] = min(V[i][j], V[i][k] + V[k][j]);
  }
}

int main() {
  while(cin >> n >> m, n) {
    rep(i, m) rep(j, m) {
      C[i][j] = ((i==j)?0:INFTY);
      V[i][j] = ((i==j)?0:INFTY);
    }
    
    rep(i, n) {
      int tmp_i, tmp_j, ti, co;
      cin >> tmp_i >> tmp_j >> co >> ti;
      // 無向グラフ
      C[tmp_i-1][tmp_j-1] = co;
      C[tmp_j-1][tmp_i-1] = co;
      V[tmp_i-1][tmp_j-1] = ti;
      V[tmp_j-1][tmp_i-1] = ti;      
    }

    floyd();

    int k;
    cin >> k;

    rep(i,k) {
      cin >> p >> q >> r;
      if(r == 0)
        cout << C[p-1][q-1] << endl;
      else
        cout << V[p-1][q-1] << endl;
    }
  }
  
  return 0;
}
