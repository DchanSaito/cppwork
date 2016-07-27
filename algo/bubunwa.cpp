#include <iostream>

using namespace std;

int a[10] = {1, 2, 4, 7};
int n, k;

bool dfs(int i, int sum) {
  if (i == n) return sum == k;
  if (dfs(i+1, sum)) return true;
  if (dfs(i+1, sum + a[i])) return true;

  return false;
}

int main() {
  n = 4;
  k = 13;
  
  if (dfs(0, 0)) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
