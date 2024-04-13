#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food)
{
    string answer = "";
    vector<int> v;
    for (int i = 0; i < food.size(); i++)
    {
        if (food[i] == 1)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < food[i] / 2; j++)
            {
                v.push_back(i);
            }
        }
    }
    for (int i : v)
    {
        answer += to_string(i);
    }
    answer += '0';
    reverse(v.begin(), v.end());
    for (int i : v)
    {
        answer += to_string(i);
    }
    return answer;
}