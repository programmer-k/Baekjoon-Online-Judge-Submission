#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

int fish_map[4][4];
int direction_map[4][4];
int move_row[8] = { -1, -1, -1, 0, 1, 1, 1, 0  };
int move_col[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };
int max_eat_count;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      cin >> fish_map[i][j] >> direction_map[i][j];

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (direction_map[i][j] == 8)
        direction_map[i][j] = 0;
}

void PrintStatus() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << fish_map[i][j] << ' ' << direction_map[i][j] << " | ";
    }
    cout << '\n';
  }
  cout << '\n';
}

void MoveFish(int row, int col) {
  // Check each of the direction.
  for (int i = 0; i < 8; ++i, direction_map[row][col] = (direction_map[row][col] + 1) % 8) {
    int direction = direction_map[row][col];
    int dest_row = row + move_row[direction];
    int dest_col = col + move_col[direction];
    
    // Ouf of range
    if (dest_row < 0 || dest_col < 0 || dest_row >= 4 || dest_col >= 4)
      continue;
    
    // Shark check
    if (fish_map[dest_row][dest_col] == 100)
      continue;
    
    // Swap the two fishes.
    //cout << "Fish #" << fish_map[row][col] << " Moved" << '\n';
    swap(fish_map[row][col], fish_map[dest_row][dest_col]);
    swap(direction_map[row][col], direction_map[dest_row][dest_col]);
    //PrintStatus();
    return;
  }
  
}

void MoveAllFish() {
  // Find all fish and move each one.
  for (int fish_num = 1; fish_num <= 16; ++fish_num) {
    bool fish_moved = false;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        // Found the fish.
        if (!fish_moved && fish_map[i][j] == fish_num) {
          fish_moved = true;
          MoveFish(i, j);
        }
      }
    }
  }
}



void DepthFirstSearch(int row, int col, int eat_count) {
  // Update the maximum value.
  max_eat_count = max(max_eat_count, eat_count);
  //cout << " current sum: " << eat_count << '\n';
  //PrintStatus();

  // Move fish.
  int fish_map_copy[4][4];
  int direction_map_copy[4][4];
  memcpy(fish_map_copy, fish_map, sizeof(fish_map));
  memcpy(direction_map_copy, direction_map, sizeof(direction_map));
  MoveAllFish();

  // Move shark.
  int direction = direction_map[row][col];
  for (int i = 1; i <= 3; ++i) {
    int next_row = row + move_row[direction] * i;
    int next_col = col + move_col[direction] * i;

    // Out of range
    if (next_row < 0 || next_col < 0 || next_row >= 4 || next_col >= 4)
      continue;
    
    // Skip the empty fish.
    if (fish_map[next_row][next_col] == 0)
      continue;
    
    // Eat the fish.
    int fish_num = fish_map[next_row][next_col];
    fish_map[row][col] = 0;
    fish_map[next_row][next_col] = 100;
    //cout << "Shark eat fish #" << fish_num;
    DepthFirstSearch(next_row, next_col, eat_count + fish_num);
    fish_map[row][col] = 100;
    fish_map[next_row][next_col] = fish_num;
  }

  // Recover fish state.
  memcpy(fish_map, fish_map_copy, sizeof(fish_map));
  memcpy(direction_map, direction_map_copy, sizeof(direction_map));
}

void Solve() {
  int fish_num = fish_map[0][0];
  fish_map[0][0] = 100;
  //cout << "Shark eat fish #" << fish_num;
  DepthFirstSearch(0, 0, fish_num);
  cout << max_eat_count << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}