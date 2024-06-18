#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int trees[1000002];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> trees[i];
}

void Solve() {
  sort(trees + 1, trees + n + 1, greater<int>());
  /*for (int i = 1; i <= n + 1; ++i)
    cout << trees[i] << ' ';
  cout << endl;*/

  int total_length = 0;
  int curr_height = trees[1];
  for (int i = 1; i <= n; ++i) {
    int next_tree = trees[i + 1];

    while (total_length < m) {
      if (curr_height == next_tree)
        break;

      --curr_height;
      total_length += i;
      //cout << curr_height << ", " << total_length << endl;
    }
  }

  cout << curr_height << '\n';
}

int main(void)
{
  GetInput();
  Solve();
  return 0;
}