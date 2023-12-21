#include <bits/stdc++.h>
using namespace std;
int sum = 0,ct=0;
set<int> se;
void Configurations(string s, string l)
{
    if (s.length() < 1){
            string ans = l+s;
            int max_value=0,dollar=0;
            cout << "Configuration " << ct+1 << " : "<<endl;
            for(int i=0;i<ans.size();i++)cout << ans[i] << " ";cout << endl;
            for(int i=0;i<ans.size();i++){
                 dollar += (ans[i]=='R'?+1:-1);
                 se.insert(dollar);
                 cout << dollar << " ";
                 max_value=max(max_value,dollar);
            }
            cout << endl << "maximum possible pay-off : " << max_value << endl << endl; 
            sum+=max_value;ct++;se.insert(max_value);
        }
    unordered_set<char> uset;
    for (int i = 0; i < s.length(); i++)
    {
        if (uset.find(s[i]) != uset.end())
            continue;
        else
            uset.insert(s[i]);
        string temp = "";
        if (i < s.length() - 1)
            temp = s.substr(0, i) + s.substr(i + 1);
        else
            temp = s.substr(0, i);
        Configurations(temp, l + s[i]);
    }
}

int main()
{
    string s = "";int n=2;
    for(int i=0;i<n;i++)s.push_back('B');
    for(int i=0;i<n;i++)s.push_back('R');    
    // cout << "Following line will contain each Configuration, \nwith the payoff values, after each card is drawn from the deck,\nand its maximum possible pay-off.\nThe last line contains expected pay-off for this game.\n\n" ;
    Configurations(s, "");
    // cout << endl << "expected pay-off for this game : " << sum*1.0/ct << endl ;
    for(auto i : se)cout << i << endl;
    return 0;

}

