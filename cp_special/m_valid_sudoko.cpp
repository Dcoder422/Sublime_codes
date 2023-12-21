#include<bits/stdc++.h>
using namespace std;

    bool isValidSudoku(vector<vector<char>>& board) {
        //rows
        for(int i=0;i<9;i++){
            unordered_map<char,int> m;
            for(auto j : board[i]){
                ++m[j];
                if(m[j]==2 && j!='.')
                    return false;
            } }
        //columns
        for(int i=0;i<9;i++){
            unordered_map<char,int> m;
            for(auto j : board){
                ++m[j[i]];
                if(m[j[i]]==2 && j[i]!='.')
                    return false;
            } }
        //boxes


            //imp 

            
        vector<pair<int,int>> v={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        for(auto k : v){
        	unordered_map<char,int> m;
           for(int i=k.first;i<k.first+3;i++){
               for(int j=k.second;j<k.second+3;j++){
                   m[board[i][j]]++;
                  if(m[board[i][j]]==2 && board[i][j]!='.')
                    return false;  
               }
           } 
        }
        return true;
    }
int main(){
    vector<vector<char>> b={{'5','3','.','.','7','.','.','.','.'},
							{'6','.','.','1','9','5','.','.','.'},
							{'.','9','8','.','.','.','.','6','.'},
							{'8','.','.','.','6','.','.','.','3'},
							{'4','.','.','8','.','3','.','.','1'},
							{'7','.','.','.','2','.','.','.','6'},
							{'.','6','.','.','.','.','2','8','.'},
							{'.','.','.','4','1','9','.','.','5'},
							{'.','.','.','.','8','.','.','7','9'}
							};
         cout << isValidSudoku(b) << endl;
         cout<< "ef";


    }

 
