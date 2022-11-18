#include <iostream>
#include <set>
using namespace std;

int t, k, nums[1000000];
char operations[1000000];

void GetInput1()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
}

void GetInput2()
{
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> operations[i] >> nums[i];
}

void Solve()
{
    for (int i = 0; i < t; i++)
    {
        multiset<int> dualPriorityQueue;
        GetInput2();

        for (int j = 0; j < k; j++)
        {
            //cout << "inner for loop" << endl;
            char operation = operations[j];
            int num = nums[j];

            if (operation == 'I')
            {
                dualPriorityQueue.insert(num);
            }
            else
            {
                if (!dualPriorityQueue.empty())
                {
                    if (num == 1)
                    {
                        dualPriorityQueue.erase(--dualPriorityQueue.end());
                    }
                    else
                    {
                        dualPriorityQueue.erase(dualPriorityQueue.begin());
                    }
                }
            }

            //for (multiset<int>::iterator it = dualPriorityQueue.begin(); it != dualPriorityQueue.end(); it++)
            //    cout << *it << ' ';
            //cout << '\n';
        }

        if (dualPriorityQueue.empty())
            cout << "EMPTY\n";
        else
            cout << *(--dualPriorityQueue.end()) << ' ' << *dualPriorityQueue.begin() << '\n';
    }
}

int main(void)
{
    GetInput1();
    Solve();
    return 0;
}