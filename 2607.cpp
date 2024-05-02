#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> words;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    words.push_back(str);
  }
}

void Solve() {
  int similar_words_cnt = 0;
  int alphabet_cnt1[26] = { 0, };
  for (unsigned int i = 0; i < words[0].size(); i++) {
    char ch = words[0][i];
    alphabet_cnt1[ch - 'A']++;
  }

  for (int i = 1; i < n; i++) {
    int alphabet_cnt2[26] = { 0, };
    for (unsigned int j = 0; j < words[i].size(); j++) {
      char ch = words[i][j];
      alphabet_cnt2[ch - 'A']++;
    }

    int diff = 0;
    int positive_diff = 0;
    int negative_diff = 0;
    for (int j = 0; j < 26; j++) {
      int val = alphabet_cnt1[j] - alphabet_cnt2[j];
      if (abs(val) >= 2) {
        diff = 10;
        positive_diff = negative_diff = 10;
        break;
      }
      
      diff += abs(val);
      if (val > 0)
        positive_diff += val;
      else if (val < 0)
        negative_diff += val;
    }

    if (diff <= 1)
      similar_words_cnt++;
    else if (positive_diff == 1 && negative_diff == -1)
      similar_words_cnt++;
  }

  cout << similar_words_cnt << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}