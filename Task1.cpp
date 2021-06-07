#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  string command, name;
  bool current = false;
  time_t start, end;
  vector<pair<string, time_t>> tasks;
  while (command != "exit") {
    cout << "Enter command: ";
    cin >> command;
    if (command == "exit") cout << "Goodbye!";
    else if (command == "begin") {
      if (current) {
        end = time(nullptr);
        tasks.emplace_back(name, end - start);
      }
      cout << "Enter task name: ";
      cin >> name;
      start = time(nullptr);
      current = true;
    } else if (command == "end") {
      if (current) {
        end = time(nullptr);
        tasks.emplace_back(name, end - start);
        current = false;
      }
    } else if (command == "status") {
      for (auto & task : tasks) cout << task.first << " "
      << put_time(gmtime(&task.second), "%H:%M:%S") << endl;
      if (current) cout << name << endl;
    } else cout << "Incorrect input!" << endl;
  }
  return 0;
}
