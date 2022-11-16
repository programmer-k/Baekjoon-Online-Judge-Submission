#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
map<string, int> speciesCount;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string species;
        cin >> species;
        speciesCount[species]++;
        //cout << species << ": " << speciesCount[species] << '\n';
    }
}

void Solve()
{
    string maxSpecies;
    int total = 0, maximum = -1;
    for (map<string, int>::iterator it = speciesCount.begin(); it != speciesCount.end(); it++)
    {
        if (it->second > maximum)
        {
            maximum = it->second;
            maxSpecies = it->first;
        }
        total += it->second;
    }

    if (maximum > total - maximum)
        cout << maxSpecies << '\n';
    else
        cout << "NONE" << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}