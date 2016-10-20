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

using namespace std;

typedef long long ll;
typedef long double ld;

int X, Y, c[16][16], mem[20][20];

int solve(int x, int y, int tate) {
  if(x < 0 || x >= X) return 0;
  if(y >= Y) {
    if(tate == 1)
      return 1;
    else
      return 0;
  }
  if(c[y][x] == 1) return 0;
  if(tate == 1 && c[y][x] == 2) {
    return solve(x, y+2, 1);
  }
  if(c[y][x] == 2) return 0;
  if(mem[y][x] != -1) return mem[y][x];
  int tmp = solve(x-1, y+1, 2) + solve(x+1, y+1, 3) + solve(x, y+1, 1);
  mem[y][x] = tmp;
  return tmp;
}
  

int main() {
  while(cin >> X >> Y, X) {
    int res = 0;
    
    rep(i, Y) {
      rep(j, X) {
        cin >> c[i][j];
        mem[i][j] = -1;
      }
    }
    
    rep(i, X) {
      res += solve(i, 0, 1);
    }
    
    cout << res << endl;
  }
  return 0;
}
