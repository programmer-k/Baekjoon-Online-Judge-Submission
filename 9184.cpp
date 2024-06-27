#include <iostream>
#include <cstring>
using namespace std;

int a, b, c;
int answer[101][101][101];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
}

int Solve(int a, int b, int c) {
  //cout << "Solve " << a << ", " << b << ", " << c << endl;
  if (answer[a + 50][b + 50][c + 50] != 0)
    return answer[a + 50][b + 50][c + 50];

  if (a <= 0 || b <= 0 || c <= 0)
    return answer[a + 50][b + 50][c + 50] = 1;
  
  if (a > 20 || b > 20 || c > 20)
    return answer[a + 50][b + 50][c + 50] = Solve(20, 20, 20);
  
  if (a < b && b < c)
    return answer[a + 50][b + 50][c + 50] = Solve(a, b, c - 1) + Solve(a, b - 1, c - 1) - Solve(a, b - 1, c);
  else
    return answer[a + 50][b + 50][c + 50] = Solve(a - 1, b, c) + Solve(a - 1, b - 1, c) + Solve(a - 1, b, c - 1) - Solve(a - 1, b - 1, c - 1);
}

int main(void) {
  GetInput();
  /*for (int i = 0; i <= 100; ++i)
    for (int j = 0; j <= 100; ++j)
      for (int k = 0; k <= 100; ++k)
        answer[i][j][k] = -1234567890;
  */
  //memset(answer, -1234567890, sizeof(answer));
  while (true) {
    cin >> a >> b >> c;

    if (a == -1 && b == -1 && c == -1)
      break;
    
    cout << "w(" << a << ", " << b << ", " << c << ") = " << Solve(a, b, c) << '\n';
  }
  return 0;
}