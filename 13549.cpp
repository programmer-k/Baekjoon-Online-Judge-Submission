#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int len = 100001;
int n, k;
int map[len];
int dist[len];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
}

/*int BreadthFirstSearch(int start) {
  queue<int> q;
  q.push(start);
  dist[start] = 0;

  int queue_size = q.len();
  for (int i = 0; i < queue_size; ++i) {
    int curr_pos = q.front();
    q.pop();

    if (curr_pos == k)
      return dist[k];

    q.push(curr_pos);

    int next_pos = curr_pos * 2;
    // out of range
    if (next_pos < 0 || next_pos >= len)
      continue;
    
    // already visited
    if (dist[next_pos] != -1)
      continue;
    
    q.push(next_pos);
    dist[next_pos] = dist[curr_pos];
  }

  queue_size = q.len();
  for (int i = 0; i < queue_size; ++i) {
    int curr_pos = q.front();
    q.pop();

    if (curr_pos == k)
      return dist[k];

    int next_positions[2] = { curr_pos + 1, curr_pos - 1 };
    for (int j = 0; j < 2; ++j) {
      int next_pos = next_positions[j];
      // out of range
      if (next_pos < 0 || next_pos >= len)
        continue;
      
      // already visited
      if (dist[next_pos] != -1)
        continue;
      
      q.push(next_pos);
      dist[next_pos] = dist[curr_pos] + 1;
    }
  }

  return -1;
}*/

int BreadthFirstSearch(int start) {
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  //cout << "BFS" << endl;

  while (!q.empty()) {
    int curr_pos = q.front();
    q.pop();

    //cout << "curr_pos: " << curr_pos << endl;

    int next_positions[3] = { curr_pos + 1, curr_pos - 1, curr_pos * 2 };

    for (int i = 0; i < 3; ++i) {
      int next_pos = next_positions[i];
      //cout << "next_pos: " << next_pos << endl;
      // out of range
      if (next_pos < 0 || next_pos >= len)
        continue;

      int distance;
      if (i == 2)
        distance = dist[curr_pos];
      else
        distance = dist[curr_pos] + 1;

      if (distance >= dist[next_pos])
        continue;
      
      //cout << "Add " << next_pos << endl;
      q.push(next_pos);
      dist[next_pos] = distance;
    }
  }

  return dist[k];
}


void Solve() {  
  for (int i = 0; i < len; ++i)
    dist[i] = INT_MAX;
  cout << BreadthFirstSearch(n) << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}