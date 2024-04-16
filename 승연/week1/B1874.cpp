#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define ll long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    stack<int> s;
    vector<int> v;
    vector<char> res;
    int N;
    int num = 1;
    int idx = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    while (true)
    {
        while (!s.empty() && s.top() == v[idx])
        {
            s.pop();
            res.push_back('-');
            idx++;
        }
        if (num > N)
        {
            break;
        }
        s.push(num);
        num++;
        res.push_back('+');
    }

    if (s.empty())
    {
        for (char c : res)
        {
            cout << c << '\n';
        }
    }
    else
    {
        cout << "NO";
    }
}
