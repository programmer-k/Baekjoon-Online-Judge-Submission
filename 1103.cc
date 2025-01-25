#include <iostream>
#include <utility>
using namespace std;

struct Node {
  int val;
  pair<int, int> nexts[4];  // right, bottom, left, up (clockwise)
};

int n, m;
Node nodes[50][50];
bool visited[50][50];
int dp[50][50];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char val;
      cin >> val;
      nodes[i][j].val = val <= '9' ? val - '0' : val;
    }
}

void InitNodes() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int val = nodes[i][j].val;
      int move_row[4] = { 0, val, 0, -val };
      int move_col[4] = { val, 0, -val, 0 };

      for (int k = 0; k < 4; ++k) {
        int new_i = i + move_row[k];
        int new_j = j + move_col[k];

        if (val == 'H' || new_i < 0 || new_j < 0 || new_i >= n || new_j >= m || nodes[new_i][new_j].val == 'H') {
          nodes[i][j].nexts[k].first = -1;
          nodes[i][j].nexts[k].second = -1;
        } else {
          nodes[i][j].nexts[k].first = new_i;
          nodes[i][j].nexts[k].second = new_j;
        }
      }
    }
  }
}

int DepthFirstSearch(int row, int col) {
  if (dp[row][col] != 0)
    return dp[row][col];
  
  Node& node = nodes[row][col];
  visited[row][col] = true;

  int max_val = 0;
  for (int i = 0; i < 4; ++i) {
    int next_row = node.nexts[i].first;
    int next_col = node.nexts[i].second;
    
    if (next_row == -1 && next_col == -1)
      continue;
    
    if (visited[next_row][next_col]) {
      cout << "-1\n";
      exit(0);
    }
    
    max_val = max(max_val, DepthFirstSearch(next_row, next_col));
  }

  visited[row][col] = false;
  return dp[row][col] = max_val + 1;
}

void Solve() {
  InitNodes();
  cout << DepthFirstSearch(0, 0) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}