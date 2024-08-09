#include <iostream>
#include <deque>
using namespace std;

deque<char> wheels[5];
int k;
int wheel_idxs[100];
int directions[100];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 1; i <= 4; ++i) {
    for (int j = 0; j < 8; ++j) {
      char val;
      cin >> val;
      wheels[i].push_back(val);
    }
  }

  cin >> k;
  for (int i = 0; i < k; ++i)
    cin >> wheel_idxs[i] >> directions[i];
}

void Rotate(int wheel_idx, int direction, int propagation) {
  // Firstly, recursively rotate the neighboring wheels if necessary.
  deque<char>& wheel = wheels[wheel_idx];
  char prev_sawtooth = wheel[6];
  char next_sawtooth = wheel[2];
  int opposite_direction = direction == 1 ? -1 : 1;
  bool propagate_left = propagation == 2 ? false : true;
  bool propagate_right = propagation == 1 ? false : true;

  if (propagate_left && wheel_idx >= 2 && prev_sawtooth != wheels[wheel_idx - 1][2]) {
    Rotate(wheel_idx - 1, opposite_direction, 1);
  }

  if (propagate_right && wheel_idx <= 3 && next_sawtooth != wheels[wheel_idx + 1][6]) {
    Rotate(wheel_idx + 1, opposite_direction, 2);
  }  

  // Secondly, rotate the given wheel.
  if (direction == 1) {
    wheel.push_front(wheel.back());
    wheel.pop_back();
  } else {
    wheel.push_back(wheel.front());
    wheel.pop_front();
  }
}

int CalcTotalScore() {
  int total_score = 0;
  for (int i = 4; i > 0; --i) {
    total_score *= 2;
    if (wheels[i][0] == '1')
      total_score += 1;
  }
  return total_score;
}

void Solve() {
  for (int i = 0; i < k; ++i)
    Rotate(wheel_idxs[i], directions[i], 3);

  cout << CalcTotalScore() << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}