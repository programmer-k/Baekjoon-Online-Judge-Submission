#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int alphabets1[26];
int alphabets2[26];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> str1 >> str2;
}

void Solve() {
  for (unsigned int i = 0; i < str1.size(); ++i)
    ++alphabets1[str1[i] - 'a'];

  for (unsigned int i = 0; i < str2.size(); ++i)
    ++alphabets2[str2[i] - 'a'];

  int total = 0;
  for (int i = 0; i < 26; ++i) {
    total += abs(alphabets1[i] - alphabets2[i]);
  }
  cout << total << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}