#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
using namespace std;

int n, m;

set<string> keywords;
vector<string> used_keywords_list;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string keyword;
    cin >> keyword;
    keywords.insert(keyword);
  }

  for (int i = 0; i < m; i++) {
    string used_keywords;
    cin >> used_keywords;
    used_keywords_list.push_back(used_keywords);
  }
}

void Solve() {
  for (int i = 0; i < m; i++) {
    string used_keywords = used_keywords_list[i];
    istringstream iss(used_keywords);
    string keyword;

    while (getline(iss, keyword, ',')) {
      keywords.erase(keyword);
    }

    cout << keywords.size() << '\n';
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}