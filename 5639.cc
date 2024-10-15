#include <iostream>
using namespace std;

int arr[10000];
int arr_size;

void GetInput() {
  //cout << "GetInput" << endl;
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int num;
  while (cin >> num) {
    arr[arr_size++] = num;
  }
}

void PrintPostOrder(int start, int end) {
  // start: inclusive, end: exclusive
  // Thus, start must be always less than end.
  // If not, stop.
  if (start >= end)
    return;
  
  int right = start + 1;
  while (right < end && arr[right] <= arr[start]) {
    ++right;
  }

  // Print the left child.
  PrintPostOrder(start + 1, right);

  // Print the right child.
  PrintPostOrder(right, end);

  // Print the root.
  cout << arr[start] << '\n';
}

void Solve() {
  //cout << "Solve" << endl;
  PrintPostOrder(0, arr_size);
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}