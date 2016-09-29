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

int main() {
  vector<int> v;
  int n;
  rep(i,10){
    cin >> n;
    v.push_back(n);
  }
  sort(v.begin(), v.end(), greater<int>());
  cout << v[0] << endl;
  cout << v[1] << endl;
  cout << v[2] << endl;
  

  return 0;
}
