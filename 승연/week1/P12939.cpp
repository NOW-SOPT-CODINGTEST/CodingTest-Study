#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s)
{
    string answer = "";
    vector<int> vec;
    stringstream ss(s);
    string s1;
    while (ss >> s1)
    {
        vec.push_back(stoi(s1));
    }
    answer += to_string(*min_element(vec.begin(), vec.end())) + " " + to_string(*max_element(vec.begin(), vec.end()));
    return answer;
}