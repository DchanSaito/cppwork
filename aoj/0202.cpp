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

bool dp[1000002], sosu[1000002];
int n, x;
int v[30];

void sosuu() {
  sosu[0]=false;
  sosu[1]=false;
  for(int i=2; i*i<=x; i++) {
    if (sosu[i]) {
      for (int j=2*i; j<=x; j+=i) {
        sosu[j] = false;
      }
    }
  }
}
  

int main() {
  while(cin >> n >> x, n) {
    rep(i, n)
      cin >> v[i];
    rep(i, x+1) {
      sosu[i] = true;
      dp[i] = false;
    }
    sosuu();
    rep(i, n) {
      dp[v[i]]=true;
      for(int j=1; j<=x; j++)
        if(dp[j] && j+v[i] <= x)
          dp[j+v[i]] = true;
    }
    while(x>0) {
      if(dp[x] && sosu[x])
        break;
      x--;
    }
    if(x==0)
      cout << "NA" << endl;
    else
      cout << x << endl;
  }

  return 0;
}
