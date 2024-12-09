#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int v;
vector<pair<int, int>> edges[100'001];
bool visited[100'001];
int answer;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> v;
  for (int i = 0; i < v; ++i) {
    int from;
    cin >> from;

    while (true) {
      int to, dist;
      cin >> to;

      if (to == -1)
        break;
      
      cin >> dist;
      edges[from].push_back({ to, dist });
    }
  }
}

int DepthFirstSearch(int node) {
  int highest_depth = 0;
  int second_highest_depth = 0;
  visited[node] = true;

  for (pair<int, int> next : edges[node]) {
    int next_node = next.first;
    int next_dist = next.second;

    if (visited[next_node])
      continue;

    int depth = DepthFirstSearch(next_node) + next_dist;

    if (second_highest_depth < depth && depth < highest_depth)
      second_highest_depth = depth;
    else if (depth >= highest_depth) {
      second_highest_depth = highest_depth;
      highest_depth = depth;
    }
  }

  answer = max(answer, highest_depth + second_highest_depth);
  return highest_depth;
}

void Solve() {
  DepthFirstSearch(1);
  cout << answer << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}