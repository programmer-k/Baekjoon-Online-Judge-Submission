#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int n, l, r;
int populations[50][50];
int next_populations[50][50];
bool visited[50][50];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> l >> r;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> populations[i][j];
}

bool BreadthFirstSearch(int row, int col) {
  //cout << "BreadthFirstSearch(" << row << ", " << col << ")" << endl;
  vector<pair<int, int>> border_open_countries;
  queue<pair<int, int>> q;
  visited[row][col] = true;
  q.push({ row, col });
  border_open_countries.push_back({ row, col });

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int curr_row = p.first;
    int curr_col = p.second;
    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };

    for (int i = 0; i < 4; ++i) {
      int next_row = curr_row + move_row[i];
      int next_col = curr_col + move_col[i];

      // Out of range
      if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n)
        continue;
      
      // Already visited
      if (visited[next_row][next_col])
        continue;
      
      // open the border line
      int diff = abs(populations[curr_row][curr_col] - populations[next_row][next_col]);
      //cout << "row: " << row << ", col: " << col << endl;
      //cout << "next_row: " << next_row << ", next_col: " << next_col << endl;
      //cout << "diff: " << diff << endl;
      if (diff >= l && diff <= r) {
        visited[next_row][next_col] = true;
        q.push({ next_row, next_col });
        border_open_countries.push_back({ next_row, next_col });
      }
    }
  }
  
  // Calculate the new population.
  int new_population = 0;
  for (pair<int, int>& p : border_open_countries) {
    int r = p.first;
    int c = p.second;
    new_population += populations[r][c];
  }
  new_population /= border_open_countries.size();

  // Update the next population.
  for (pair<int, int>& p : border_open_countries) {
    int r = p.first;
    int c = p.second;
    next_populations[r][c] = new_population;
  }

  // Whether the population move has happened or not.
  return border_open_countries.size() == 1 ? false : true;
}

void Solve() {
  int days = 0;

  while (true) {
    bool population_move = false;
    memset(visited, false, sizeof(visited));

    /*cout << "[day " << days << "]\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << populations[i][j] << ' ';
      }
      cout << endl;
    }*/

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j] && BreadthFirstSearch(i, j)) {
          population_move = true;
        }
      }
    }
    
    memcpy(populations, next_populations, sizeof(populations));

    if (!population_move)
      break;

    ++days;
  }

  cout << days << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}