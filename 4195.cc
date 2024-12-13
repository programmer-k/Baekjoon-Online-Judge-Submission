#include <iostream>
#include <string>
#include <utility>
#include <map>
using namespace std;

class UnionFind {
public:
  int parents[200'000];
  int ranks[200'000];

  UnionFind() {
    for (int i = 0; i < 100'000; ++i) {
      parents[i] = i;
      ranks[i] = 1;
    }
  }

  int Find(int x) {
    if (x != parents[x])
      return parents[x] = Find(parents[x]);
    return x;
  }

  int Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    
    if (x == y)
      return ranks[x];

    parents[y] = x;
    ranks[x] += ranks[y];
    return ranks[x];
  }
};

int testcase;
int f;
pair<string, string> friends[100'000];
map<string, int> m;

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> testcase;
}

void GetInput2() {
  cin >> f;
  for (int i = 0; i < f; ++i)
    cin >> friends[i].first >> friends[i].second;
}

void Solve() {
  UnionFind union_find;
  int counter = 0;

  for (int i = 0; i < f; ++i) {
    string name1 = friends[i].first;
    string name2 = friends[i].second;
    int val1 = m.count(name1) > 0 ? m[name1] : m[name1] = counter++;
    int val2 = m.count(name2) > 0 ? m[name2] : m[name2] = counter++;

    int answer = union_find.Union(val1, val2);
    cout << answer << '\n';
  }
}

int main(void) {
  GetInput1();
  for (int i = 0; i < testcase; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}