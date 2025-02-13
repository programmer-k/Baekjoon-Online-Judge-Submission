#include <iostream>
#include <string>
using namespace std;

int s, p;
string dna_str;
int a, c, g, t;
int a_count, c_count, g_count, t_count;
int answer;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s >> p;
  cin >> dna_str;
  cin >> a >> c >> g >> t;
}

void CountCharacter(char ch, int val) {
  if (ch == 'A')
    a_count += val;
  else if (ch == 'C')
    c_count += val;
  else if (ch == 'G')
    g_count += val;
  else
    t_count += val;
}

bool IsValidPassword() {
  if (a_count >= a && c_count >= c && g_count >= g && t_count >= t)
    return true;
  else
    return false;
}

void Solve() {
  for (int i = 0; i < p; ++i) {
    CountCharacter(dna_str[i], 1);
  }

  if (IsValidPassword())
      ++answer;

  for (int i = p; i < s; ++i) {    
    CountCharacter(dna_str[i], 1);
    CountCharacter(dna_str[i - p], -1);

    if (IsValidPassword())
      ++answer;
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}