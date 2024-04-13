// 1221. [S/W 문제해결 기본] 5일차 - GNS

#include<iostream>
#include<vector>
#include<algorithm>

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

        for(int i=1; i<=len; i++){
            string s;
            cin >> s;

            if(s == "ZRO"){
                v.push_back(0);
            }
            else if(s == "ONE"){
                v.push_back(1);
            }
            else if(s == "TWO"){
                v.push_back(2);
            }
            else if(s == "THR"){
                v.push_back(3);
            }
            else if(s == "FOR"){
                v.push_back(4);
            }
            else if(s == "FIV"){
                v.push_back(5);
            }
            else if(s == "SIX"){
                v.push_back(6);
            }
            else if(s == "SVN"){
                v.push_back(7);
            }
            else if(s == "EGT"){
                v.push_back(8);
            }
            else if(s == "NIN"){
                v.push_back(9);
            }
        }

        sort(v.begin(),v.end());

        cout << "#" << test_case << endl;

        for(int i=0; i<len; i++){
            if(v[i] == 0){
                cout << "ZRO";
            }
            else if(v[i] == 1){
                cout << "ONE";
            }
            else if(v[i] == 2){
                cout << "TWO";
            }
            else if(v[i] == 3){
                cout << "THR";
            }
            else if(v[i] == 4){
                cout << "FOR";
            }
            else if(v[i] == 5){
                cout << "FIV";
            }
            else if(v[i] == 6){
                cout << "SIX";
            }
            else if(v[i] == 7){
                cout << "SVN";
            }
            else if(v[i] == 8){
                cout << "EGT";
            }
            else if(v[i] == 9){
                cout << "NIN";
            }
            cout << " ";
        }

        cout << endl;
	}
	return 0;
}