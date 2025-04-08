#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> weights;
int max_energy;

void GetInput() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int weight;
    cin >> weight;
    weights.push_back(weight);
  }
}

void CalcMaxEnergy(vector<int> vec, int energy, int remove_idx) {
  if (remove_idx != -1)
    vec.erase(vec.begin() + remove_idx);

  if (vec.size() == 2) {
    max_energy = max(max_energy, energy);
    return;
  }

  for (int i = 1; i < ssize(vec) - 1; ++i) {
    int new_energy = vec[i - 1] * vec[i + 1];
    CalcMaxEnergy(vec, energy + new_energy, i);
  }
}

void Solve() {
  CalcMaxEnergy(weights, 0, -1);
  cout << max_energy << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}