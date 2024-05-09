#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Player {
  string nickname;
  int level;
};

struct Room {
  vector<Player> players;
  int level_lower_limit;
  int level_upper_limit;
};

int p, m;
vector<Player> players;

bool compare(Player player1, Player player2) {
  return player1.nickname < player2.nickname;
}

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> p >> m;
  for (int i = 0; i < p; i++) {
    Player player;
    cin >> player.level >> player.nickname;
    players.push_back(player);
  }
}

void Solve() {
  vector<Room> rooms;
  for (int i = 0; i < p; i++) {
    bool enter = false;
    Player player = players[i];
    int level = player.level;

    // Check whether there is a room to enter.
    for (unsigned int j = 0; j < rooms.size(); j++) {
      int lower_limit = rooms[j].level_lower_limit;
      int upper_limit = rooms[j].level_upper_limit;
      int room_size = rooms[j].players.size();
      if (lower_limit <= level && level <= upper_limit && room_size < m) {
        rooms[j].players.push_back(player);
        enter = true;
        break;
      }
    }

    // Otherwise, create a new room and enter.
    if (!enter) {
      Room room;
      room.players.push_back(player);
      room.level_lower_limit = player.level - 10;
      room.level_upper_limit = player.level + 10;
      rooms.push_back(room);
    }
  }

  for (unsigned int i = 0; i < rooms.size(); i++) {
    int room_size = rooms[i].players.size();
    if (room_size == m) {
      cout << "Started!\n";
    } else {
      cout << "Waiting!\n";
    }

    sort(rooms[i].players.begin(), rooms[i].players.end(), compare);
    for (unsigned int j = 0; j < rooms[i].players.size(); j++) {
      cout << rooms[i].players[j].level << ' ' << rooms[i].players[j].nickname << '\n';
    }
  }
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}