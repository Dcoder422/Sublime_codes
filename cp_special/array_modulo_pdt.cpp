// You have been given an array A of size N consisting of positive integers. You need to find and
 // print the product of all the number in this array Modulo 10^9+7.

#include <bits/stdc++.h>

const int M = 1e9 + 7;

using namespace std;


 

{

int n;
cin >> n;

 

int arr[n];

for (int i = 0; i <= n; i++)

{

cin >> arr[i];

}

long long int answer=1;

for (int i = 0; i < n; i++)

{

answer=(answer*arr[i])%M;

}

cout<<answer;

}