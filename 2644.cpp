#include <iostream>
using namespace std;

int n, person1, person2, m;
int parentInfo[101];

void GetInput()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> person1 >> person2;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        parentInfo[p2] = p1;
    }
}

int GetParent(int person, int& upCount)
{
    upCount = 0;

    while (parentInfo[person] != 0)
    {
        person = parentInfo[person];
        upCount++;
    }

    return person;
}

bool IsParentRelationShip(int parent, int child)
{
    while (parentInfo[child] != 0 && parentInfo[child] != parent)
        child = parentInfo[child];
    
    if (parentInfo[child] == 0)
        return false;
    else
        return true;
}

int FindCommonParentHeight(int p1, int p2, int upCount1, int upCount2)
{
    int cnt = 0;

    for (int i = 0; i < upCount1 - upCount2; i++)
        p1 = parentInfo[p1];
    
    while (parentInfo[p1] != parentInfo[p2])
    {
        p1 = parentInfo[p1];
        p2 = parentInfo[p2];
        cnt++;
    }

    return upCount2 - cnt - 1;
}

void Solve()
{
    int upCount1, upCount2;
    int parentOfPerson1 = GetParent(person1, upCount1);
    int parentOfPerson2 = GetParent(person2, upCount2);

    if (parentOfPerson1 == parentOfPerson2)
    {
        if (IsParentRelationShip(person1, person2))
            cout << upCount2 - upCount1 << '\n';
        else if (IsParentRelationShip(person2, person1))
            cout << upCount1 - upCount2 << '\n';
        else
        {
            int commonParentHeight = (upCount1 > upCount2) ? FindCommonParentHeight(person1, person2, upCount1, upCount2) : FindCommonParentHeight(person2, person1, upCount2, upCount1);
            cout << upCount1 + upCount2 - 2 * commonParentHeight << '\n';
        }
    }
    else
        cout << -1 << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}