#include <iostream>
using namespace std;

int cards[21];

int main(void) {
  for (int i = 1; i <= 20; ++i)
    cards[i] = i;

  for (int i = 0; i < 10; ++i) {
    int a, b;
    cin >> a >> b;

    for (int j = 0; j < (b - a + 1) / 2; ++j) {
      int swap = cards[a + j];
      cards[a + j] = cards[b - j];
      cards[b - j] = swap;
    }
  }

  for (int i = 1; i <= 20; ++i)
    cout << cards[i] << ' ';
  cout << '\n';
  return 0;
}