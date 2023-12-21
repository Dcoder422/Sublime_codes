// test = operator whether shallow or deep
// public n private in functions



#include<bits/stdc++.h>
using namespace std;

class FrequencyTracker {
    public:

    int *a;
    int *b;

    public :

    FrequencyTracker() {
        a= new int[100001];
        b= new int[100001];
        for(int i=0;i<100001;i++){
          a[i]=0;b[i]=0;
        }
    }
    
    void add(int number) {
        if(b[a[number]]>0)
            b[a[number]]--;
        a[number]++;
        b[a[number]]++;
        // cout << a[number] << endl;
    }
    
    void deleteOne(int number) {
           
        if(a[number]>0)
          { 
            b[a[number]]--;
            a[number]--;
         }
        if(a[number]>0)
            b[a[number]]++;
       // cout << a[number] << endl;
    }
    
    bool hasFrequency(int frequency) {
        return (b[frequency]>0);
    }
};

// /**
//  * Your FrequencyTracker object will be instantiated and called as such:
//  * FrequencyTracker* obj = new FrequencyTracker();
//  * obj->add(number);
//  * obj->deleteOne(number);
//  * bool param_3 = obj->hasFrequency(frequency);
//  */
int main(){

cout << "hello" << endl;
     int number = 2,frequency =2 ;
 FrequencyTracker* obj = new FrequencyTracker();
 obj->add(number);
 obj->add(number);
 // number = 1;
 obj->deleteOne(number);
 bool param_3 = obj->hasFrequency(frequency);

cout << param_3 << endl;

}



#include<bits/stdc++.h>
using namespace std;

class FrequencyTracker {
    public:
    
    unordered<int,int> a,b;
    public :

    FrequencyTracker() {
    
    }
    
    void add(int number) {
        if(b[a[number]]>0)
            b[a[number]]--;
        a[number]++;
        b[a[number]]++;
        // cout << a[number] << endl;
    }
    
    void deleteOne(int number) {
           
        if(a[number]>0)
          { 
            b[a[number]]--;
            a[number]--;
         }
        if(a[number]>0)
            b[a[number]]++;
       // cout << a[number] << endl;
    }
    
    bool hasFrequency(int frequency) {
        return (b[frequency]>0);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */