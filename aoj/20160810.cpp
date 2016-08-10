#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int V[8] = {0, 1, 2, 3, 5, 7, 8, 9};

ll hatisin(ll a) {
  ll res = 0;
  ll i = 1;
  int t = 0;
  while(a > 0) {
    t = a % 8;
    res += t * i;
    a /= 8;
    i *= 10;
  }
  return res;
}

ll fukkatu(ll b) {
  ll res = 0;
  ll i = 1;
  int t = 0;
  while(b > 0) {
    t = b % 10;
    res += V[t] * i;
    i *= 10;
    b /= 10;
  }
  return res;
}

int main() {
  ll res;
  while(true) {
    cin >> res;
    if (res == 0) break;
    cout << fukkatu(hatisin(res)) << endl;
  }
  
  return 0;
}
