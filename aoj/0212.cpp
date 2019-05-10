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
int C[101][101], D[101][101];
int DP[101][16];

// co=割引券, cost=現在の値段
void solve(int st, int co, int cost) {
  if (st == d-1) {
    return;
  }
  // 次の町探し
  rep(i, n) {
    if (i == st || C[st][i] == INFTY) {
      continue;
    }
    int tmp = cost + C[st][i];
    int tmp2 = cost + C[st][i]/2;
    if (DP[i][co] > tmp) {
      DP[i][co] = tmp;
      solve(i, co, tmp);
    }
    if (co < c && DP[i][co+1] > tmp2) {
      DP[i][co+1] = tmp2;
      solve(i, co+1, tmp2);
    }
  }
}


int main() {
  while (cin >> c >> n >> m >> s >> d, c) {
    rep(i, n) {
      rep(j, n) {
        C[i][j] = INFTY;
        D[i][j] = INFTY;
      }
      rep (q, c+1) {
        DP[i][q] = INFTY;
      }
    }
    rep(i, m) {
      int a,b,f;
      cin >> a >> b  >> f;
      C[a-1][b-1] = f;
      C[b-1][a-1] = f;
    }
    solve(s-1, 0, 0);
    int res = INFTY;
    rep(i, c+1) {
      res = min(res, DP[d-1][i]);
    }
    cout << res << endl;
  }
  return 0;
}
