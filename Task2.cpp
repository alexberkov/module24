#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

int main() {
  string line, name;
  time_t t = time(nullptr);
  tm date = *localtime(&t);
  tm today = *localtime(&t);
  tm birthday = date;
  birthday.tm_mon = 11;
  birthday.tm_mday = 31;
  vector<string> bornToday;
  while (line != "end") {
    cout << "Enter name: ";
    cin >> line;
    if (line == "end") continue;
    cout << "Enter date of birth: ";
    cin >> get_time(&date, "%Y/%m/%d");
    if (date.tm_mon == today.tm_mon && date.tm_mday == today.tm_mday) bornToday.push_back(line);
    if (date.tm_mon > today.tm_mon || (date.tm_mon == today.tm_mon && date.tm_mday > today.tm_mday)) {
      if (date.tm_mon < birthday.tm_mon || (date.tm_mon == birthday.tm_mon && date.tm_mday < birthday.tm_mday)) {
        birthday.tm_mon = date.tm_mon;
        birthday.tm_mday = date.tm_mday;
        name = line;
      }
    }
  }
  if (!bornToday.empty()) {
    cout << "Today is the birthday of: ";
    for (auto & i : bornToday) cout << i << " ";
  }
  cout << endl << "Closest birthday: " << name << ", " << put_time(&birthday, "%m/%d");
  return 0;
}
