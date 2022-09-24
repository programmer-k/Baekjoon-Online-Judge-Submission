#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int size1, size2;
set<int> set1, set2;
vector<int> union_result(400000);
vector<int> intersection_result(400000);

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> size1 >> size2;
    for (int i = 0; i < size1; i++)
    {
        int temp;
        cin >> temp;
        set1.insert(temp);
    }
    for (int i = 0; i < size2; i++)
    {
        int temp;
        cin >> temp;
        set2.insert(temp);
    }
}

void Solve()
{
    vector<int>::iterator it1 = set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), union_result.begin());
    vector<int>::iterator it2 = set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), intersection_result.begin());
    cout << (it1 - union_result.begin()) - (it2 - intersection_result.begin()) << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}