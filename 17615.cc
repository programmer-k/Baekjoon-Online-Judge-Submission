#include <iostream>
using namespace std;

int n;
char arr[500'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
}

bool IsAlreadySorted() {
  int change = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] != arr[i + 1]) {
      ++change;
    }
  }

  if (change <= 1)
    return true;
  else
    return false;
}

int CalcMinMoves(char ch) {
  // Already sorted.
  if (IsAlreadySorted())
    return 0;
  
  // No edge available.
  if (ch != arr[0] && ch != arr[n - 1]) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] == ch) {
        ++count;
      }
    }

    return count;
  }

  // Left count
  int left_count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == ch) {
      ++left_count;
    } else {
      break;
    }
  }

  // Right count
  int right_count = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (arr[i] == ch) {
      ++right_count;
    } else {
      break;
    }
  }

  // Total count
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == ch) {
      ++count;
    }
  }

  if (left_count == 0) {
    return count - right_count;
  } else if (right_count == 0) {
    return count - left_count;
  } else {
    return count - max(left_count, right_count);
  }
}

void Solve() {
  cout << min(CalcMinMoves('R'), CalcMinMoves('B')) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}