#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int maxNum = 0;
    int maxIdx = 0;
    vector<int> vec(26, 0);
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //    input
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        int idx = 0;
        if (isupper(str[i]))
        {
            idx = str[i] - 'A';
        }
        else
        {
            idx = str[i] - 'a';
        }
        vec[idx]++;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > maxNum)
        {
            maxNum = vec[i];
            maxIdx = i;
        }
    }
    sort(vec.begin(), vec.end());
    if (vec[24] == vec[25])
        cout << '?';
    else
        cout << alpha[maxIdx];

    return 0;
}
