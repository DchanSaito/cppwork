#include <iostream>
#include <algorithm>
#include <string>

const int V[10][7] = {
  {0, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 0, 1, 1, 1, 1},
  {1, 1, 0, 0, 1, 1, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 1, 0, 1},
  {0, 1, 0, 0, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 0, 1, 1, 1, 1}
};

using namespace std;

typedef long long ll;
typedef long double ld;

string change(int a, int b) {
  string res = "";
  for(int i=0; i<7; i++){
    if(V[a][i] == V[b][i]) {
      res += "0";
    } else {
      res += "1";
    }
  }

  return res;
}
  
int main() {
  int n, f=-1, t;

  while(true) {
    cin >> n;
    if(n == -1) break;
    for(int i=0; i<n; i++) {
      cin >> t;
      if(f == -1) {
        for(int j=0; j<7; j++) {
          cout << V[t][j];
        }
        cout << endl;
        f = t;
      } else {
        cout << change(f, t) << endl;
        f = t;
      }
    }
    f = -1;
  }

  return 0;
}
