#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    while (true)
    {
        string str;
        int age, weight;
        cin >> str >> age >> weight;

        if (str == "#" && age == 0 && weight == 0)
            break;
        
        if (age > 17 || weight >= 80)
            cout << str << ' ' << "Senior" << '\n';
        else
            cout << str << ' ' << "Junior" << '\n';
    }
    return 0;
}