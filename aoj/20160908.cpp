#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,b,n) for(int i=b;i<n;i++)

const float PI = 3.1415926;
static const int INFTY = (1<<30);

using namespace std;

typedef long long ll;
typedef long double ld;

int n, res, t;

int main() {
  while(cin >> n, n) {
    bool flag = false;
    res = 1;
    rep(i, n) {
      cin >> t;
      if(t >= 2) flag = true;
      if(t >= 1) res++;
    }

    if (flag) cout << res << endl;
    else cout << "NA" << endl;
  }
  
  return 0;
}
