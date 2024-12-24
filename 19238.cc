#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, gas;
int start_row, start_col;
int map[21][21];
int start_map[21][21];
int end_map[21][21];
int visited[21][21];
vector<pair<int, int>> start_pos;
vector<pair<int, int>> end_pos;
int dist_to_passenger;
int dist_to_destination;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> gas;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> map[i][j];

  cin >> start_row >> start_col;
  for (int i = 1; i <= m; ++i) {
    int passenger_start_row, passenger_start_col;
    int passenger_end_row, passenger_end_col;
    
    cin >> passenger_start_row >> passenger_start_col;
    cin >> passenger_end_row >> passenger_end_col;

    start_pos.push_back({ passenger_start_row, passenger_start_col });
    end_pos.push_back({ passenger_end_row, passenger_end_col });
    
    start_map[passenger_start_row][passenger_start_col] = i;
    end_map[passenger_end_row][passenger_end_col] = i;
  }
}

bool BreadthFirstSearch(pair<int, int> start) {
  queue<pair<int, int>> q;
  memset(visited, -1, sizeof(visited));
  
  q.push(start);
  visited[start.first][start.second] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row <= 0 || next_col <= 0 || next_row > n || next_col > n)
        continue;
      
      if (visited[next_row][next_col] != -1)
        continue;

      if (map[next_row][next_col] == 1)
        continue;

      q.push({ next_row, next_col });
      visited[next_row][next_col] = visited[row][col] + 1;
    }
  }

  vector<pair<int, int>> answers;
  int min_distance = 1234567890;
  for (int i = 0; i < ssize(start_pos); ++i) {
    pair<int, int> p = start_pos[i];
    int curr_distance = visited[p.first][p.second];
    
    if (curr_distance == -1)
      continue;
    
    if (curr_distance < min_distance) {
      answers.clear();
      answers.push_back(p);
      min_distance = curr_distance;
    } else if (curr_distance == min_distance) {
      answers.push_back(p);
    }
  }

  /*cout << "===============================" << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << visited[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "===============================" << endl;*/

  //cout << "answers size: " << ssize(answers) << endl;
  if (ssize(answers) == 0)
    return false;

  sort(answers.begin(), answers.end());

  dist_to_passenger = visited[answers[0].first][answers[0].second];
  //cout << "dist_to_passenger: " << dist_to_passenger << endl;
  start_row = answers[0].first;
  start_col = answers[0].second;
  return true;
}

bool BreadthFirstSearch2(pair<int, int> start) {
  queue<pair<int, int>> q;
  memset(visited, -1, sizeof(visited));
  
  q.push(start);
  visited[start.first][start.second] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    int row = p.first;
    int col = p.second;
    q.pop();

    int move_row[4] = { 1, 0, -1, 0 };
    int move_col[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int next_row = row + move_row[i];
      int next_col = col + move_col[i];

      if (next_row <= 0 || next_col <= 0 || next_row > n || next_col > n)
        continue;
      
      if (visited[next_row][next_col] != -1)
        continue;
      
      if (map[next_row][next_col] == 1)
        continue;

      q.push({ next_row, next_col });
      visited[next_row][next_col] = visited[row][col] + 1;
    }
  }

  // Find the destination distance.
  int min_distance = -1;
  for (int i = 0; i < ssize(start_pos); ++i) {
    if (start_pos[i] == start) {
      min_distance = visited[end_pos[i].first][end_pos[i].second];
      start_row = end_pos[i].first;
      start_col = end_pos[i].second;
      start_pos.erase(start_pos.begin() + i);
      end_pos.erase(end_pos.begin() + i);
    }
  }

  if (min_distance == -1)
    return false;
  
  dist_to_destination = min_distance;
  return true;
}

void Solve() {
  int passenger_count = 0;
  while (true) {
    // Search the passenger with minimum distance.
    if (!BreadthFirstSearch({ start_row, start_col })) {
      //cout << "fail to move to passenger" << endl;
      break;
    }
    //cout << "moved to " << start_row << ", " << start_col << " (passenger)" << endl;
    
    // Move to the destination.
    if (!BreadthFirstSearch2({ start_row, start_col })) {
      //cout << "fail to move to destination" << endl;
      break;
    }
    /*cout << "moved to " << start_row << ", " << start_col << " (dest)" << endl;

    cout << "gas: " << gas << endl;
    cout << "dist_to_pas: " << dist_to_passenger << endl;
    cout << "dist_to_dest: " << dist_to_destination << endl;*/
    // Recharge the gas.
    if (gas - dist_to_passenger - dist_to_destination >= 0)
      gas = gas - dist_to_passenger - dist_to_destination + dist_to_destination * 2;
    else
      break;

    //cout << "gas: " << gas << endl;
    ++passenger_count;
  }

  // Check whether all jobs are done.
  if (passenger_count == m) {
    cout << gas << '\n';
  } else {
    cout << "-1\n";
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}