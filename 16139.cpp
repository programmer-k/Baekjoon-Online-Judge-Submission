#include <iostream>
#include <string>
using namespace std;

string s;
int q;
char a[200000];
int l[200000];
int r[200000];
int alphabet_count[200001][26];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;
  cin >> q;
  for (int i = 0; i < q; ++i)
    cin >> a[i] >> l[i] >> r[i];
}

void Solve() {
  int str_size = s.size();
  for (int i = 0; i < str_size; ++i) {
    char alphabet = s[i];
    for (int j = 0; j < 26; ++j)
      alphabet_count[i + 1][j] = alphabet_count[i][j];
    ++alphabet_count[i + 1][alphabet - 'a'];
  }

  for (int i = 0; i < q; ++i) {
    char alphabet = a[i];
    int low = alphabet_count[l[i]][alphabet - 'a'];
    int high = alphabet_count[r[i] + 1][alphabet - 'a'];
    cout << high - low << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}