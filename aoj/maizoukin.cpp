#include <iostream>
#include <algorithm>

using namespace std;

static const int INFTY = (1<<30);

int V[10][10],mem[10][10][51];
int f,H,W,m,res;

// p=0 はなし、p=1は左、p=2は右
void solve(int x, int y, int o, int p, int cost) {
  if (o <= 0) return;
  // 酸素とコストの計算
  if (V[y][x] >= 0) {
    o += V[y][x];
    if (o > m)
      o = m;
  } else {
    cost -= V[y][x];
  }
  // 最大費用を超えたら終了
  if (cost > f) return;
  // メモ化
  if(mem[x][y][o] < cost) return;
  mem[x][y][o] = cost;
  if (y == H-1) {
    res = min(res,cost);
    return;
  }
  solve(x, y+1, o-1, 0, cost);
  if(x-1 >= 0 && p != 2) solve(x-1, y, o-1, 1, cost);
  if(x+1 < W && p != 1) solve(x+1, y, o-1, 2, cost);
}

int main() {
  int o;
  while(cin >> W >> H, W) {
    cin >> f >> m >> o;
    for(int i=0; i<H; i++)
      for(int j=0; j<W; j++)
        cin >> V[i][j];
    for(int i=0; i<10; i++)
      for(int j=0; j<10; j++)
        for(int k=0; k<=m; k++)
          mem[i][j][k]=INFTY;
    res = INFTY;
    for(int i=0; i<W; i++)
      solve(i, 0, o-1, 0, 0);
    if(res == INFTY)
      cout << "NA" << endl;
    else
      cout << res << endl;
  }
    
  return 0;
}
