#include <iostream>
using namespace std;

int weight_count;
int weights[31];
int marble_count;
int marbles[7];
bool dp[31][15'001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> weight_count;
  for (int i = 1; i <= weight_count; ++i)
    cin >> weights[i];
  
  cin >> marble_count;
  for (int i = 0; i < marble_count; ++i)
    cin >> marbles[i];
}

void FindAllMeasureableMarbleWeights(int index, int curr_weight) {
  if (index > weight_count || dp[index][curr_weight])
    return;

  dp[index][curr_weight] = true;
  FindAllMeasureableMarbleWeights(index + 1, curr_weight);
  FindAllMeasureableMarbleWeights(index + 1, curr_weight + weights[index + 1]);
  FindAllMeasureableMarbleWeights(index + 1, abs(curr_weight - weights[index + 1]));
}

void Solve() {
  FindAllMeasureableMarbleWeights(0, 0);

  for (int i = 0; i < marble_count; ++i) {
    if (marbles[i] > 15'000)
      cout << "N ";
    else if (dp[weight_count][marbles[i]])
      cout << "Y ";
    else
      cout << "N ";
  }
  cout << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}