#include <iostream>
#include <queue>
#include <deque>
#include <climits>
using namespace std;

const int len = 100001;
int n, k;
int distances[len];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
}

int ZeroOneBreadthFirstSearch(int start) {
  for (int i = 0; i < len; ++i)
    distances[i] = INT_MAX;

  deque<int> q;
  q.push_back(n);
  distances[n] = 0;
  
  while (!q.empty()) {
    int curr_pos = q.front();
    q.pop_front();

    if (curr_pos == k)
      return distances[k];
    
    int next_positions[3] = { curr_pos * 2, curr_pos + 1, curr_pos - 1 };
    for (int i = 0; i < 3; ++i) {
      int weight = (i + 1) / 2;
      int next_pos = next_positions[i];

      // out of range
      if (next_pos < 0 || next_pos >= len)
        continue;
      
      // equal or greater distance
      if (distances[next_pos] <= distances[curr_pos] + weight)
        continue;
      
      //cout << "Add " << next_pos << endl;
      weight ? q.push_back(next_pos) : q.push_front(next_pos);
      distances[next_pos] = distances[curr_pos] + weight;
    }
  }

  return -1;
}

void Solve() {
  cout << ZeroOneBreadthFirstSearch(n) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}