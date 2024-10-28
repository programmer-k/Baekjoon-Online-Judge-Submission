#include <iostream>
#include <string>
using namespace std;

int n, k;
string words[50];
bool alphabets[26];
int max_count;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> words[i];
}

void CalculateMaximumReadableWords(int index, int count) {
  if (index >= 26) {
    if (count != k)
      return;
    
    int readble_words = 0;
    for (int i = 0; i < n; ++i) {
      bool is_readable = true;
      for (size_t j = 0; j < words[i].size(); ++j) {
        if (!alphabets[words[i][j] - 'a'])
          is_readable = false;
      }
      
      if (is_readable)
        ++readble_words;
    }

    max_count = max(max_count, readble_words);
    return;
  }

  if (alphabets[index]) {
    CalculateMaximumReadableWords(index + 1, count);
  } else {
    // Mark the current index as readable.
    alphabets[index] = true;
    CalculateMaximumReadableWords(index + 1, count + 1);
    
    // Mark the current index as non-readble.
    alphabets[index] = false;
    CalculateMaximumReadableWords(index + 1, count);
  }
}

void Solve() {
  for (int i = 0; i < n; ++i)
    words[i] = words[i].substr(4, words[i].size() - 8);

  alphabets[0] = alphabets[2] = alphabets[8] = alphabets[13] = alphabets[19] = true;
  CalculateMaximumReadableWords(0, 5);
  cout << max_count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}