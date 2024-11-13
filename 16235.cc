#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int add[11][11];
int map[11][11];
vector<int> trees[11][11];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> add[i][j];
  
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    trees[x][y].push_back(z);
  }
}

void SimulateSpringAndSummer() {
  // Sort the trees.
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      sort(trees[i][j].begin(), trees[i][j].end());

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (size_t k = 0; k < trees[i][j].size(); ++k) {
        int tree = trees[i][j][k];
        map[i][j] -= tree;

        // Remove all remaining trees if there is no enough nutrition.
        if (map[i][j] < 0) {
          // Add nutrition.
          map[i][j] += tree;
          for (size_t l = k; l < trees[i][j].size(); ++l) {
            map[i][j] += trees[i][j][l] / 2;
          }
          
          trees[i][j].erase(trees[i][j].begin() + k, trees[i][j].end());
          break;
        }

        // Increment age.
        ++trees[i][j][k];
      }
    }
  }

  /*cout << "[tree]" << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int tree : trees[i][j]) {
        cout << tree;// << ' ';
      }
      cout << ' ';
    }
    cout << '\n';
  }*/
}

void SimulateFall() {
  int move_row[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
  int move_col[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int tree : trees[i][j]) {
        if (tree % 5 == 0) {
          for (int k = 0; k < 8; ++k) {
            int next_row = i + move_row[k];
            int next_col = j + move_col[k];

            if (next_row < 1 || next_col < 1 || next_row > n || next_col > n)
              continue;
            
            trees[next_row][next_col].push_back(1);
          }
        }
      }
    }
  }
}

void SimulateWinter() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      map[i][j] += add[i][j];
    }
  }
}

int CountLiveTrees() {
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      count += trees[i][j].size();
    }
  }

  return count;
}

void Solve() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      map[i][j] = 5;
  
  for (int i = 1; i <= k; ++i) {
    SimulateSpringAndSummer();
    SimulateFall();
    SimulateWinter();
  }

  cout << CountLiveTrees() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}