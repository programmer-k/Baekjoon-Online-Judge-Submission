#include <iostream>
#include <numeric>
using namespace std;

int t;
int m, n, x, y;

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> t;
}

void Solve() {
  int threshold = lcm(m, n);
  int answer = 1;
  int val_to_one = min(x, y) - 1;
  int new_x, new_y;

  new_x = x - val_to_one;
  new_y = y - val_to_one;
  //cout << "new_x: " << new_x << ", new_y: " << new_y << endl;

  int curr_x = 1, curr_y = 1;
  while (true) {
    int min_next = min(m - curr_x, n - curr_y) + 1;

    if ((curr_x == new_x && curr_y == new_y) || answer > threshold)
      break;

    if (curr_x + min_next > m)
      curr_x = curr_x + min_next - m;
    else
      curr_x = curr_x + min_next;
    if (curr_y + min_next > n)
      curr_y = curr_y + min_next - n;
    else
      curr_y = curr_y + min_next;
    //curr_y = (curr_y + min_next) % m;
    //curr_y = (curr_y + min_next) % n;
    answer += min_next;
    //cout << curr_x << ", " << curr_y << ", " << answer << endl;
  }

  if (answer > threshold)
    cout << "-1\n";
  else
    cout << answer + val_to_one << '\n';
}

int main(void) {
  GetInput1();
  for (int i = 0; i < t; ++i) {
    cin >> m >> n >> x >> y;
    Solve();
  }
  return 0;
}