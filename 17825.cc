#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int dice_nums[10];
unordered_map<int, vector<int>> moves = {
  { 0, { 1, 2, 3, 4, 5 } },
  { 1, { 2, 3, 4, 5, 6 } },
  { 2, { 3, 4, 5, 6, 7 } },
  { 3, { 4, 5, 6, 7, 8 } },
  { 4, { 5, 6, 7, 8, 9 } },
  { 5, { 21, 22, 23, 24, 25 } },
  { 6, { 7, 8, 9, 10, 11 } },
  { 7, { 8, 9, 10, 11, 12 } },
  { 8, { 9, 10, 11, 12, 13 } },
  { 9, { 10, 11, 12, 13, 14 } },
  { 10, { 27, 28, 24, 25, 26 } },
  { 11, { 12, 13, 14, 15, 16 } },
  { 12, { 13, 14, 15, 16, 17 } },
  { 13, { 14, 15, 16, 17, 18 } },
  { 14, { 15, 16, 17, 18, 19 } },
  { 15, { 29, 30, 31, 24, 25 } },
  { 16, { 17, 18, 19, 20, -1 } },
  { 17, { 18, 19, 20, -1, -1 } },
  { 18, { 19, 20, -1, -1, -1 } },
  { 19, { 20, -1, -1, -1, -1 } },
  { 20, { -1, -1, -1, -1, -1 } },
  { 21, { 22, 23, 24, 25, 26 } },
  { 22, { 23, 24, 25, 26, 20 } },
  { 23, { 24, 25, 26, 20, -1 } },
  { 24, { 25, 26, 20, -1, -1 } },
  { 25, { 26, 20, -1, -1, -1 } },
  { 26, { 20, -1, -1, -1, -1 } },
  { 27, { 28, 24, 25, 26, 20 } },
  { 28, { 24, 25, 26, 20, -1 } },
  { 29, { 30, 31, 24, 25, 26 } },
  { 30, { 31, 24, 25, 26, 20 } },
  { 31, { 24, 25, 26, 20, -1 } }
};

unordered_map<int, int> scores = {
  { -1, 0 }, { 0, 0 }, { 1, 2 }, { 2, 4 }, { 3, 6 }, { 4, 8 }, { 5, 10 }, { 6, 12 }, { 7, 14 },
  { 8, 16 }, { 9, 18 }, { 10, 20 }, { 11, 22 }, { 12, 24 }, { 13, 26 }, { 14, 28 }, { 15, 30 },
  { 16, 32 }, { 17, 34 }, { 18, 36 }, { 19, 38 }, { 20, 40 }, { 21, 13 }, { 22, 16 }, { 23, 19 },
  { 24, 25 }, { 25, 30 }, { 26, 35 }, { 27, 22 }, { 28, 24 }, { 29, 28 }, { 30, 27 }, { 31, 26 }
};

vector<int> positions(4);
int max_score;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 10; ++i)
    cin >> dice_nums[i];
}

void CalcMaxScore(int move_count, int current_score) {
  if (move_count == 10) {
    max_score = max(max_score, current_score);
    return;
  }

  int step_forward = dice_nums[move_count];
  for (int i = 0; i < 4; ++i) {
    int& current_position = positions[i];

    // Skip already finished one.
    if (current_position == -1)
      continue;

    int next_position = moves[current_position][step_forward - 1];

    // Skip duplicate positions.
    bool is_duplicate_position = false;
    for (int j = 0; j < 4; ++j)
      if (next_position != -1 && next_position == positions[j])
        is_duplicate_position = true;

    if (is_duplicate_position)
      continue;

    int score_added = scores[next_position];
    swap(current_position, next_position);
    CalcMaxScore(move_count + 1, current_score + score_added);
    swap(current_position, next_position);
  }
}

void Solve() {
  CalcMaxScore(0, 0);
  cout << max_score << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}