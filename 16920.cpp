#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n, m, p;
int s[10];
char map[1000][1000];
int visited[1000][1000];
vector<pair<int, int>> players_castles[10];
int obstacle_cnt = 0;
int castle_cnt[10];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> p;
  for (int i = 1; i <= p; ++i)
    cin >> s[i];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> map[i][j];
}

//void BreadthFirstSearch(pair<int, int> initial_castle_pos, int limit) {
void BreadthFirstSearch(vector<pair<int, int>>& player_castles, int limit) {
  char player = map[player_castles[0].first][player_castles[0].second];
  int player_num = player - '0';
  queue<pair<int, int>> q;
  for (unsigned int i = 0; i < player_castles.size(); ++i) {
    pair<int, int> p = player_castles[i];
    q.push(p);
    visited[p.first][p.second] = 0;
  }
  castle_cnt[player_num] += player_castles.size();
  player_castles.clear();

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int x = p.first;
    int y = p.second;

    if (visited[x][y] == limit)
      break;

    int move_x[4] = { 1, 0, -1, 0 };
    int move_y[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
      int new_x = x + move_x[i];
      int new_y = y + move_y[i];

      // out of range
      if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
        continue;

      // empty space
      if (map[new_x][new_y] != '.')
        continue;
      
      q.push({ new_x, new_y });
      visited[new_x][new_y] = visited[x][y] + 1;
      map[new_x][new_y] = player;
      if (visited[new_x][new_y] == limit)
        player_castles.push_back({ new_x, new_y });
      else
        ++castle_cnt[player_num];
    }
  }
}

void PrintCastleForEachPlayer() {
  for (int i = 1; i <= p; ++i)
    cout << castle_cnt[i] << ' ';
  cout << '\n';
}

int GetTotalCurrentCastle() {
  int total = 0;
  for (int i = 1; i <= p; ++i)
    total += players_castles[i].size();
  return total;
}

void Solve() {
  // Find each castle and obstacles
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (map[i][j] >= '1' && map[i][j] <= '9')
        players_castles[map[i][j] - '0'].push_back({ i, j });
      else if (map[i][j] == '#')
        ++obstacle_cnt;

  // debugging code
  /*cout << "obstacle_cnt: " << obstacle_cnt << endl;
  for (int i = 1; i <= p; ++i) {
    vector<pair<int, int>>& player_castles = players_castles[i];
    
    cout << "player " << i << ": " ;
    for (unsigned int j = 0; j < player_castles.size(); ++j)
      cout << "<" << player_castles[j].first << ", " << player_castles[j].second << ">, ";
    cout << endl;
  }*/

  while (GetTotalCurrentCastle() != 0) {
    // expand the castles for each player
    for (int i = 1; i <= p; ++i) {
      vector<pair<int, int>>& player_castles = players_castles[i];
      int num_castles = player_castles.size();
      //cout << "num_catles for player " << i << ": " << num_castles << endl;
      if (num_castles != 0)
        BreadthFirstSearch(player_castles, s[i]);
    }
  }

  PrintCastleForEachPlayer();
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}