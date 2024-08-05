#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int l, c;
char characters[15];
vector<char> picks;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> l >> c;
  for (int i = 0; i < c; ++i)
    cin >> characters[i];
}

void PickAndPrint(int idx) {
  if ((int) picks.size() == l) {
    int vowel = 0, consonant = 0;
    for (unsigned int i = 0; i < picks.size(); ++i)
      if (picks[i] == 'a' || picks[i] == 'e' || picks[i] == 'i' || picks[i] == 'o' || picks[i] == 'u')
        ++vowel;
      else
        ++consonant;
    
    if (vowel >= 1 && consonant >= 2) {
      for (unsigned int i = 0; i < picks.size(); ++i)
        cout << picks[i];
      cout << '\n';
    }

    return;
  }

  if (idx == c)
    return;
  
  picks.push_back(characters[idx]);
  PickAndPrint(idx + 1);
  picks.pop_back();

  PickAndPrint(idx + 1);
}

void Solve() {
  assert(c < 16);
  sort(characters, characters + c);
  PickAndPrint(0);
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}