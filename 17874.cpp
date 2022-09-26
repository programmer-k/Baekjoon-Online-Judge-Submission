#include <iostream>
using namespace std;

int main(void)
{
    int n, h, v;
    cin >> n >> h >> v;
    int width = (v > n - v ? v : n - v);
    int height = (h > n - h ? h : n - h);
    cout << width * height * 4 << '\n';
    return 0;
}