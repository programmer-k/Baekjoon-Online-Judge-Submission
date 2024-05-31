#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<string> serial_numbers;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    serial_numbers.push_back(str);
  }
}

bool Compare(string serial_num1, string serial_num2) {
  int size1 = serial_num1.size();
  int size2 = serial_num2.size();
  if (size1 != size2) {
    return size1 < size2;
  }

  int sum1 = 0, sum2 = 0;
  for (unsigned int i = 0; i < serial_num1.size(); ++i) {
    char ch1 = serial_num1[i];
    char ch2 = serial_num2[i];
    if (ch1 >= '0' && ch1 <= '9')
      sum1 += ch1 - '0';
    if (ch2 >= '0' && ch2 <= '9')
      sum2 += ch2 - '0';
  }

  if (sum1 != sum2) {
    return sum1 < sum2;
  }

  for (unsigned int i = 0; i < serial_num1.size(); ++i) {
    char ch1 = serial_num1[i];
    char ch2 = serial_num2[i];
    if (ch1 != ch2) {
      return ch1 < ch2;
    }
  }

  // cannot reach here.
  return false;
}

void Solve() {
  sort(serial_numbers.begin(), serial_numbers.end(), Compare);
  for (int i = 0; i < n; ++i)
    cout << serial_numbers[i] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}