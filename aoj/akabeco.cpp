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

const int V[6][2] = {{1,2}, {-1,3}, {1,-1}, {4,5}, {5,2}, {2,1}};

int main() {
  string t;
  int now;
  bool flag;
  while(cin >> t, t!="#") {
    flag = true;
    now = 0;
    rep(i, t.size()) {
      int tmp= t[i] - '0';
      now = V[now][tmp];
      if(now < 0) {
        flag = false;
        break;
      }
    }
    if(now == 5 && flag)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
    
  
  return 0;
}
