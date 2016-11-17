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

int month, M, N, L;

int main() {
  while(cin >> L, L) {
    month = 0;
    
    rep(i, 12) {
      cin >> M >> N;
      L -= M - N;
      if(L <= 0 && month == 0) {
        month = i + 1;
      }
    }

    if(month == 0)
      cout << "NA" << endl;
    else
      cout << month << endl;
  }
  
  return 0;
}
