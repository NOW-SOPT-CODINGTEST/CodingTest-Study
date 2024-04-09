#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int cnt = 0;
    for (int j = 0; j < s.size(); j++)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if ((st.top() == '[' and s[i] == ']') or (st.top() == '{' and s[i] == '}') or (st.top() == '(' and s[i] == ')'))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        if (st.empty())
        {
            cnt += 1;
        }
        char tmp = s.front();
        s.erase(s.begin());
        s.push_back(tmp);
    }
    return cnt;
}
