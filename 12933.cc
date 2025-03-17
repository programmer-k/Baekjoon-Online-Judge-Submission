#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector<int> ducks;
int answer;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> str;
}

bool Update(char ch) {
  for (int i = 0; i < ssize(ducks); ++i) {
    if (ch == 'u' && ducks[i] == 0) {
      ++ducks[i];
      return true;
    } else if (ch == 'a' && ducks[i] == 1) {
      ++ducks[i];
      return true;
    } else if (ch == 'c' && ducks[i] == 2) {
      ++ducks[i];
      return true;
    } else if (ch == 'k' && ducks[i] == 3) {
      ducks.erase(ducks.begin() + i);
      return true;
    }
  }

  return false;
}

void Solve() {
  for (int i = 0; i < ssize(str); ++i) {
    char ch = str[i];

    if (ch == 'q') {
      ducks.push_back(0);
      answer = max(answer, static_cast<int>(ssize(ducks)));
    } else if (!Update(ch)) {
      cout << "-1\n";
      return;
    }
  }

  if (ssize(ducks) != 0) {
    cout << "-1\n";
    return;
  }

  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}