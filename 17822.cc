#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int n, m, t;
int x[50], d[50], k[50];
deque<int> disks[51];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> t;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int val;
      cin >> val;
      disks[i].push_back(val);
    }
  }

  for (int i = 0; i < t; ++i)
    cin >> x[i] >> d[i] >> k[i];
}

void Rotate(int index) {
  int offset = x[index];
  int direction = d[index];
  int iteration = k[index];

  for (int i = offset; i <= n; i += offset) {
    for (int j = 1; j <= iteration; ++j) {
      if (direction == 0) { // Clockwise
        disks[i].push_front(disks[i].back());
        disks[i].pop_back();
      } else {  // Counter-clockwise
        disks[i].push_back(disks[i].front());
        disks[i].pop_front();
      }
    }
  }

  bool same[51][50];
  bool found = false;
  memset(same, false, sizeof(same));

  // Find adjacent elements with the same value.
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (disks[i][j] != -1 && disks[i][j] == disks[i + 1][j]) {
        found = true;
        same[i][j] = same[i + 1][j] = -1;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (disks[i][j] != -1 && disks[i][j] == disks[i][(j + 1) % m]) {
        found = true;
        same[i][j] = same[i][(j + 1) % m] = -1;
      }
    }
  }

  if (found) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (same[i][j]) {
          disks[i][j] = -1;
        }
      }
    }
  } else {
    int total = 0;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (disks[i][j] != -1) {
          total += disks[i][j];
          ++count;
        }
      }
    }

    double average = (double) total / count;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (disks[i][j] != -1) {
          if (disks[i][j] > average) {
            --disks[i][j];
          } else if (disks[i][j] < average) {
            ++disks[i][j];
          }
        }
      }
    }
  }

}

void Solve() {
  for (int i = 0; i < t; ++i) {
    Rotate(i);
  }

  int answer = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (disks[i][j] != -1) {
        answer += disks[i][j];
      }
    }
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}