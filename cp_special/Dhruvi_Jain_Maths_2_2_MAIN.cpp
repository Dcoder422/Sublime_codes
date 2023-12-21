#include <bits/stdc++.h>
using namespace std;

// sum to store summation of maximum possible payoff of all configurations
// ct for storing count of configurations

int sum = 0,ct=0;

// recursive function declaration
void Configurations(string s, string l)
{
    if (s.length() < 1){ // new permutation is stored in string l

            string ans = l+s;

            // max_value will store the maximum possible payoff 
            int max_value=0,dollar=0;

            // printing configuration number
            cout << "Configuration " << ct+1 << " : "<<endl;

            // printing configuration
            for(int i=0;i<ans.size();i++)cout << ans[i] << " ";cout << endl;

            // printing payoff, as cards are drawn one by one    
            for(int i=0;i<ans.size();i++){
                 dollar += (ans[i]=='R'?+1:-1);
                 cout << dollar << " ";
                 max_value=max(max_value,dollar);
            }

            //printing maximum possible pay-off
            cout << endl << "maximum possible pay-off : " << max_value << endl << endl; 

            // summation of maximum possible payoff of all configurations
            sum+=max_value;ct++;
        }

        // using unordered set to avoid interation for duplicates
    unordered_set<char> uset;

    for (int i = 0; i < s.length(); i++)
    {
        // checking for duplicates
        if (uset.find(s[i]) != uset.end())
            continue;
        else
            uset.insert(s[i]);

        string temp = "";

        // Algorithm
        if (i < s.length() - 1)
            temp = s.substr(0, i) + s.substr(i + 1);
        else
            temp = s.substr(0, i);

        //recursive call
        Configurations(temp, l + s[i]);
    }
}

int main()
{
    // taking string 

    string s = "BBBBRRRR";

    // for description of output

    cout << "Following line will contain each Configuration," ;
     cout << "\nwith the payoff values, after each card is drawn from the deck,";
     cout << "\nand its maximum possible pay-off.\nThe last line contains expected";
     cout << " pay-off for this game.\n\n" ;

      // executing function

    Configurations(s, "");

    cout << endl << "expected pay-off for this game : " << sum*1.0/ct ;
    return 0;
}

