#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int zeros, ones;
vector<int> positives, negatives;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    if (num == 1)
      ++ones;
    else if (num > 0)
      positives.push_back(num);
    else if (num < 0)
      negatives.push_back(num);
    else
      ++zeros;
  }
}

void Solve() {
  sort(positives.begin(), positives.end());
  sort(negatives.begin(), negatives.end());
  reverse(positives.begin(), positives.end());

  //for (int val : positives)
  //  cout << val << ' ';
  //cout << '\n';

  int total = 0;
  int positives_size = positives.size();
  int negatives_size = negatives.size();
  for (int i = 0; i < positives_size - 1; i += 2) {
    total += positives[i] * positives[i + 1];
    //cout << "total = " << total << endl;
  }

  if (positives_size % 2 == 1)
    total += positives[positives_size - 1];

  for (int i = 0; i < negatives_size - 1; i += 2) {
    total += negatives[i] * negatives[i + 1];
    //cout << "total = " << total << endl;
  }

  if (negatives_size % 2 == 1 && zeros == 0)
    total += negatives[negatives_size - 1];

  total += ones;

  cout << total << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}