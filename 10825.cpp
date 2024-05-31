#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Score {
  string name;
  int kor;
  int eng;
  int math;
};

int n;
vector<Score> scores;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string name;
    int kor, eng, math;
    cin >> name >> kor >> eng >> math;
    scores.push_back({ name, kor, eng, math });
  }
}

bool Compare(const Score& score1, const Score& score2) {
  int kor1 = score1.kor;
  int kor2 = score2.kor;
  if (kor1 != kor2) {
    return kor1 > kor2;
  }

  int eng1 = score1.eng;
  int eng2 = score2.eng;
  if (eng1 != eng2) {
    return eng1 < eng2;
  }

  int math1 = score1.math;
  int math2 = score2.math;
  if (math1 != math2) {
    return math1 > math2;
  }

  string name1 = score1.name;
  string name2 = score2.name;
  int len = min(name1.size(), name2.size());
  for (int i = 0; i < len; ++i) {
    char ch1 = name1[i];
    char ch2 = name2[i];
    if (ch1 != ch2) {
      return ch1 < ch2;
    }
  }

  return name1.size() < name2.size();
}

void Solve() {
  sort(scores.begin(), scores.end(), Compare);
  for (int i = 0; i < n; ++i)
    cout << scores[i].name << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}