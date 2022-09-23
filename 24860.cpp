#include <iostream>
using namespace std;

int main(void)
{
    long long Vk, Jk;
    long long Vr, Jr;
    long long Vh, Dh, Jh;

    cin >> Vk >> Jk;
    cin >> Vr >> Jr;
    cin >> Vh >> Dh >> Jh;

    cout << (Vh * Dh * Jh) * (Vk * Jk) + (Vh * Dh * Jh) * (Vr * Jr) << '\n';
    return 0;
}