#include <iostream>
#include <stack>

using namespace std;

int main () {
    string s;
    cin >> s;

    int result = 0;

    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(s[i]);
        else {  
            if(s[i-1]=='('){ 
                st.pop();
                result += st.size();
            } else { 
                st.pop();
                result++;
            }
        }
    }
    cout << result;

    return 0;
}