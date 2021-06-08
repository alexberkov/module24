#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

typedef unsigned long ul;

bool isEqual (tm date, tm birthday) {
  return (date.tm_mon == birthday.tm_mon && date.tm_mday == birthday.tm_mday);
}

bool isMore (tm date, tm today) {
  return (date.tm_mon > today.tm_mon || (date.tm_mon == today.tm_mon && date.tm_mday > today.tm_mday));
}

bool isLess (tm date, tm birthday) {
  return (date.tm_mon < birthday.tm_mon || (date.tm_mon == birthday.tm_mon && date.tm_mday < birthday.tm_mday));
}

int main() {
  string line, name;
  time_t t = time(nullptr);
  tm date = *localtime(&t);
  tm today = *localtime(&t);
  tm birthday = date;
  birthday.tm_mon = 11;
  birthday.tm_mday = 31;
  vector<string> bornToday;
  vector<pair<string,tm>> closest;
  while (line != "end") {
    cout << "Enter name: ";
    cin >> line;
    if (line == "end") continue;
    cout << "Enter date of birth: ";
    cin >> get_time(&date, "%Y/%m/%d");
    if (isEqual(date, today)) bornToday.push_back(line);
    if (isMore(date, today)) {
      if (isLess(date, birthday) || isEqual(date, birthday)) {
        birthday.tm_mon = date.tm_mon;
        birthday.tm_mday = date.tm_mday;
        name = line;
        closest.emplace_back(name, birthday);
      }
    }
  }
  if (!bornToday.empty()) {
    cout << "Today is the birthday of: " << endl;
    for (auto & i : bornToday) cout << i << endl;
    cout << endl;
  }
  cout << "Closest birthdays: " << endl;
  ul i = closest.size() - 1;
  while (true) {
    cout << closest[i].first << ", " << put_time(&closest[i].second, "%m/%d") << endl;
    if (isEqual(closest[i].second, closest[i - 1].second) && i != 0)  i--;
    else break;
  }
  return 0;
}
