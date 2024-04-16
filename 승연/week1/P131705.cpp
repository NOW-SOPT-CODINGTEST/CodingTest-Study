#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number)
{
    int cnt = 0;
    for (int i = 0; i < number.size(); i++)
    {
        for (int j = 0; j < number.size(); j++)
        {
            if (i == j)
            {
                break;
            }
            for (int k = 0; k < number.size(); k++)
            {
                if (i == k or j == k)
                {
                    break;
                }
                if (number[i] + number[j] + number[k] == 0)
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}