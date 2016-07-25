#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

const int V[6] = {1, 5, 10, 50, 100, 500};

int main() {
  int C[6] = {3, 2, 1, 3, 0, 2};
  int A = 620;
  
  int ans = 0;

  for (int i = 5; i >= 0; i--) {
    int t = min(A/V[i], C[i]);
    A -= t * V[i];
    ans += t;
  }
  
  cout << ans << endl;
  return 0;
}
