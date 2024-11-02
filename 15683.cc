#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, m;
int office[8][8];
int max_blind_spot;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> office[i][j];
}

void MarkRightDirection(vector<pair<int, int>>& marks, int i, int j) {
  for (int k = j + 1; k < m; ++k) {
    if (office[i][k] == 6)
      break;
    else if (office[i][k] >= 1 && office[i][k] <= 5)
      continue;
    else if (office[i][k] == 0) {
      office[i][k] = '#';
      marks.push_back({ i, k });
    }
  }
}

void MarkLeftDirection(vector<pair<int, int>>& marks, int i, int j) {
  for (int k = j - 1; k >= 0; --k) {
    if (office[i][k] == 6)
      break;
    else if (office[i][k] >= 1 && office[i][k] <= 5)
      continue;
    else if (office[i][k] == 0) {
      office[i][k] = '#';
      marks.push_back({ i, k });
    }
  }
}

void MarkUpwardDirection(vector<pair<int, int>>& marks, int i, int j) {
  for (int k = i - 1; k >= 0; --k) {
    if (office[k][j] == 6)
      break;
    else if (office[k][j] >= 1 && office[k][j] <= 5)
      continue;
    else if (office[k][j] == 0) {
      office[k][j] = '#';
      marks.push_back({ k, j });
    }
  }
}

void MarkDownwardDirection(vector<pair<int, int>>& marks, int i, int j) {
  for (int k = i + 1; k < n; ++k) {
    if (office[k][j] == 6)
      break;
    else if (office[k][j] >= 1 && office[k][j] <= 5)
      continue;
    else if (office[k][j] == 0) {
      office[k][j] = '#';
      marks.push_back({ k, j });
    }
  }
}

void ClearMarkings(vector<pair<int ,int>>& marks) {
  for (pair<int, int> p : marks)
    office[p.first][p.second] = 0;
  marks.clear();
}

void CalcMinBlindSpot(int i, int j) {
  //cout << "CalcMinBlindSpot(" << i << ", " << j << ")" << endl;
  // Exit condition
  if (i == n && j == 0) {
    /*for (int idx1 = 0; idx1 < n; ++idx1) {
      for (int idx2 = 0; idx2 < m; ++idx2) {
        if (office[idx1][idx2] == '#')
          cout << "# ";
        else
          cout << office[idx1][idx2] << ' ';
      }
      cout << '\n';
    }*/

    // Count all blind spots.
    int blind_spot_count = 0;
    for (int idx1 = 0 ; idx1 < n; ++idx1)
      for (int idx2 = 0; idx2 < m; ++idx2)
        if (office[idx1][idx2] == '#')
          ++blind_spot_count;
    
    max_blind_spot = max(max_blind_spot, blind_spot_count);
    //cout << "max_blind_spot: " << max_blind_spot << endl;
    return;
  }

  int next_i = j == m - 1 ? i + 1 : i;
  int next_j = j == m - 1 ? 0 : j + 1;
  vector<pair<int, int>> marks;

  //cout << "office[i][j]: " << office[i][j] << endl;
  if (office[i][j] == 0 || office[i][j] == 6 || office[i][j] == '#') {
    // Nothing to do for the walls and empty space.
    CalcMinBlindSpot(next_i, next_j);
  } else if (office[i][j] == 1) {
    MarkRightDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);

    MarkLeftDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);

    MarkUpwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);
    
    MarkDownwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);
  } else if (office[i][j] == 2) {
    MarkLeftDirection(marks, i, j);
    MarkRightDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);

    MarkUpwardDirection(marks, i, j);
    MarkDownwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);
  } else if (office[i][j] == 3) {
    MarkUpwardDirection(marks, i, j);
    MarkRightDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);

    MarkRightDirection(marks, i, j);
    MarkDownwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);

    MarkDownwardDirection(marks, i, j);
    MarkLeftDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);

    MarkLeftDirection(marks, i, j);
    MarkUpwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);
  } else if (office[i][j] == 4) {
    MarkLeftDirection(marks, i, j);
    MarkRightDirection(marks, i, j);
    MarkUpwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);

    MarkRightDirection(marks, i, j);
    MarkUpwardDirection(marks, i, j);
    MarkDownwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);

    MarkLeftDirection(marks, i, j);
    MarkRightDirection(marks, i, j);
    MarkDownwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);

    MarkLeftDirection(marks, i, j);
    MarkUpwardDirection(marks, i, j);
    MarkDownwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);
  } else if (office[i][j] == 5) {
    MarkRightDirection(marks, i, j);
    MarkLeftDirection(marks, i, j);
    MarkUpwardDirection(marks, i, j);
    MarkDownwardDirection(marks, i, j);
    CalcMinBlindSpot(next_i, next_j);
    ClearMarkings(marks);
  }
}

void Solve() {
  //cout << endl;
  CalcMinBlindSpot(0, 0);
  int object_count = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (office[i][j] != 0)
        ++object_count;
  cout << n * m - object_count - max_blind_spot << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}