// 1221. [S/W 문제해결 기본] 5일차 - GNS

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

#define endl "\n"
using namespace std;

int main(int argc, char** argv)
{   
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        string t_num;
        int len;

        cin >> t_num >> len;

        vector<int> v;
        unordered_map<string, int> um;
        unordered_map<string, string> um2;

        um["ZRO"] = 0;
        um["ONE"] = 1;
        um["TWO"] = 2;
        um["THR"] = 3;
        um["FOR"] = 4;
        um["FIV"] = 5;
        um["SIX"] = 6;
        um["SVN"] = 7;
        um["EGT"] = 8;
        um["NIN"] = 9;

        um2["0"] = "ZRO";
        um2["1"] = "ONE";
        um2["2"] = "TWO";
        um2["3"] = "THR";
        um2["4"] = "FOR";
        um2["5"] = "FIV";
        um2["6"] = "SIX";
        um2["7"] = "SVN";
        um2["8"] = "EGT";
        um2["9"] = "NIN";

        for(int i=1; i<=len; i++){
            string s;
            cin >> s;
            v.push_back(um[s]);
        }

        sort(v.begin(),v.end());

        cout << "#" << test_case << endl;

        for(int i=0; i<len; i++){
            cout << um2[to_string(v[i])] << " ";
        }

        cout << endl;
	}
	return 0;
}