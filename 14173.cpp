#include <iostream>
using namespace std;

int main(void)
{
    int box1[4], box2[4];
    for (int i = 0; i < 4; i++)
        cin >> box1[i];
    for (int i = 0; i < 4; i++)
        cin >> box2[i];
    int cube[4];
    cube[0] = min(box1[0], box2[0]);
    cube[1] = min(box1[1], box2[1]);
    cube[2] = max(box1[2], box2[2]);
    cube[3] = max(box1[3], box2[3]);
    int length = max(cube[2] - cube[0], cube[3] - cube[1]);
    cout << length * length << '\n';
    return 0;
}