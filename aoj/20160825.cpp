#include <iostream>
#include <algorithm>
#include <string>

static const int MAX = 100;

int h, w;
int V[MAX][MAX];

using namespace std;

int main() {
  string c;
  
  cin >> h >> w;
  for(int i=0; i < h; i++) {
    cin >> c;
    for(int j=0; j < w; j++) {
      if(c[j] == 'c')
        V[i][j] = 0;
      else
        V[i][j] = -1;
    }
  }

  for(int i=0; i < h; i++) {
    for(int j=0; j < w-1; j++) {
      if(V[i][j] != -1 && V[i][j+1] != 0) {
        V[i][j+1] = V[i][j] + 1;
      }
    }
  }

  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cout << V[i][j];
      if(j != w-1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}
