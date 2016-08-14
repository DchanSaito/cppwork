#include <iostream>
#include <string>

using namespace std;

int main() {
  string name = "慣れないこと";
  int menkyo = 893274893;
  time_t now = time(nullptr);
  struct tm* localNow = localtime(&now);
  struct tm tomorrowStruct = { 0, 0, 0, localNow->tm_mday + 1, localNow->tm_mon, localNow->tm_year };
  time_t tomorrow = mktime(&tomorrowStruct);

  cout << name << " " << menkyo << " " << tomorrow << endl;

  return 0;
}
