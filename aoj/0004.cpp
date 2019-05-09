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
#include <iomanip>

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,b,n) for(int i=b;i<n;i++)
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

const float PI = 3.1415926;
static const int INFTY = (1<<30);

using namespace std;

typedef long long ll;
typedef long double ld;

double a,b,c,d,e,f;

int main() {
  while(cin >> a >> b >> c >> d >> e >> f) {
    double x, y;
    x = (c*e - f*b) / (a*e - b*d);
    y = (f*a - c*d) / (e*a - b*d);
    x = x == 0 ? 0 : x;
    y = y == 0 ? 0 : y;
    cout << fixed << setprecision(3) << x << " " << y << endl;
  }
  return 0;
}
