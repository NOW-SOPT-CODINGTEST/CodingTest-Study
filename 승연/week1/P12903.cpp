#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    if (s.size() % 2 == 0)
    {
        for (int i = s.size() / 2 - 1; i <= s.size() / 2; i++)
        {
            answer += s[i];
        }
    }
    else
    {
        answer = s[s.size() / 2];
    }
    return answer;
}