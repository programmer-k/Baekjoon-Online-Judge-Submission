#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <utility>
using namespace std;

int t;
int a, b;
int visited[10000];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void GetInput2() {
  cin >> a >> b;
}

string BreadthFirstSearch(int start) {
  queue<pair<int, string>> q;
  memset(visited, -1, sizeof(visited));
  q.push({ start, "" });
  visited[start] = 0;

  while (!q.empty()) {
    pair<int, string> p = q.front();
    int curr = p.first;
    string curr_str = p.second;
    q.pop();

    if (curr == b)
      return curr_str;

    for (int i = 0; i < 4; ++i) {
      int next;
      if (i == 0)
        next = curr * 2 % 10000;
      else if (i == 1)
        next = curr == 0 ? 9999 : curr - 1;
      else if (i == 2)
        next = (curr % 1000) * 10 + (curr / 1000);
      else
        next = (curr % 10) * 1000 + (curr / 10);
      
      // No need to check out of range
      // Visit check
      if (visited[next] == -1) {
        string next_str = curr_str;
        if (i == 0)
          next_str.push_back('D');
        else if (i == 1)
          next_str.push_back('S');
        else if (i == 2)
          next_str.push_back('L');
        else
          next_str.push_back('R');

        q.push({ next, next_str });
        visited[next] = visited[curr] + 1;
      }
    }
  }

  return "";
}

void Solve() {
  cout << BreadthFirstSearch(a) << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}