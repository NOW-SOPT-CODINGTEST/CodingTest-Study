#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.size() == 0)
        {
            st.push(s[i]);
            continue;
        }
        if (st.top() != s[i])
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }
    }
    return st.size() == 0 ? 1 : 0;
}