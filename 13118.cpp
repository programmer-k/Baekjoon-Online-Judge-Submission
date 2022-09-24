#include <iostream>
using namespace std;

int main(void)
{
    int p[4];
    for (int i = 0; i < 4; i++)
        cin >> p[i];
    int apple[3];
    for (int i = 0; i < 3; i++)
        cin >> apple[i];
    
    bool collision = false;
    for (int i = 0; i < 4; i++)
    {
        if (p[i] == apple[0])
        {
            collision = true;
            cout << i + 1 << '\n';
            break;
        }
    }
    if (!collision)
        cout << 0 << '\n';
    return 0;
}