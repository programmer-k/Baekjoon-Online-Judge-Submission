#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

string n;
int k;
int max_val = -1;
int num_count[10];
string dp[7][11];
bool duplicate_num = false;

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
}

void Recursive(int i, int swap_count) {
  //cout << "n: " << n << ", swap_count: " << swap_count << endl;

  if (i == ssize(n) || swap_count == k) {
    if (swap_count == k) {
      max_val = max(max_val, atoi(n.c_str()));
    } else if (i == ssize(n)) {
      // Swap k times if not done yet.
      while (!duplicate_num && swap_count < k) {
        int len = ssize(n);
        swap(n[len - 2], n[len - 1]);
        ++swap_count;
      }

      max_val = max(max_val, atoi(n.c_str()));
    }

    return;
  }

  char& current_num = n[i];
  vector<pair<char, int>> max_nums;
  max_nums.push_back({ 0, -1 });
  
  // Find the largest number right to the current number.
  //pair<char, int> max_num = { 0, -1 };
  for (int j = i + 1; j < ssize(n); ++j) {
    char next_num = n[j];
    if (next_num > max_nums.back().first) {
      max_nums.clear();
      max_nums.push_back({ next_num, j });
    } else if (next_num == max_nums.back().first) {
      max_nums.push_back( { next_num, j });
    }
  }

  for (pair<char, int> max_num : max_nums) {
    // Swap the current number and the largest number found.
    if (max_num.second != -1 && current_num < max_num.first) {
      // The first digit should not be zero.
      if (i == 0 && n[max_num.second] == '0')
        return;
      
      if (swap_count < k) {
        swap(current_num, n[max_num.second]);
        Recursive(i + 1, swap_count + 1);
        swap(current_num, n[max_num.second]);
      }
    } else {
      Recursive(i + 1, swap_count);
    }
  }
}

void Solve() {
  // Count each digit.
  for (int i = 0; i < ssize(n); ++i)
    ++num_count[n[i] - '0'];

  if (ssize(n) == 1 || (ssize(n) == 2 && n[1] == '0')) {
    cout << "-1\n";
    return;
  }

  for (int i = 0; i < 10; ++i)
    if (num_count[i] >= 2)
      duplicate_num = true;

  // Make each number as large as possible from the left side.
  Recursive(0, 0);

  // Swap k times if not done yet.
  /*while (!duplicate_num && swap_count < k) {
    int len = ssize(n);
    swap(n[len - 2], n[len - 1]);
    ++swap_count;
  }*/

  cout << max_val << '\n';
}

/*string FindLargestNum(int index, int swap_left) {
  // Out of bound
  if (index == ssize(n)) {
    if (swap_left == 0)
      max_val = max(max_val, atoi(n.c_str()));
    return;
  }

  if (dp[index][swap_left] != 0) {
    return dp[index][swap_left];
  }

  // Do not swap but continue with the next digit.
  FindLargestNum(index + 1, swap_left);

  // Swap with each digit.
  if (swap_left > 0) {
    for (int i = index + 1; i < ssize(n); ++i) {
      swap(n[index], n[i]);
      if (n[0] != '0') {
        FindLargestNum(index, swap_left - 1);
        FindLargestNum(index + 1, swap_left - 1);
      }
      swap(n[index], n[i]);
    }
  }

  return;
}

void Solve1() {
  cout << FindLargestNum(0, k) << '\n';
  //cout << max_val << '\n';
}*/

int main(void) {
  GetInput();
  Solve();
  return 0;
}
