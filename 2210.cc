#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <set>
#include <string>
using namespace std;

struct Data {
  pair<int, int> pos;
  string str;
};

char map[5][5];
set<string> answers;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      cin >> map[i][j];
}

void BreadthFirstSearch(pair<int, int> start) {
  queue<Data> q;
  string initial_str(1, map[start.first][start.second]);
  q.push({ start, initial_str });

  while (!q.empty()) {
    Data data = q.front();
    pair<int, int> p = data.pos;
    string curr_str = data.str;
    int row = p.first;
    int col = p.second;
    q.pop();

    if (curr_str.size() == 7)
      break;
    else if (curr_str.size() == 6)
      answers.insert(curr_str);

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= 5 || next_col >= 5)
        continue;
      
      string next_str = curr_str + map[next_row][next_col];
      q.push({ make_pair(next_row, next_col), next_str });
    }
  }
}

void Solve() {
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      BreadthFirstSearch({ i, j });
  
  cout << answers.size() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}