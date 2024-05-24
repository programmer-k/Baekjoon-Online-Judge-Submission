#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];

int main(void) {
  for (int i = 0; i < 5; ++i)
    cin >> arr[i];
  
  int total = 0;
  for (int i = 0; i < 5; ++i)
    total += arr[i];
  cout << total / 5 << '\n';

  sort(arr, arr + 5);
  cout << arr[2] << '\n';
  return 0;
}