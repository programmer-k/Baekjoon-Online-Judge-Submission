#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int vote_count;
int arr[1000];
vector<pair<int, int>> pics;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> vote_count;
  for (int i = 0; i < vote_count; ++i)
    cin >> arr[i];
}

void Solve() {
  for (int i = 0; i < vote_count; ++i) {
    bool found = false;
    int min_vote = 9999;
    for (int j = 0; j < ssize(pics); ++j) {
      if (pics[j].first == arr[i]) {
        found = true;
        ++pics[j].second;
        break;
      }

      min_vote = min(min_vote, pics[j].second);
    }

    if (found)
      continue;
    
    if (ssize(pics) == n) {
      for (int j = 0; j < ssize(pics); ++j) {
        if (pics[j].second == min_vote) {
          pics.erase(pics.begin() + j);
          break;
        }
      }
    }

    pics.push_back({ arr[i], 1 });
  }

  sort(pics.begin(), pics.end());
  for (int i = 0; i < ssize(pics); ++i) {
    cout << pics[i].first << ' ';
  }
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}