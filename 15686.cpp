#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int n, m;
char map[50][50];
vector<pair<int, int>> houses;
vector<pair<int, int>> chicken_stores;
vector<bool> picks;
int min_distance = INT_MAX;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];
}

void InitHouseAndChickenStoreInfo() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char val = map[i][j];
      if (val == '1') {
        houses.push_back({ i, j });
      } else if (val == '2') {
        chicken_stores.push_back({ i , j });
      }
    }
  }
}

void CalcDistance() {
  int total_distance = 0;
  for (unsigned int i = 0; i < houses.size(); ++i) {
    int house_min_distance = INT_MAX;
    pair<int, int> house = houses[i];
    for (unsigned int j = 0; j < chicken_stores.size(); ++j) {
      if (picks[j]) {
        pair<int, int> chicken_store = chicken_stores[j];
        house_min_distance = min(house_min_distance, abs(house.first - chicken_store.first) + abs(house.second - chicken_store.second));
      }
    }
    total_distance += house_min_distance;
  }
  min_distance = min(min_distance, total_distance);
}

void PickStoresAndCalcDistance() {
  if (picks.size() == chicken_stores.size()) {
    int pick_count = 0;
    for (unsigned int i = 0; i < picks.size(); ++i)
      if (picks[i])
        ++pick_count;
    
    if (pick_count != m)
      return;

    CalcDistance();
    return;
  }

  picks.push_back(true);
  PickStoresAndCalcDistance();
  picks.pop_back();

  picks.push_back(false);
  PickStoresAndCalcDistance();
  picks.pop_back();
}

void Solve() {  
  InitHouseAndChickenStoreInfo();
  PickStoresAndCalcDistance();
  cout << min_distance << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}