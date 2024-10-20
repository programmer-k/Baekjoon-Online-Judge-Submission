#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int arr[2001];
int questions_start[1000000];
int questions_end[1000000];
int is_palinedrome[2001][2001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];

  cin >> m;
  for (int i = 0; i < m; ++i)
    cin >> questions_start[i] >> questions_end[i];
}

/*bool IsPalindrome(int start, int end) {
  for (int i = 0; i < (start + end) / 2 - start; ++i)
    if (arr[start + i] != arr[end - i])
      return false;
  
  return true;
}*/

int IsPalindrome(int start, int end) {
  if (start > end)
    return 1;
  
  // Already calculated before
  if (is_palinedrome[start][end] != -1)
    return is_palinedrome[start][end];

  if (arr[start] == arr[end]) {
    is_palinedrome[start][end] = IsPalindrome(start + 1, end - 1);
  } else {
    is_palinedrome[start][end] = 0;
  }

  return is_palinedrome[start][end];
}

void Solve() {
  memset(is_palinedrome, -1 ,sizeof(is_palinedrome));
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j)
      IsPalindrome(i, j);
        //is_palinedrome[i][j] = true;

  for (int i = 0; i < m; ++i) {
    cout << is_palinedrome[questions_start[i]][questions_end[i]] << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}