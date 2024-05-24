#include <iostream>
using namespace std;

int calls[20];
int y_price;
int m_price;

int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> calls[i];
  
  for (int i = 0; i < n; ++i) {
    y_price += (calls[i] / 30 + 1) * 10;
    m_price += (calls[i] / 60 + 1) * 15;
  }

  if (y_price == m_price) {
    cout << "Y M " << y_price << '\n';
  } else if (y_price > m_price) {
    cout << "M " << m_price << '\n';
  } else {
    cout << "Y " << y_price << '\n';
  }

  return 0;
}