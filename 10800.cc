#include <iostream>
#include <algorithm>
using namespace std;

struct Ball {
  int color;
  int weight;
  int index;
};

int n;
Ball balls[200'000];
int c[200'001], s[2'001], answers[200'000];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    balls[i].index = i;
    cin >> balls[i].color >> balls[i].weight;
  }
}

bool Compare(const Ball& ball1, const Ball& ball2) {
  if (ball1.weight == ball2.weight)
    return ball1.color < ball2.color;
  return ball1.weight < ball2.weight;
}

void Solve() {
  sort(balls, balls + n, Compare);

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int color = balls[i].color;
    int weight = balls[i].weight;
    int index = balls[i].index;

    c[color] += weight;
    s[weight] += weight;
    sum += weight;

    if (i != 0 && balls[i - 1].color == color && balls[i - 1].weight == weight)
      answers[index] = answers[balls[i - 1].index];
    else
      answers[index] = sum - c[color] - s[weight] + weight;
  }

  for (int i = 0; i < n; ++i)
    cout << answers[i] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}