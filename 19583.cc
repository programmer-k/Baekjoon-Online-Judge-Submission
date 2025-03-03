#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <vector>
using namespace std;

pair<int, int> s, e, q;
vector<pair<pair<int, int>, string>> chat_records;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  string input1, input2, input3;
  cin >> input1 >> input2 >> input3;

  s.first = atoi(input1.substr(0, 2).c_str());
  s.second = atoi(input1.substr(3).c_str());

  e.first = atoi(input2.substr(0, 2).c_str());
  e.second = atoi(input2.substr(3).c_str());

  q.first = atoi(input3.substr(0, 2).c_str());
  q.second = atoi(input3.substr(3).c_str());

  string time, nickname;
  while (cin >> time >> nickname) {
    pair<int, int> p;
    p.first = atoi(time.substr(0, 2).c_str());
    p.second = atoi(time.substr(3).c_str());
    chat_records.push_back({ p, nickname });
  }
}

void Solve() {
  int answer = 0;
  set<string> nickname_set;
  for (int i = 0; i < ssize(chat_records); ++i) {
    pair<int, int> time = chat_records[i].first;
    string nickname = chat_records[i].second;

    if (time <= s) {
      nickname_set.insert(nickname);
    }
    else if (e <= time && time <= q && nickname_set.count(nickname)) {
      nickname_set.erase(nickname);
      ++answer;
    }
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}