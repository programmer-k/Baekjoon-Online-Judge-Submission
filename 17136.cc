#include <iostream>
#include <limits>
using namespace std;

int map[10][10];
bool marks[10][10];
int counts[6];
int answer = numeric_limits<int>::max();

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      cin >> map[i][j];
}

void DepthFirstSearch(int index, int count) {
  if (count >= answer)
    return;

  // Check the counts are valid.
  for (int i = 1; i <= 5; ++i)
    if (counts[i] > 5)
      return;

  // Searched all elements in the map.
  if (index == 100) {
    // Add all counts values.
    int total = 0;
    for (int i = 1; i <= 5; ++i)
      total += counts[i];
    answer = min(answer, total);
    return;
  }
  
  int row = index / 10;
  int col = index % 10;

  if (map[row][col] == 0) {
    // Continue searching with the next element.
    DepthFirstSearch(index + 1, count);
  } else {
    // Brute-force the five cases.
    for (int len = 1; len <= 5; ++len) {
      // Check the range is valid.
      if (row + len > 10 || col + len > 10)
        break;
      
      bool valid = true;
      for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
          if (map[row + i][col + j] == 0 || marks[row + i][col + j])
            valid = false;
      
      // Stop if there is a zero.
      if (!valid)
        break;

      // Mark the elements.
      for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
          marks[row + i][col + j] = true;
      
      // Update the counter and continue.
      ++counts[len];
      bool found_next = false;
      for (int i = row; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
          if (!found_next && map[i][j] == 1 && !marks[i][j]) {
            found_next = true;
            DepthFirstSearch(i * 10 + j, count + 1);
          }
        }
      }

      if (!found_next)
        DepthFirstSearch(100, count + 1);
      --counts[len];

      // Unmark the elements.
      for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
          marks[row + i][col + j] = false;
    }
  }
}

void Solve() {
  DepthFirstSearch(0, 0);
  if (answer == numeric_limits<int>::max())
    cout << "-1\n";
  else
    cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}