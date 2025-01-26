#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;

const int INF = numeric_limits<int>::max();
int n, m;
int graph[101][101];
int dists[101][101];
vector<int> moves[101][101];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  
  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i != j) {
        graph[i][j] = INF;
        moves[i][j].push_back(j);
      }
  
  for (int j = 0; j < m; ++j) {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[from][to] = min(graph[from][to], weight);
  }
}

void FloydWarshall() {
  memcpy(dists, graph, sizeof(graph));

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        int new_dist = dists[i][k] + dists[k][j];
        if (dists[i][k] != INF && dists[k][j] != INF && dists[i][j] > new_dist) {
          dists[i][j] = new_dist;
          moves[i][j].clear();
          for (int val : moves[i][k])
            moves[i][j].push_back(val);
          for (int val : moves[k][j])
            moves[i][j].push_back(val);
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dists[i][j] == INF)
        cout << "0 ";
      else
        cout << dists[i][j] << ' ';
    }
    cout << '\n';
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dists[i][j] == INF || i == j) {
        cout << "0\n";
        continue;
      }

      cout << ssize(moves[i][j]) + 1 << ' ' << i << ' ';
      for (int val : moves[i][j])
        cout << val << ' ';
      cout << '\n';
    }
  }
}

void Solve() {
  FloydWarshall();
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}