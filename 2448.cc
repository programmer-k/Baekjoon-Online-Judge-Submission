#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int n;
char output[3072][3072 * 2];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
}

void UpdateStars(int line, int index, int size) {
  if (size == 3) {
    output[line][index] = '*';
    output[line + 1][index - 1] = output[line + 1][index + 1] = '*';
    for (int i = index - 2; i <= index + 2; ++i)
      output[line + 2][i] = '*';
    return;
  }
  
  int next_size = size / 2;
  UpdateStars(line, index, next_size);
  UpdateStars(line + next_size, index - next_size, next_size);
  UpdateStars(line + next_size, index + next_size, next_size);
}

void Solve() {
  memset(output, ' ', sizeof(output));
  UpdateStars(0, n - 1, n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n * 2; ++j)
      cout << output[i][j];
    cout << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}