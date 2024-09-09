#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n;
int students[401];
int likes[401][5];
int classroom[21][21];
int idx[21][21];

struct Data {
  int like_count;
  int empty_count;
  int row;
  int col;
};

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n * n; ++i) {
    cin >> students[i];
    for (int j = 1; j <= 4; ++j)
      cin >> likes[i][j];
  }
}

void Rules(int index, vector<Data>& results) {
  //int highest_like_count = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      // The seat is currently occupied.
      if (classroom[i][j] != 0)
        continue;

      int like_count = 0;
      int empty_count = 0;
      int move_row[4] = { 1, 0, -1, 0 };
      int move_col[4] = { 0, 1, 0, -1 };

      for (int k = 0; k < 4; ++k) {
        int new_i = i + move_row[k];
        int new_j = j + move_col[k];

        // Out of range
        if (new_i <= 0 || new_j <= 0 || new_i > n || new_j > n)
          continue;

        int adjacent_seat = classroom[new_i][new_j];
        for (int l = 1; l <= 4; ++l) {
          if (adjacent_seat == likes[index][l])
            ++like_count;
        }

        if (adjacent_seat == 0)
          ++empty_count;
      }

      results.push_back({ like_count, empty_count, i, j });
    }
  }
}

bool Compare(const Data& data1, const Data& data2) {
  if (data1.like_count == data2.like_count) {
    if (data1.empty_count == data2.empty_count) {
      if (data1.row == data2.row) {
        return data1.col < data2.col;
      }

      return data1.row < data2.row;
    }

    return data1.empty_count > data2.empty_count;
  }

  return data1.like_count > data2.like_count;
}

void AssignSeat(int index) {
  vector<Data> results;
  Rules(index, results);
  sort(results.begin(), results.end(), Compare);
  //cout << "result" << endl;
  //for (int i = 0; i < results.size(); ++i)
  //  cout << results[i].like_count << results[i].empty_count << results[i].row << results[i].col << endl;

  classroom[results[0].row][results[0].col] = students[index];
  idx[results[0].row][results[0].col] = index;
}

void Calc() {
  int total = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int like_count = 0;
      int move_row[4] = { 1, 0, -1, 0 };
      int move_col[4] = { 0, 1, 0, -1 };

      for (int k = 0; k < 4; ++k) {
        int new_i = i + move_row[k];
        int new_j = j + move_col[k];

        // Out of range
        if (new_i <= 0 || new_j <= 0 || new_i > n || new_j > n)
          continue;

        int adjacent_seat = classroom[new_i][new_j];
        for (int l = 1; l <= 4; ++l) {
          if (adjacent_seat == likes[idx[i][j]][l])
            ++like_count;
        }
      }

      if (like_count == 0)
        continue;

      int score = 1; 
      for (int i = 1; i < like_count; ++i)
        score *= 10;
      
      total += score;
    }
  }

  cout << total << endl;
}

void Solve() {
  for (int i = 1; i <= n * n; ++i) {
    AssignSeat(i);
  }

  /*for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << classroom[i][j] << ' ';
    }
    cout << endl;
  }*/

  Calc();
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}