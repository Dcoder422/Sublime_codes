// https://leetcode.com/problems/word-pattern/

#include<bits/stdc++.h>
using namespace std;

    bool wordPattern(string pattern, string s) {

map<char,string> m;
        vector<char> sch;
        vector<string> ss;
        vector<string> v;
        string u="";
        for(auto i:s){
            if(i==' '){
           v.push_back(u);
           if(find(ss.begin(), ss.end(), u)==ss.end())
                ss.push_back(u);
                u="";}
            else
                u.push_back(i);
        }
        for(auto i : pattern){
        	if(find(sch.begin(), sch.end(), i)==sch.end())
            sch.push_back(i);}
        v.push_back(u);
        if(find(ss.begin(), ss.end(), u)==ss.end())
               ss.push_back(u);
        for(auto i : sch)
        	cout <<i << endl;
        cout << endl;
        for(auto i : ss)
        	cout << i << endl;
        cout << endl;
         for(auto i : v)
        	cout << i << endl;
        cout << endl;

        if(v.size()==pattern.size() && ss.size()== sch.size()){
            auto it = ss.begin();
            for(auto i : sch){
                m[i]=*it;
                it++;
            }
             auto itt = v.begin();
            for(auto i:pattern){
                if(m[i]!=*itt)
                    return false;
                itt++;
            }
            return true;
        }
        else return false;}
int main(){
string pattern = "deadbeef", s = "d e a d b e e f";
// "deadbeef"
// "d e a d b e e f"
cout << wordPattern(pattern,s);
}


