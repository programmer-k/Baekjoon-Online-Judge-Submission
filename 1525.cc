#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <utility>
using namespace std;

struct Data {
  int curr_map[3][3];
  int row;
  int col;

  Data(int given_map[][3], int row, int col) {
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        curr_map[i][j] = given_map[i][j];
    
    this->row = row;
    this->col = col;
  }
};

int input_map[3][3];
int answer_map[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
int min_move = numeric_limits<int>::max();
int move_row[4] = { 1, 0, -1, 0 };
int move_col[4] = { 0, 1, 0, -1 };
map<string, int> visited;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> input_map[i][j];
}

bool IsAnswer() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (input_map[i][j] != answer_map[i][j]) {
        return false;
      }
    }
  }

  return true;
}

string MapToString(int given_map[][3]) {
  string str;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      str += to_string(given_map[i][j]);
    }
  }
  return str;
}

void BreadthFirstSearch(int start_row, int start_col) {
  queue<Data> q;
  q.push({ input_map, start_row, start_col });
  visited[MapToString(input_map)] = 0;

  while (!q.empty()) {
    Data data = q.front();
    int row = data.row;
    int col = data.col;
    string curr_str = MapToString(data.curr_map);
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row < 0 || next_col < 0 || next_row >= 3 || next_col >= 3)
        continue;
      
      Data new_data(data.curr_map, next_row, next_col);
      swap(new_data.curr_map[row][col], new_data.curr_map[next_row][next_col]);
      string new_str = MapToString(new_data.curr_map);

      if (visited.count(new_str) > 0) {
        continue;
      }

      q.push(new_data);
      visited[new_str] = visited[curr_str] + 1;
    }
  }
}

void Solve() {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      if (input_map[i][j] == 0)
        BreadthFirstSearch( i, j );

  if (visited.count("123456780") > 0)
    cout << visited["123456780"] << '\n';
  else
    cout << "-1\n";
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}