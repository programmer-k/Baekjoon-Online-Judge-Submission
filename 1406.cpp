#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string str;
int m;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  cin >> str;
  cin >> m;
  cin.ignore();
}

void Solve() {
  stack<char> left;
  stack<char> right;

  for (unsigned int i = 0; i < str.size(); i++) {
    left.push(str[i]);
  }

  for (int i = 0; i < m; i++) {
    string command;
    getline(cin, command);
    switch (command[0]) {
      case 'L':
        if (!left.empty()) {
          right.push(left.top());
          left.pop();
        }
        break;
      case 'D':
        if (!right.empty()) {
          left.push(right.top());
          right.pop();
        }
        break;
      case 'B':
        if (!left.empty())
          left.pop();
        break;
      default:  // P $
        char character = command[2];
        left.push(character);
        break;
    }

    //cout << str << endl;
    //cin >> ch;
  }

  vector<char> vec;
  while (!left.empty()) {
    vec.push_back(left.top());
    left.pop();
  }
  for (int i = vec.size() - 1; i >= 0; i--) {
    cout << vec[i];
  }

  while (!right.empty()) {
    cout << right.top();
    right.pop();
  }
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}