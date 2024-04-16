using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long charge = 0;
    for (int i = 1; i <= count; i++)
    {
        charge += price * i;
    }
    if (money - charge < 0)
    {
        answer = -(money - charge);
    }
    else
    {
        return 0;
    }
    return answer;
}