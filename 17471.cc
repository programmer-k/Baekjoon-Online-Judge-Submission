#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <cstring>
using namespace std;

int n;
int populations[11];
vector<int> edges[11];
int min_population_diff = numeric_limits<int>::max();

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> populations[i];

  for (int curr = 1; curr <= n; ++curr) {
    int count;
    cin >> count;
    
    for (int j = 0; j < count; ++j) {
      int next;
      cin >> next;
      edges[curr].push_back(next);
    }
  }
}

void BreadthFirstSearch(int start, vector<int>& split_info, bool* visited) {
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int next_node : edges[node]) {
      if (!visited[next_node] && split_info[next_node] == split_info[start]) {
        q.push(next_node);
        visited[next_node] = true;
      }
    }
  }
}

bool IsValidSplit(vector<int>& split_info) {
  bool visited[11];
  memset(visited, false, sizeof(visited));

  // Invalid if all of the nodes are in one side.
  bool all_one = true;
  bool all_two = true;
  for (int i = 0; i < ssize(split_info); ++i) {
    if (split_info[i] == 1) {
      all_two = false;
    } else if (split_info[i] == 2) {
      all_one = false;
    }
  }

  if (all_one || all_two)
    return false;

  // Visit split 1.
  for (int i = 1; i <= n; ++i) {
    if (split_info[i] == 1) {
      BreadthFirstSearch(i, split_info, visited);
      break;
    }
  }

  // Visit split 2.
  for (int i = 1; i <= n; ++i) {
    if (split_info[i] == 2) {
      BreadthFirstSearch(i, split_info, visited);
      break;
    }
  }

  // If there still is a node unvisited, then it means there is a disconnection.
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      return false;
    }
  }

  return true;
}

int CalculateMinPopulationDiff(vector<int>& split_info) {
  int split1 = 0, split2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (split_info[i] == 1) {
      split1 += populations[i];
    } else {
      split2 += populations[i];
    }
  }

  return abs(split2 - split1);
}

void SplitRegions(vector<int>& split_info, int index) {
  // Base case: If spliting is all done, check whether the split is valid.
  if (index == n + 1) {
    if (IsValidSplit(split_info)) {
      min_population_diff = min(min_population_diff, CalculateMinPopulationDiff(split_info));
      
    }

    return;
  }

  // Select the current region as 1.
  split_info.push_back(1);
  SplitRegions(split_info, index + 1);
  split_info.pop_back();

  // Select the current region as 1.
  split_info.push_back(2);
  SplitRegions(split_info, index + 1);
  split_info.pop_back();
}

void Solve() {
  vector<int> split_info;
  split_info.push_back(0);
  SplitRegions(split_info, 1);

  if (min_population_diff == numeric_limits<int>::max())
    cout << "-1\n";
  else
    cout << min_population_diff << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}