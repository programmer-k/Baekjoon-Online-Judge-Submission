#include <iostream>
using namespace std;

int n;
char board[50][50];
int maximum_candies = -1;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> board[i][j];
}

void Swap(char& val1, char& val2) {
  char temp = val1;
  val1 = val2;
  val2 = temp;
}

void CountMaximumCandiesHoriontally() {
  for (int i = 0; i < n; ++i) {
    int count = 1;

    for (int j = 0; j < n - 1; ++j) {
      if (board[i][j] == board[i][j + 1])
        ++count;
      else {
        // update before the new kind of candy
        maximum_candies = max(maximum_candies, count);
        count = 1;
      }
    }
    // update before the next row
    maximum_candies = max(maximum_candies, count);
  }
}

void CountMaximumCandiesVertically() {
  for (int j = 0; j < n; ++j) {
    int count = 1;
    
    for (int i = 0; i < n - 1; ++i) {
      if (board[i][j] == board[i + 1][j])
        ++count;
      else {
        // update before the new kind of candy
        maximum_candies = max(maximum_candies, count);
        count = 1;
      }
    }
    // update before the next row
    maximum_candies = max(maximum_candies, count);
  }
}

void CountMaximumCandies() {
  CountMaximumCandiesHoriontally();
  CountMaximumCandiesVertically();
}

void Solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      // Switch horizontally
      Swap(board[i][j], board[i][j + 1]);

      CountMaximumCandies();

      // Switch back
      Swap(board[i][j], board[i][j + 1]);
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      // Switch vertically
      Swap(board[i][j], board[i + 1][j]);

      CountMaximumCandies();

      // Switch back
      Swap(board[i][j], board[i + 1][j]);
    }
  }

  cout << maximum_candies << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}