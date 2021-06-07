#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
  time_t t = time(nullptr);
  tm total = *localtime(&t);
  cout << "Enter time: ";
  cin >> get_time(&total, "%M:%S");
  cout << "Start!" << endl << put_time(&total, "%M:%S") << endl;
  time_t p = time(nullptr);
  while (!(total.tm_sec == 0 && total.tm_min == 0)) {
    time_t c = time(nullptr);
    if (c != p) {
      if (total.tm_sec == 0 && total.tm_min != 0) {
        total.tm_sec = 59;
        total.tm_min--;
      } else total.tm_sec--;
      cout << put_time(&total, "%M:%S") << endl;
      p = c;
    }
  }
  cout << "DING! DING! DING!";
  return 0;
}
