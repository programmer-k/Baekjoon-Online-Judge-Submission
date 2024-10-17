#include <iostream>
#include <string>
using namespace std;

int n;
string words[10];
bool alphabets_exist[26];
char characters[10];
int characters_nums[10];
bool nums_occupied[10];
int character_count;
int max_total;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> words[i];
}

void CalculateMaximumSum(int index) {
  // Calculate the sum if all number assignments have been finished.
  if (index == character_count) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
      int sub_total = 0;
      for (size_t j = 0; j < words[i].size(); ++j) {
        char ch = words[i][j];
        int k;
        for (k = 0; k < character_count; ++k) {
          if (ch == characters[k]) {
            break;
          }
        }

        sub_total *= 10;
        sub_total += characters_nums[k];
      }
      total += sub_total;
    }

    max_total = max(max_total, total);
    return;
  }

  // Assign all possible numbers to an alphabet.
  for (int i = 0; i < 10; ++i) {
    // Do not use the occupied number to prevent duplicate assignment.
    if (!nums_occupied[i]) {
      nums_occupied[i] = true;
      characters_nums[index] = i;
      CalculateMaximumSum(index + 1);
      nums_occupied[i] = false;
    }
  }
}

void Solve() {
  // Mark all the alphabets showing up.
  for (int i = 0; i < n; ++i) {
    for (size_t j = 0; j < words[i].size(); ++j) {
      alphabets_exist[words[i][j] - 'A'] = true;
    }
  }

  // Add all the alphabets into characters array.
  for (int i = 0; i < 26; ++i) {
    if (alphabets_exist[i]) {
      characters[character_count++] = 'A' + i;
    }
  }

  CalculateMaximumSum(0);
  cout << max_total << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}