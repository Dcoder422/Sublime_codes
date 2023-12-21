#include <bits/stdc++.h>
using namespace std;
int n=10,k=4,free_slot,last_slot;
vector<int> nex(n,-1), front(k,-1),rear(k,-1),v(n);
void enqueue(int qn , int d){
	if(free_slot==-1)return;
	if(front[qn]==-1){
		front[qn]=free_slot;
		free_slot=nex[free_slot];
		rear[qn]=front[qn];
		v[rear[qn]]=d;
	}
	else{
		nex[rear[qn]]=free_slot;
		rear[qn]=free_slot;
		free_slot=nex[free_slot];
		v[rear[qn]]=d;
	}
}
void dequeue(int qn){
	if(front[qn]==-1)return;
	if(front[qn]==rear[qn]){
		nex[last_slot]=front[qn];
		last_slot=front[qn];
		nex[last_slot]=-1;
		front[qn]=rear[qn]=-1;}
	else{
		int t=front[qn];
		front[qn]=nex[front[qn]];
		nex[last_slot]=t;
		last_slot=t;
		nex[last_slot]=-1;
	}
}
int main(){ 
	free_slot=0;
	last_slot=n-1;
	for(int i=0;i<n-1;i++)nex[i]=i+1;
		enqueue(0,1);
		enqueue(1,2);enqueue(1,1);enqueue(0,3);
		enqueue(2,4);enqueue(2,3);enqueue(0,3);
		enqueue(0,3);enqueue(1,3);enqueue(3,6);
		enqueue(0,10);enqueue(1,5);enqueue(3,9);
		dequeue(0);dequeue(0);dequeue(3);dequeue(3);
		int i=0;
		int j=front[i];
		while(1){
			if(j==-1){cout<<-1;break;}
			cout << v[j] << endl;
			if(j==rear[i])break;
			j=nex[j];
		}

}