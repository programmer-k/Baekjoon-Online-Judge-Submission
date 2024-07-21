#include <iostream>
#include <string>
using namespace std;

int k;
char inequality_signs[9];
bool in_use[10];
string minimum = "a";
string maximum;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> k;
  for (int i = 0; i < k; ++i)
    cin >> inequality_signs[i];
}

void FindNums(string num) {
  int size = num.size();
  if (size == k + 1) {
    minimum = min(minimum, num);
    maximum = max(maximum, num);
    return;
  }

  for (char digit = '0'; digit <= '9'; ++digit) {
    char last_ch = num.back();
    char inequality_sign = inequality_signs[num.size() - 1];
    if (inequality_sign == '<' && last_ch < digit && !in_use[digit - '0']) {
      in_use[digit - '0'] = true;
      FindNums(num + digit);
      in_use[digit - '0'] = false;
    }
    else if (inequality_sign == '>' && last_ch > digit && !in_use[digit - '0']) {
      in_use[digit - '0'] = true;
      FindNums(num + digit);
      in_use[digit - '0'] = false;
    }
  }
}

void Solve() {
  for (char digit = '0'; digit <= '9'; ++digit) {
    string str(1, digit);
    in_use[digit - '0'] = true;
    FindNums(str);
    in_use[digit - '0'] = false;
  }
  
  cout << maximum << '\n';
  cout << minimum << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}