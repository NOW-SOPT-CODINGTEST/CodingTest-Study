#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    if (s.size() == 4 or s.size() == 6)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (!isdigit(s[i]))
            {
                answer = false;
            };
        }
    }
    else
    {
        return false;
    }
    return answer;
}