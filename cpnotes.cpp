//doble click on the file to open more than one file in sublime

ctrl + B - to run

#include<bits/stdc++.h>
using namespace std;
// snippet name --- mycode
// choose for       for 
// for -> for loop snippet 
int main(){
    // use c++14
  
    search here : setprecision 

	//1. basic

	// cout << "Hello";
	// cout << sqrt(16);	
	// cout << "hi" << " " << "my name";

    // 2.variables

    // int a =2;
    // int b=3;
    // int sum = a+b;

    // 3.basic data types

    // char,int , float,double,bool
    // char c= 'a';
    // int a= 3;
    // double b = 3.5;
    // a = 4.5;
    // bool d = false ;
    // bool s = true ;
    // cout << c << " " << a << " " << b << " " << d << " " << s << endl;
    // all numbera
    // 4.endl is newline character, an extra empty character space after output denotes it
    // cin-> after execution shifts control just after the input
    // declare n define a functuion before int main
    // dont use functions with return type as float or double causes precision error 
    
    //strings
    // string str = "hello";
    // string s ;
    // cin >> s;

    // string concat
    // string concat = str + s;
    // cout << str << s<< endl;
    // cout << concat;

    // cin breaks/stops at spaces n new line 
    // cin ignores spaces , doesnt take it as input
    // case sensitive 

    // equal string
    // if(str == s )
    //     cout << "equal";
    // else cout << "unequal";


    // str[0] ='a';
    // cout << str ;

    //string are mutable
    // invalid -> str[0] = "a"; because str[0] is a char type so i cannot assign string to it

    // size of a string
    // cout << str.size();

    // string a;
    // cin >> s>> a;
    // cout << s << " " << a << endl;

    // input a line 
    // string as;
    // getline (cin,as);
    // cout << as;

    //input two lines
    // string as,ss;
    // getline (cin,as);
    // getline (cin,ss);
    // cout << as << ss;

    //imp
    // int t;
    // cin >> t;
    // cin.ignore(); // use this
    // while(t--){
    //     string s;
    //     getline(cin,s);
    //     cout << s << endl;

    // }
    
    //cin ignores newline but getline doesnt , thus it takes its first input as newline

    // both give same result
    // int d,f;
    // cin >> d >> f;
    // cin >> d;
    // cin >> f;
    // cout << d << f;

    //reverse of a string 

    //we should not use this method
    //1. time complexity
    //2. char type is added to string type
    // string s ;
    // cin >> s;
    // string rev;
    // for(int i = s.size()-1;i>= 0;--i)
    //     rev = rev + s[i];
    // cout << rev ;

    // correct method 
    // for(int i = s.size()-1;i>= 0;--i)
    //     rev.push_back(s[i]);
    // cout << rev ;

    // imp
    // input a very big number like 10^100 in form of strings
    // string s ;
    // cin >> s;

    // to print last digit, it will char type
    // cout << s[s.size()-1];

    //this will return ascii of that character
    // cout << (int)s[s.size()-1];

    //to obtain last digit as int
    // int ld= s[s.size()-1]-'0';
    // cout << ld;

    string s = "hdghd";
    // string a = "h";
    // cout << s - a; no such thing is possible

    // push back has void as return type
    // s.push_back('w');<--- only char type is accepted inside the brackets when s is string type
    // cout << s;
    
    // types of array 
    // int , bool , double

    // size of local(either inside main function or any other function)array  
    // is of order 10^5 (as per online coding platforms) and size of 
    // global array is of order 10^7


    // ex for local....this will give segmentation fault
    // int n = 1e7
    // int a[n-1] = 7;
    // cout << a[n-1]; 

    // but this will not..
    // int n = 1e5 ;
    // or
    // int n = 1e7

    // ex for global ( here const is used so that the value of variable remains constant throughout the program)

    // this will give no error
    // const int n = 1e7
    // int a[n];
    // int main(){
    //     a[n-1] = 7;
    //     cout << a[n-1];
    // }

    //return 0 or any number tells the compiler that 
    //the function/program has been successfully executed
    //if even u do not mention it, present compiler assume it automatically

    //no need to define functions just declare it
    //we can not return 2 no.s we can only return a single thing

    // in built functions in c++
    //1.swap(a,b) 2.max(a,b) 3.min(a,b)



    //arrays are always passed by reference (never passed by values) to a function

    //     SORTING 

    //bubble sort-> number of passes = array size - 1
    //bubble sort is not adaptive by default but can be made adaptive

    //intermediate step array of bubble sort can be useful as heaviest element is pushed to end
    //but intermediate step array of insertion sort is not useful .

    // to convert character to uppercase , there is no such function for strings

    //toupper(char ch)

    // cout << tolower('A'); output : 97 

    // a copy of variable is passed to the function in case - func(int a), so that 
    // the actual variable doesnt gets affected , if u wish the actual variable to get 
    // affected by function, use references (addresses) in the argument of function 
    // example func(int &a)

    ex.***** just change argument in the function declaration--> add & 

    void increment(int &n,int n1){
        n++;
        n1++;
    }
    int main(){
        int a=3;
        int b =5;
        cout << a << " " << b << endl;
        increment(a,b); // <-- no change required here
        cout << a  << " " << b << endl;
    }
    output :
    3 5
    4 5

    n is passed by reference and n1 is passed by value

    // we can return only single values by functions 
    // inbuilt functions of c++--> swap(a,b), max(a,b),min(a,b)

    // all data types including string are passed by values if references are not used

    // ex..

    void jk(string s){
        s=" ";
    }
    int main(){
        string s="dffds";
        cout << s <<endl;
        jk(s);
        cout << s <<endl;
    
    }

    output : 
    dffds
    dffds



    // but array is the only data type which is always by default passed by reference 

    // ways : func(int a[])(no need of size at all) ,

     func(int a[10]), func(int n,int a[n])<-- 
    // although y kuch compilers me chl jata hai but y(3rd vala) ek valid tareeka nhi
    // h ki tum ek declared variable ko declaration me use karo

    // for multidimentional array a[][]...1st dimension chod k baki dimension dena 
    // compulsory h...vrna compilation error hota h 

    //func(int m , int n , int a[][m])
    // y ek valid tareeka nhi h isse better agr array ki zarurat lage to 
    //globaly declare karlo....vaise hum jyada arrays ka cp me use krte nhi
 
    // const int N=1e5+10(take array size like this if in ques it is given n<10^5)

    // address of a byte is in hexadecimal (c or c++)
    // *p -> read as -> value at address p

    //cannot globaly declare an array of size more than 10^7 

    //compilation error - wrong syntax

    //memory limited exceeded(mle) - like using array of size 10^8
    
    //runtime error - illegal access of memory 
    // like accessing index more than size of the array(segmentation fault )
    // while using pointers wrongly 
    //4/0 (undefined array)

    //time limit error (tle)- only for execution time not for compilation time 
    //Recursion code error...

    // in online coding platforms --> no. of iterations in 1 sec :
    // 10^7 - 10^8

    // iteration -> execution of a single program statement
    //try to -> O(n) to O(logn)

    // in global array all elements are always initialised to 0

    // in case of prefix sum .... take base index as 1

    // recursion : try to write function in terms of the same function (with a bit change in argument)
    // if operation is written before function call then the order of execution is reverse for the same operation but written 
    // after the function call 

    // best sorting time complexity -> O(nlogn)

     // m= 1e9 + 7 (way of writing)
     //string is mutable data type
     
     // ****strcmp(a,b) to compare two strings also (a==b) *****works*****

     //globally int n ; doesnt work only const int n ; works

     // use sort function of c++ *************

     // *********************  n is the length of array ************************
     // int n = sizeof(arr) / sizeof(arr[0]);
  
    /*Here we take two parameters, the beginning of the
    array and the length n upto which we want the array to
    be sorted*/
    // sort(arr, arr + n);

     // time complexity O((n+m)log(n+m))
// system sort of c++ takes O(nlogn) time
// sort function puts same elememts one after the other

     // array of strings ***********
     // string s[n];

     //pairs
     // class which stores two values
     pair<1,2>
     1 and 2 are data types or containers which you wish to pair
     ex.
     pair<int,string> p;
     pair<int,long long int> o;
     ways of entering value in a pair
     1.
     p=make_pair(2,"abc");
     cout << p.first << " "<<  p.second 
     output : 2 abc
     2.
     p={2,"abc"};

     can copy it like we do for int

     pair<int,string> p1=p;
     p1.first=3;
     cout << p.first ;
     output : 2

     p doesnt change as p1 me p ki copy ja rhi hai

     but if we write 
     pair<int,string> &p1=p;
     p1.first=3;
     cout << p.first ;
     output : 3

     used when two thing have relation and it need to be maintained throughout 

      ex 
      int a[]={1,2,3};
      int b[]={2,3,4};
      like if two values are swaped in a then similar index of b must be swaped
      given a and b are related

      ex.
      pair<int,int> p_array[3];
      p_array[0]={1,2};
      p_array[1]={2,3};
      p_array[2]={3,4};
      swap(p_array[0],p_array[2]);
      for(i=0;i<3;i++){
        cout << p_array[i].first << " " << p_array[i].second << endl;
      }

      output :    3 4
                  2 3 
                  1 2
        take input of pair
        cin >> p.first  ;   


      
     //**** vectors ***
     1.continuous memory blocks
     2.dynamic size(array)
     3.zero based
     //for online programming websites
     4.localy declared vector -> max 10^5 size
     5.globaly declared vector -> max 10^7 size
     6.can directly copy it (not possible in array)

     vector<data_type or containers or pair (anything)>

     ex. vector<int> v;
     currently its size is 0

     ex.vector<int> v={1,2,3};

     ex.vector<int> v(5);
     printVec(v);
     output : size : 5
     0 0 0 0 0
     so vectors are initialised with 0

     v.push_back(7)
     printVec(v)
     size : 6 
     0 0 0 0 0 7

     ex.vector<int> v(5,3);
     all values are initialised by 3
     printVec(v);
     size : 5
     3 3 3 3 3
     v.push_back(7)
     printVec(v)
     size : 6
     3 3 3 3 3 7

     ex.
     vector<pair<int,int>> v;


     input value x :
     v.push_back(x); // O(1)
     vector size increases to 1

     void printVec(vector<int> v){ //here copy of v is passed any changes 
        //made in v inside the function wont be reflected in the actual vector
        // moreover making a copy is expensive here since O(size)
        // hence pass vector references i.e. &v in the functon argument 
        cout << "size: " << v.size() << endl;
        //v.size() -> O(1)
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        }
        cout << endl;
     }

     v.pop_back(); // O(1)
     pops out last value of vector

     ex.vector<int> v;
     v.push_back(7);
     v.push_back(6);
     printVec(v);
     v.pop_back();
     printVec(v);

     output:
     size: 2
     7 6 
     size: 1
     7

     //copy 
     //in array if u try to copy then pointers are passed
     //so if u make any changes in the copy variable same will 
     //be reflected in the original variable 

     //but in vector u get a copy of the orignal vector and any 
     //changes in the copy vector wont be reflected in the orignal vector

     vector<int> v2 = v; // O(size)

     ex.vector<int> v;
     v.push_back(7);
     v.push_back(6);

     vector<int> v2 =v;
     v2.push_back(5);
     printVec(v);
     printVec(v2);

     output:
     size: 2
     7 6 
     size: 3
     7 6 5

     ex.vector of string
     vector<string> v;
     string s;
     v.push_back(s);

     // vector of pair ***** v.useful in cp ********

     vector<pair<int,int>> v = {{1,2},{2,3},{4,5}};
     cout << v[0].first;
     output : 1

     // input pair
     int x,y;
     cin >> x >> y;
     v.push_back({x,y});
     // or in place of { } can use make_pair(x,y)


     //array of vectors

     vector<int> v[10];
     10 vectors ban chuke hai jo 0 size k hai

     //taking value input 


     input :
     3
     3
     1 2 3 
     3 
     3 4 5
     2 
     1 2 

     int N;// no. of vectors in array
     cin >> N;
     vector<int> v[N];
     for(int i=0;i<N;i++){
        int n;
        cin >> n;//size of vectors
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
     }



     for(int i=0;i<N;i++)
        printVec(v[i]);// printing each vector
    //also
    cout << v[0][1];
    is valid --> behaving like a 2d array
    in this no. of rows are fixed but no. of columns in each row are dynamic 


    //for having both no. of rows and column dynamic --->vectors of vectors

    //vectors of vectors ***
    int N;// no. of vectors in vector
     cin >> N;
     vector<vector<int>> v;
     for(int i=0;i<N;i++){
        int n;
        vector<int> temp; // temp vector as v is empty we cannot use v[i]
        cin >> n;//size of vectors
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
     }

     for(int i=0;i<v.size();i++)
        printVec(v[i]);// printing each vector
    //also
    cout << v[0][1]; // valid

    //pushing an empty vector 
    v.push_back(vector<int> ());

    //another way to input 
     cin >> N;
     vector<vector<int>> v;
     for(int i=0;i<N;i++){
        int n;
        v.push_back(vector<int> ()); // temp vector as v is empty we cannot use v[i]
        cin >> n;//size of vectors
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
     }

     iterators are pointers like structures


     //iterators 

     <containers whose iterator u wish to declare > ::iterator it;

     ex.vector<int> ::iterator it;

     it+1 will not work in cases of maps and sets 
     but it++ or ++it is valid for all containers coz
     it+1 points to location just nxt to it 
     but ++it or it++ points to just nxt iterator

     it+1 and it++ is same in case of vectors since continuous memory
     is allocated to vectors

     //special operator used to access pairs in case of iterators
     // can use it or not

     //range based loops work in all containers
     // it in copy of the element is made
     ex.
     vector<int> v={1,2,3};
     for(int value : v){
        value++;
        // cout << value << " ";
     }
     cout << endl;
     for(int value : v){
        cout << value << " ";
     }
     output : 1 2 3

     ex.

     vector<int> v={1,2,3};
     for(int &value : v){
        value++;
        // cout << value << " ";
     }
     cout << endl;
     for(int value : v){
        cout << value << " ";
     }
     output : 2 3 4

     ***********
     //auto assumes datatype dynamicaly*********

     //auto keyword is very useful in case of iterators****

     ***Maps(similar to dictionary in python)
     1.mutable
     2.unique keys are stored
     3.keys are stored in sorted order
     4.time complexity of inserting a single key is O(log(n))
     where n is the present size of the map
     O(nlogn) is time complexity of inserting all pairs in a map
     5.to acess a single key value time complexity is O(log(n))
     6.O(nlog(n)) is the time complexity of accessing the entire map
     7.map elements are pairs 

     //O(n)
     for( auto it : m){
        cout << m.first << m.second ;
     }
     // Accessing values through iterator is a O(1) operation as iterator 
     // has address of the value and access value at some address if you know
     //  the address is a unit time operation. Now when we traverse the map, 
     //  we start from m.begin() and are doing it++ in each step, it++ is also 
     //  O(1) , so whole map traversal is O(1) only. at 11:40 we are not using 
     //  iterators but internally that only is happening, pr is the value at
     //   address pointer by iterator, internally range based loops is also 
     //   iterating through maps using iterators and then providing us reference 
     //   to to the value at that address

     normal(ordered) maps store keys in sorted order
     like if keys are strings then they are stored in lexiographicaly increasing order
     they are implemented using red black trees
     red black tree is a self balancing tree
     maps occupy discontinuous memory space
     map ka har ek element ek pair hota hai

     in maps
     key and value both can be any complex data type or containers


     O(log(n))

     m[key]; // just writing this much has time complexity O(log(n))
     if no value is provided then default values are stored in those keys
        ex. for int double float 0 is stored
    for string empty string is stored, vector -> empty vector

     // has a function .size() , .insert() 

     //mutable 
     m[4]="fdjg";
     m[4]="fjh";
     cout << m[4];
     output : fjh  

     m.find(<key>) returns a iterator //O(log(n))
     ex. m.find(3)
     if suppose the key is not present then it will return m.end()
        generally jitne bhi self balancing trees hote h logn time complexity 
    me hi insertion ,search ....hoti h


    m.erase() // O(log(n)) 
    takes two types of input key as well as iterator
    in erase if u give a iterator that doesnt exist then 
    u get a segmentation fault 

    .find() .size()  .clear() these functions are common 
    and work almost in all containers

    ** insertion time also depends on key 
    like if we have a v.long string as key then complexity wont be log(n)
     it will be s.size()*logn
     s.size() is the size of the string key and n is the size of map

     map can be used in questions where frequency is to be counted
     and conditions are:
     1.-ve numbers also 
     2.no.>10^5
     
     difference between maps and unordered maps 
     1.inbuilt implementation -- uses hash tables (unordered_map) and trees(maps)
     2.time complexity-O(1(average time complexity)) for both insertion and access of a single key
     if hash tables have collisions then time complexity can be bit more
        find() erase() also have O(1)
     3.valid keys data_type

     else everything is same ....function...

     if order of keys doesnt matter in the questions then always use unordered_map as time complexity is less

        in maps we can enter key of any complex data_type
    but not in unordered_maps 

    pair has no inbuilt hash function defined

    hash function is defined inbuilt for
    all basic data_type
    int, long long,double, float... strings

    complex data structures -> set ,vectors, pairs ,set of set dont have hash functions defined

    as map uses comparison hence all data_types are possible

    //multimap

    multimap<pair<int,int>,string> m;
    multimap is similar to map also its implementation is done by using red black trees
    difference is map has unique keys but in multimap same key can be used more than once
    but if we want to store more than one value we can better used
    map<int,vector<string>> m;


    //Set
    normal set
    set stores unique elements in sorted order


    ** for sets use find function as : s.find(x); (most valid)

    insertion and access , .find() ,time complexity : log(n)
    even if u insert same element, more than times , it will be stored only once 

    unordered_set when we dont need sorted order
    // ******** for checking presence ********** 
    we just need to find whether a certain value is present or not
    unordered_set also uses hash tables 
    also we cannot keep complex data_types

    //***multiset **** uses trees

    multiset-> repetition of elements is allowed 
    ***it stores multiples elements in sorted order

    useful inplace of  priority queues
    as priority queues also stores multiples elements in sorted order

    if same multiple values are present then find() returns iterator of 1st value
        .erase(<iterator>)--> O(1)
        .erase(<value>)-->O(logn)
    while comparing two data_types or containers 
    comparision starts from 1st element(ex.0th index in case of vectors are compared)
    bigger the element bigger is the container     

    map of pair as keys is used many times

    ***Stacks***

    its specific ques:
    1.balanced parenthesis 
    2.NGE - Next Greater elements

    LIFO
    can access : 
    1.top element(1.push 2.pop 3.top(to look at the top element))
    2.size

    .empty()

    stack<data_structure> s;
    data_structure : int , double , pair ......



    ****Queue*****
    used in graphs(BFS)

    FIFO

    3 operations in stl
    1.push(added in the end) 
    2.pop(removed from front)
    3.front(to look at the front element)

    sort(address of beginning,address nxt to where to end)
    sorts data_structures such as arrays and vectors

    stl c++ uses introsort -> combination of quick sort , heap sort and insertion sort, nlog(n)

    39 and 40 left and ques using comparator--- try...48 also

    inbuilt comparator function says :
    if u wish to swap return false
    if u dont wish to swap return true    

    trick : jo cheez chahiye usi order mei return kardo  

    some inbiult comparator also exits *******  


    ** Upper bound and Lower bound **
    //both return location of the element
    arrays-> pointer
    vectors-> iterator
    logn

    used v.extensively in cp
    if using for arrays and vectors then they both should be sorted
        in order to have O(logn) otherwise it will be O(n)

    lower bound will find the element , if the element is not present then an element greater than it
    if a number larger than given number doesnt exist then pointer nxt to the largest no. wil be returned(that doesnt exist)
        array-> a+n(a-> array , n -> size)
        vector->a.end()

        if i find lower bound of 5 in {4 5 5 7 8 25}
            then 5 (at position just after 4 is returned)

    Upper bound : even if the element is present it will come up with greater element only

    in case of set and map use differntly
    in case of map it implies only on keys(it comapres only keys)
    both Upper bound and lower bound are possible for pair,string, as they can be compared

    reverse function reverses string , vector n array
    no copy is made ...same vector is reversed

    all_of , any_of , none_of can be implied on array n vector
    
    ***Length of string is mutable can be changed by .push_back;

    Next Greater Element--> que v.imp from cp and interview point of view

    *** if u try to find top element of an empty stack u get segmentation fault

       for(auto s : m)
    ** if m is a map then s is its elements that is s is a pair , to access first element 
    s.first ** no brackets required after .first or .second
 
    // log(base 2)(10^6)=20

    *** for calculating power to a number make ur own function cause pow() returns double value
    inbuilt max() and min() function takes long as arguments as return long

    in unordered set , elements can be in any order , not necessary in which order they are entered , for this reason use vector of pair

    ***** setting precision *****
    // double x = 1.5e9;
    // cout.precision(1);
    // cout << fixed << x << endl;
    // x = 1.5e9;
    // cout.precision(0);
    // cout << fixed << x ;

    // output : 
    //     1500000000.0
    //     1500000000

    **binary

    any number just before 2^x has all 1 1 1......
    ex 1 -> 1
       3 -> 11
       7-> 111

    bit manupulation operations are faster as compared to % / -> slow operators 
    
    XOR

    xor of a binary(0 or 1) with 0 returns the same binary
    xor of a binary with 1 returns the opposite binary

    0^0 = 0
    1^0 = 1
    
    0^1 = 1
    1^1 = 0
    
    subset generation through recursion -> O(2^n)
    subset generation through bit manupulation -> O(n*2^n)

    can declare bool array as bool a[n]
    
    for pre computation based ques take 1 based array

    __gcd(a,b) -> log n , n is max(a,b)  

    ** precomputation and hashing and bit ** v.imp techniques 

    sort() -> O(nlogn)

    int max = *max_element(v.begin(), v.end());

    imp**********************

    avoid using extra array/ vector they may occupy a lot of memory leading to runtime error
    segmentation fault or test cases not passed

    ** for array or vector size ~ 10^7 always declare globally

    global arrays are initialised to default(0)

    ** do not use goto statement

    ** while declaring array globaly both no. of rows and columns should be mentioned

     ** memory limit is v less considered use long long as much u want*****

     ** vectors are dynamic -can be resized
     ** erase() deletes the entire memory space of the element along with it
     ** and also then vector is reindexed******
    
    ** range based loop cannot be used for arrar , as it uses iterators
    but array uses pointers

    ** for sets use find function as : s.find(x); (most valid)
     ** auto it = --m.end(); prefix so that pehle minus ho phir assign ho

     ** string s ; int ma;
     m -> vector
     auto p = make_pair(s,ma);
        m.push_back(p);

        ** awesome feature of vector
        **  vector<int> v(5,0);
    cout << v.end()-(++v.begin());

    output : 4

    ** never use variable name and function with same name 

    ** left XORinacci q.46 in div 2a ladder

    ** for 2D arrays 
    auto ma = *max_element(&arr[i][0], &arr[i][6]);
    ** use & for address , arr+i wont work

    ** for getting a hint to what might be wrong in a test case
    ** chk answer by the judge to other test cases so that u might guess his programs processing


// https://www.hackerrank.com/challenges/recursive-digit-sum/problem

//selection sort


** cin ignores space and new line
** whenever take an input take complete input dont break the loop
otherwise in nxt test case it will continue from the mid of previous input

** in built gcd function = __gcd()
******************************
************
compiler automatically converts binary to int*************** 

int a=9;
(1<<1)|a---> converts to int itself

*** this works
bit 
char A ='A';
char a = A | (1<<5);
cout << a << endl;
cout << (a&(~(1<<5))) << endl;
cout << char('C'|' ');
cout << char('c'&'_');

output= 
a
65
c
C

** for checking power of 2
(n&(n-1))=0

** array of vectors **
vector<int> v[n];

** gcd is also used for calculating minimum fractions
ex. 12/18 -> 2/3 , gcd(12,18) = 6 , 12/6 = 3,,,18/6=3


** comparator function may not work in geeks for geeks

** bit manupulation imp tricks
1.x^x =0
2.x^0=x
~ << >> , right shift for -ve no. returns all 1 from LHS 

3. bit toggle -xor
4.one’s complement of the number :~num
5.Two’s complement of the number :(~num+1)
6.Stripping off(removing) the lowest set bit : X = X & (X-1)
(method also used for counting no. of set bits(c) with O(c))
7.Getting the lowest set bit of a number: X &(-X)
 Let X = 00101100. So ~X(1’s complement) will be ‘11010011’ 
 and 2’s complement will be (~X+1 or -X) i.e.  ‘11010100

00101100
& 11010100
-----------
  00000100
8. Divide by 2 using the right shift operator

00001100 >> 1 (00001100 is 12)
------------
00000110 (00000110 is 6)

9.Multiply by 2 using the left shift operator

10. 2^x by 1<<x;

11. char('C'|' ') -> c

12. char('c'&'_') -> C

13. unset a bit num &= (~(1 << pos));

14. set a bit num |= (1 << pos);

15.Count set bits in integer  
while (x)
    {
        x &= (x-1);
        count++;
    }

16. like x+=1; ...is ... x=x+1;
         x>>=1          x=x>>1;
         also while(x=....) is while(x)
              if(x=....)  is if(x) but RHS of = is evaluated first

          for non zero x->1 else x->0

17. log base 2 of 32 bit integer
int log2(int x)
{
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}

18.Checking if given 32 bit integer is power of 2 
 x & (x-1) = 0

19. Compute XOR from 1 to n (direct method):
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

20.Count of numbers (x) smaller than or equal to n such that n+x = n^x:

count = pow(2, count of zero bits until left most set bit)

21. Find XOR of all subsets of a set
We can do it in O(1) time. The answer is always 0 if the given set has
 more than one element. For sets with a single element, the answer is the value of the single element. 

22.Number of leading zeroes: __builtin_clz(x)
Number of trailing zeroes : __builtin_ctz(x)
Number of 1-bits: __builtin_popcount(x)(no. of set bits)

23.auto number = 0b011;
    cout << number; -> 3

** ** *** 
24. if a number has bits in an alternate pattern
  n ^ (n >> 1) 
  If n has an alternate pattern, then n ^ (n >> 1)
operation will produce a number having all bits set.


//https://www.geeksforgeeks.org/bits-manipulation-important-tactics/#count

*** ****** ****
    inbuilt function ->(int)log2(n);--> for position of max. set bit

    binary to gray code :
    G (n) = n xor (n >> 1)

    **** *** v imp-
    to get a hint to the solution after reading the problem , consider its constraints carefully

    void print_bi(int n){
    for(int i=63;i>=0;i--){
        if((n&(1LL<<i))!=0)cout << 1 ;
        else cout << 0 ;
    }
    cout << endl;
}

when using 64 bit 

        unsigned long long  a=0,b=0;
        unsigned long long  c=1LL;
        (b&(c<<i))
        ******
        *****
        ****
        **
        int x;
        due to implicit type conversion (c<<x)
        is a unsigned long long type

        ** take corner cases -- starting no.s 

        for better underestanding of bit manupulation
            use set theory

******

number theory :

int binExpIter(int a,int b){
    int ans =1;
    while(b){
        if(b&1)ans=(ans*1LL*a)%M;
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return ans;
} //O(logb)

// case 1:

//if a is v.large , a>10^9 , then calculations can also
//not be performed in long long 
// so if a<10^18 then can use a%M else 
// ex. a=2^1024;
// then do a = binExpo(2,1024,M);

// case 2:

// if 10^9 <M < 10^18
// we do binary multiplication

int binExpIter(int a,int b){
    int ans =1;
    while(b){
        if(b&1)ans=binMultiply(ans,a);
        a=binMultiply(a,a);
        b>>=1;
    }
    return ans;
} //O(log^2(N))
long long binMultiply(long long a,long long b,long long m){
    long long ans =0;
    while(b){
        if(b&1)ans=(ans+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return ans;
}

// case 3:
// for b<10^18 just change type of argument to long long
// int binExpIter(int a,long long b){
// b>10^18 ex. b=64^32...using ETF(euler totient function)
// for ex calculate (50^64^32)%M 
// do binEXp(50,binExp(64,32,M-1),M)(if M is prime)

Sieve : works well till N=1e+7;
O(N*log(log(N)))

const int N=1e7+10;
vector<bool> pf(N,1);//initialy considering all as prime factor
vactor<int> lp(N),hp(N);//can also be done in previous vector , instead if bool save lp - lowest prime hp- highest prime



pf[0]=p[1]=false;
for(int i=2;i<N;i++){ //i*i<=N for more optimized code
    if(pf[i]==true){
        lp[i]=hp[i]=i;
        for(int j=i*2;j<N;j+=i)pf[j]=false; // j=i*i for optimization
        hp[j]=i;
        if(lp[j]==0)lp[j]=i;
    }
}

Prime factorization :
vector<int> v;//all factors
unordered_map<int,int> count;//count of pf

for(int i=lp[num];i*i<=num;i++){
        while(num%i==0){
            v.push_back(i);
            num/=i;
        }
    }
    if(i>1)v.push_back(i);


    // OR //

while(num>1){
    int p=hp[num];
    while(num%p==0){
        num/=p;
        v.push_back(p);
        count[p]++;
    }
}    // O(log N)

for ALL divisors:**works for N=1e5+10***
    // can calculate sum of divisors and count of divisors using this method

vector<int> v[N];

for(int i=2;i<N;i++){ //i*i<=N for more optimized code
        for(int j=i*2;j<N;j+=i)v[j].push_back(i);    
}O(nlogn)


Modular Multiplicative Inverse of A=binExp(A,M-2,M) 

ex . nCr%M , k<n<10^6
nCr= n! / ((n-r)!*r!)
int den = (fact[n-r]*1LL*fact[r])%M;
ans = fact[n]*binExp(den,M-2,M);

log(10^5)~16;

*** **** *** *** 
for n =10^6 maximum no. of  distinct primes is 10***


** v v v v imp ***
wrong answer 
runtime time error 

occur often because u havent consider long long***

**** avoid doing operations while taking inputs ***
-***--- can give TLE  ******

*** to find no. of coprimes of n, <n;
---- use ETF ****--------

** v imp ** with floor(), ceil(), trunc(), round() 
i.e 1891232 is output as 1.8912321e+006
** When outputting floating-point numbers, cout has
 a default precision of 6 and it truncates anything after that.
  to provide precision to floating-point numbers : ----
  ** ** *** 
  fixed << setprecision(0) ***

  *** while using ternary operator in cout **
  always put entire of it inside brackets

  in ternary operator both if else should be of same type 
  ex.
  either both cout or both assignment type 
  multiple operations can be performed by using commmas

  when multiple conditions are given with commas only last one is considered

  in c++/c m=2 converts to 2

  ** test all possible cases that come to ur mind 
  ** and force ur mind to think of all other possible test cases 
  ** that may occur


  ** for time complexity of recursion 
  ** total no. of function calls*time complexity of a single function

  ** parenthesis generation & subset generation-> O(2^n)

  ** to remove duplicates in a vector
  ar.erase(unique(ar.begin(), ar.end()), ar.end());



  ** always checkouts editotials even if ur method is short
  ** you may get to know better ways to do it


  ** recursion v powerful...jo dimag karta h vo recursion kr skta h****
  ** chote constraint => recursion

  vector<int > v =p ; -> O(n)

  if 1<=n <= 30 then time complexity of question 
     can be O(2^n) --- > hint to recursion

*****
****
***
** whenever get an error first chk whether u need to consider long long


**The sum of n over all testcases doesnt exceed 2*10^5 then O(n^2)will give TLE


** first chk if there is an overflow then chk logic

**** v.end() is excluded from vectoe it doesnt point to any value 

**** always try your code for atleast two test cases

*** tricks for binary search
***
jise maximum ya minimum krne ki baat ho rhi ho
vhi search space bnta h (lo , ji, mid)

*** function accumulate sums all number in a vector


** imp 
vector<vector<int>> g(N); // N - no. of rows

*** no of rows and columns for 2D vector:
int rn=grid.size(); rows
    int cn = grid[0].size(); columns

***** void dfs(int vertex,int par=0)----this is how default 
value is set in a function
dfs(1) will not give an error since default value is given 
par will be 0 unless u give 2nd argument to the function like dfs(1,2)    

Trees and Graphs :

Tree is a graph with no cycles
in trees , n nodes , n-1 egdes
        
        acyclic undirected graphs - trees

leaf node - having no child

depth of a node - its distance from root of tree
height of a node - its maximum distance from a leaf node
LCA - lowest common ancestor

maps can have 1e5 or v.more abt 1e7 keys even in local variable
bcoz this is non continuous memory allocation
in case of continuous memory allocation maximum allocation
can be globaly of 1e7 elements

in bfs at a time ,,nodes of atmost two levels can exist in the queue 

****** DP ******
changing parameters are states of DP
1. brute force recursion
2.memoization

memset(dp,-1,sizeof(dp));
dp -> array

in dp no. of recursion call = no. of states
1D  dp[N]-> N
2D  dp[N][M]-> N*M

dp/binary search 

knapsack - from a given no. of elements choose sum elements
based on some condition
1.start from last
2.choose or leave that element based on condition
3.write brute force
4.memoize(dp)

subsequence order of elements needs to be same  , 
elements need not be continuous

***
first try top down(generally recursion) approach
then go for bottom up (generally iterative) approach

****** general *********
be careful - > whether u have to maximize product and then calculate its modulo
or first u have to caluculate modulo of a product and then maximize it


1.
ans = max(ans, a*b);
return ans % M
2.
ans = max(ans,(a*b)%M)
return ans;
********************************************
********************************

both are different and will give different answers
So be careful


********* *** *** ** *** * * * * * * * * * **  vvvvvvvv imp
*****
if an global array or vector is used in a test case 
and its initial value is being used(mostlty 0 , since global array n vectors are initialised with 0)
then always at the end of every test case initialise the array / vector again

**** *** * * * ** * * *v v v v v   imp
** in case of long long use accumulate(v.begin(),v.end(),0LL);vector<long long> v;

*** whenever u r asked to only write function
dont make global variables
vector array in argument is written as(already passed by reference as it is a array)
void xvgb(vector<pair<int,int>> g[])

where s is multiset 
s.erase(a); erases all a from set a
s.erase(s.find(a)); erases only a single value a

memset is used only on arrays

subarray - continuous
subsequence - may be continuous/discontinuous
 series of elements from an array such that their 
 order remain the same.
 subset - includes some element of the array in any order

if func1() is called in func2() then func1() should 
    be called before func2()
*** imp**
converting array to vector 
vector<int> prices(price,price+n);

dp imp time complexity
1.frog 1 O(n)
2.frog 2 O(n*k)
3.longest increasing subsequence O(n*n)
4.Coin change 1 O(S*n)
5.Coin change 2 O(S*n)
6.0-1 knapsack O(n*weight)
7.Rod cutting O(n*n)
8.Subset Sum / Partition sum O(sum*n)
9.Longest Common subsequence O(len1*len2)


O(logn)--> hint --> binary search


OOPs -:
class - user defined data type
object- instance of a class has properties and behavior
empty class - 1byte
Access MOdifier 
public - can be accessed anywhere within the program
private - by default(can be accessed only within the class)
protected-


things written below public can be accessed anywhere within the program

ex. class Hero{
    public :
    int health;
    char level;

    void gethealth(){
        return health;
    }
}

static allocation :
int i ;

Hero a;
cout << a.level;
cout << a.gethealth();

dynamic allocation :
int *i = new int;(in heap memory )

Hero *b = new Hero;
(*b).health
or
b->health

inheritance is possible in class(i.e sub class)
but not possible in structures(struct)

class - members private by default
struct - members public by default



***** very effective -> two pointer approach *****

** way to declare multiple pointer variables
struct Node *p0,*p1,*p2;
free() to delete a node;

in stack top pointer is like head pointer of a linked list

It is not dynamic i.e., it doesn’t grow and shrink depending on needs at runtime

binary tree having elements if any data type 
as per defined by the user,,,,,
****
template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
}        

for using maps like m[i][j]
do like map<int,map<int,int>> m;

** Hashmaps **
bucket array -> value array

Hash functons -> 1.hash code ->conversion to integer
                             ->uniform distribution (N is a good prime no. for uniform distribution)
              -> 2.compression function(compresses int within the range %N)

Collision Handling 
-> open hashing-same plase pr hi jao - separate chaining is effective in uniform distribution
-> closed addressing              

see from love babbars slide

int hash[maximum + 1] = { 0 }; 

code force - 2*10^5 => do in O(n),,,nlogn also works, but it is on margin 
even 1 xtra O(n) loop may give tle in case of O(nlogn)code

To be divisible by 4, the number has to end with the last two digits forming a number divisible by 4.

//this works
for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){

            // ****
            string t;
            cin >> t;
            v[i].push_back(t);

            //*****
            cout << v[i][j] << " ";
        }cout << endl;
       } 

       // this doesnt
for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){

            // ****
            cin >> v[i][j];

            //*****
            cout << v[i][j] << " ";
        }cout << endl;
       } 


******

 ****

 first chk ur algo on all test cases then only 
 implement otherwise its a waste of time
 dont just start writing code after seeing few test cases 
 chk all

 adha parda question mat pado its more
 wsate of time /// plsssssss

** **** ***** ***
 when question is on sub arrays -- try two pointers approach

 for finding intersection of intervals we make pairs
    of start n end n then sort


** 
struct my_struct{
    int a;
    int b;
    my_struct(int x, int y): a(x), b(y) {}
};

int main(){
    my_struct st(2, 5);
    cout << st.a << " " << st.b << endl;
    return 0;
}

This will initialise the value of a with 2 and the value of b with 5.


**
creating a function pointer is,

return_type (* pointer_name) (datatype_of_arg_1, datatype_of_arg_2, ...);
https://www.scaler.com/topics/can-we-declare-function-inside-structure-of-c-programming/


** 
arr1.swap(arr2)

8! is border case for permutations (including sets)
9! gives error (including sets)

****
***
** through recursion for 9! permutations it is not possible
to print all permutations in lexiographicaly order using any 
data structures(set or any other)


**
  ListNode *left1,*right1;


  ****

  stoi()-- string to integer("23"-23)
  to_string()===(23-"23")

  stack is used for both
  1. evaluating postfix notation from inorder notation of an arithmetic expression 
  2. computing postfix notation(i.e evaluating int ans of the postfix notation)

  Note - inoder arithmetic notation cannot be evaluated directly
  it is first converted to its postfix notation(using stack) , then postfix notation
  is evaluated(using stack) to give final answer

  both are evaluated by traversing array from front(0 index)


** if ans goes to long long consider variable to be long long 
rather than multiplying it by 1LL

****
 in switch case

 switch(i[0]){
                case '+': s.push(a+b);break;-- here break is v imp
                case '-': s.push(a-b);break;
                case '*': s.push(a*b);break;
                case '/': s.push(a/b);break;
            }
without break we are getting wrong answer

string s="hfdfg";int i=0;
    while(s[i]!='\0'){
        cout << s[i] << endl;
        i++;
    }

    * ****
    string is a char array ending with '\0'

    str.find('5') returns index of the element

    for data structures that uses trees
        : a: map,multimap , set,multiset;
    a.upper_bound(), a.find() (in maps compares only keys )

    in case of arrays n vectors they should be **sorted** compulsorily 

    **************************************************************
   always time complexity of lower_bound n upper_bound is O(logn)


   mostly used :
   a: any data structures
   a.erase(iterator);

   agr koi question normally smjh na aye -- always think for stack approach it may exist***********

   all functions related to vectors
   https://www.educba.com/c-plus-plus-vector-functions/

   ** non zero = true 
   ** zero = false

   dp:
   1.count total no of ways 
   2. there are multiple ways whuich gives min n max
   3. try all possible ways

   question says - today the person cannot repeat an activity he did yesterday
   can be interpreted as - the activity the person did today was not done yesterday
   https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

   *** vector<vector<int>> dp(n,vector<int>(4.-1));
   initialing 2D array

   ** v v imp for 2D dp
   https://youtu.be/ngCos392W4w

   ** nice que 
   https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbnlfM2lIbUVjWjBRWWRrenpTaUozZ05KaVNLQXxBQ3Jtc0tuLWlWdnV2cU15azVLdVlfVHhwNnZJQ3F0dEo2SU9TMTFKNmlmX3oxU0I5MFJUNUptVUJBaUYwTVZNLUhHZkR6amtCUHY4bzMzVlpqdVFCeG41ZWpib3h0WW04RkNDVGRxdDJpM3pJNVR6REdMUnRTQQ&q=https%3A%2F%2Fbit.ly%2F3F6q83P&v=3WaxQMELSkw

*****
no. of variable parameters of recursion = no. of states of dp

subsequence - order has to be followed(comtinuous or non continuous part of array)
subset - can be empty also (as per que)

empty string is a subsequence as well as subset

heap or priority queues - used to find min in O(1)
build-heap -O(n) n-total no. of nodes

**** index based comparision of elements - use merge sort

** n*a[i] total is less than 1e9 these constraints show summation (prefix sum )
may be a solution
1 <= n <= 1e4
-1e5 <= a[i] <= 1e5

we can compare two queues like this:
(q2 == q1)


int charCounts[MAX_CHAR]
        = { 0 }; // Initialize an array to keep track of
                 // character counts

 **
 to chk whether str2 is a substring of temp or not
 (temp.find(str2) != string::npos);

 'and' works in c++


 O((logn!))= O(nlogn) 

 total time complexity of recursion =
 total no of function calls * time complexity of a single function call

 time complexity of find() in unordered_set is O(1)
 unordered - > Hashmaps   

 pointers always passed by values
 int my(Node * p) == copy of p is made for func

 for stack clear func doest exist s.clear()XX

 *** imp ***
 for binary search take hi-lo>1 in cases like hi = mid -1 , lo=mid****
 ***
  , hi>lo if for cases when 
 both hi=mid-1 n lo=mid+1

prefer taking hi-lo>1

****** 
dont submit answers without dry run

never change/update/edit of dp states inside the function
it will surely give wrong answer as some ans wiil be aaved to some other states
not the one it has been obtained from

map_name.erase(key)

***
*
*

**

unordered_map -- > can be a reason of tle , prefrer using vector of max size

*******
__builtin_popcount(int number);   O(1)****

write 1LL or 0LL in the starting of expression

for performing the same task 
if all elements are diff - use map,set
    else use heap;
avoid multimap - it may cause headache in balancing repetetive cases
heap func - all similar to stack


***
in multimap m[i] does not work

** by default in maps and multimaps only **keys** are sorted
never by value

avoid using multimap n multiset better use vectors

many times tle may come bcoz of using some data str,heap, unordered map etc
as builtind them and allocating memory may consume much time and result in tle 
(vector is best as memory is allocated localy)

*****

read the questions and their output format v v nicely
and before submitting read the ques n its constraints once more


even using more space can give TLE


unique() removes duplicate elements only when they are consecutive

 BinaryTreeNode<int>* no = new BinaryTreeNode<int>(str[0]-'0');

 creating maps may give tle be cautious

 Unordered Map does not contain a hash function for a pair like it has for int,
  string, etc, So if we want to hash a pair then we have to explicitly provide it with a hash function that can hash a pair.


  nulls are v imp in specifying a b tree

  m.find(v) for all unordered and ordered map n set

  v v v imp********
  *****

  given graph may have un connected components hence chk every node


  string s = "xbv";
    string a = s+"bvjbf";
    s doesnt change by this

    most imp in dfs n bfs - vis array 

    give time to understanding the ques properly dont hurry in underestanding it 
    otherwise  whole hard work will go in vainS

    unordered_set.erase(b)  - no error if b was not present

    **
    shortest path - from a source node
    topo => directed
    mst = minimum spanning tree

    Dijkstra - directed graph - non-negative weights  - bfs using priority queues 
    shoetest path in negative weighted DAG - topo + traverse each topo node and update its child 
    mst - for a weighted, connected, undirected graph:
    kruskals algo - for mst - dsu
    prims algo - for mst - key , mst , parent 

    topo sort - dfs - Stacks
    topo sort - bfs - indegree array (kahn)
    cycle detection - undirected - dfs/bfs 
     cycle detection - directed - dfs - vis , dfs vis
     cycle detection - directed - bfs - topo sort (for DAG)Directed Acyclic Graph (DAG)[topo.size()!=n, only
      works for topo found using this algo(bfs), topo found using dfs for the same graph may have size==n]
    
    for undirected connected graph  :
     bridge/articulation points - disc , low, par , vis 
     
     kosaraju - strongly connected compo- topo sort(way of stacks (using dfs only(not bfs))) - transpose - dfs 
     
     bellman ford - shortest path with negative weights-negative cycle detection -- n-1 times - DAG(convert undirected to directed)
     floyd warshall - all pair shortest path - dp - DAG(negative weights but no negative weighted cycle)


e Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not
Delete can be used by either using Delete operator or Delete [ ] operator
New operator is used for dynamic memory allocation which puts variables on heap memory.
Which means Delete operator deallocates memory from heap.
Pointer to object is not destroyed, value or memory block pointed by pointer is destroyed.
The delete operator has void return type does not return a value.


Flatten binary tree to linked list only possible for preorder morris traversal

morris traversal can give inorder but cannot flatten in inorder
 to flatten in inorder use reverse inorder traversal


 **** Reverse Inorder Traversal ***

 void populateNextRecur(Node *p, Node **next_ref)
    {
        if (p)
        {

            populateNextRecur(p->right, next_ref);

            p->next = *next_ref;

            *next_ref = p;

            populateNextRecur(p->left, next_ref);
        }
    }

    void populateNext(Node *root)
    {

        Node *next = NULL;

        populateNextRecur(root, &next);
    }


    segmentation fault -> avoid using stack space do iteratively

***************** ******** ******* 
    // imp observation contruction of a normal binary tree 
    of the same element depends on the order they are inserted

    hence in question realted to order(index) it can be used

    1 2 3=>
    1
     \ 
      2
       \
        3

2 1 3 = >    
   
   2        
 /   \
1      3

preorder traversal - (bst to ll) - morris traversal
inorder traversal - (bst to ll) - reverse traversal

merge two ll - is done by recursion not like we do for arrays

int *arr;
    int size;
    int top1, top2;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 

*** infix to postfix for arithmetic expression evaluation

** switch case cannot be applied to strings;

NStack(int N, int S)
    {
       arr = new int[S];
        
    }      

learn -> 2^20 = 10^6

in 2D array no. columns should be mentioned

For M to be a prime number is really important. Because if it is not a prime number then it is possible that the result of a modulo operation may become 0. Eg. if M=12 and we perform ( 8 * 3 ) % 12, we will get 0. But if M is prime then ( ( a % M ) * ( b % M ) ) % M can never be 0 (unless a or b == 0)
If M is prime then we can find MMI for any number n such that 1<=n<M    


prims algo reason for taking min of key is that the connection with the node recently marked 
visited is confirmed by that min weighted edge(it is confirmed as a parent of another edge )if this procedure is not followed 
the wrong parent my be assigned and graph may not be connected , not be even a tree  

directed graph - topo sort

kosaraju why to transpose graph proof , and not simply do reverse topo traversal

// For all those who are wandering why is it important to transpose the graph...
// Consider this graph
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4
// Now if you print the topo sort   you get
// 0
// 3
// 4
// 2
// 1
// After reversing the stack if you try you get 1 2 4 3 0 if you try to do dfs from 1 you will reach 0 3 4 in one move which makes 1 0 3 4 a strongly connected component giving you count=1 instead of count=3

graphs most imp - vis array

mini moves or shortest path to reach des from source always - bfs

**** v v v v imp ***
in questions where need to write entire code not function do cout instead of return :)

in case of arrays always use this way to initialise
int vis[m+1][n+1];
       for(int i=0;i<m+1;i++){
           for(int j=0;j<n+1;j++){
               vis[i][j]=0;
           }
       }

       not - vis[n][m]={0} 

O(N)- 1D dp

read n understand test cases v nicely 50% of the que can
be understood with the help of test cases

dry run on test cases is v imp

1 sec = 1e8 (but try to keep it less than 1e7)

*** in unordered_maps n unordered_set
key has to be of predefined data structures like 
whose hash functions are predefined
int , char , string , pointers ....
only but for map value can have any data structure
like pair,vector 
even user defined like tree node will work

**
(a + b) mod m = ((a mod m) + (b mod m)) mod m 
(a + b + c) mod m = ((a mod m) + (b mod m) + (c mod m)) mod m 
(a-b) mod m = ((a mod m) - (b mod m) + m) mod 

imp - (21-7+9)%4

generally - take max as ~10^6

learn
    // cout.precision(1);
    // cout << fixed << x << endl;
struct TrieNode* p = (struct TrieNode*)malloc(sizeof(struct TrieNode));
not imp new works 

time complexity of s.substr() is O(n)

// return cout<<"No",0;

stl ko pair ko sort krna ata h map krna nhi ata
// count(all(a),maxi) 

******
When comparing signed with unsigned, the compiler converts 
the signed value to unsigned. For equality, this doesnt
matter, -1 == (unsigned) -1. For other comparisons it 
matters, e.g. the following is true: -1 > 2U.

** hence this will not throw an error since .size() return_type is unsigned integer

int p=-1;
for(int i=p;i<s.size();i++)
    s[i]='0';
A signed integer is a 32-bit datum that encodes an integer in the range 
[-2147483648 to 2147483647]. An unsigned integer is a 
32-bit datum that encodes a nonnegative integer in the 
range [0 to 4294967295].


**
auto fir = [&target](int x){return x<target;};

binary search imp->
lower_bound,upper_bound , partition_point

in ques - find max , min take hint - may be binary search

(x < v * M ? R : L) = M;
The hypot() function in C++ returns the square root of sum of square of
arguments passed. It finds the hypotenuse, hypotenuse is the longest side of a right angled triangle.

**********
*******
******
nice optimization for binary search ***** no need to think for upper n lower_bound

int l = - 1; // bad
    int r = 1;  // good
    while (!isGood(r)) {
        l = r;
        r *= 2;
    }

int balloons = z[i]*time/(t[i]*z[i]+y[i]) + ...

The right formula must be reordered, or add a bracket to it: int balloons = (time/(t[i]*z[i]+y[i])) * z[i] + ...

This is because, given 3 integers a, b, c, we have a * b / c != b / c * a. E.g: 2 * 5 / 3 = 3, while 5 / 3 * 2 = 2

substring

****
#define eps 1e-13
keep bigger range of eps in questions 
where a sequence of steps need previously 
calculated value 
in this case error increases with each step
so keep precision high initially

** use directly without including !s.empty() && s.find(a)!=s.end();
set<int> s
a=*s.begin(); // doesnt give error if s is empty
s.erase(b); // or b is not present in s

4-connected region: from a given pixel you can get to any other pixel in the region by a series of 4 way moves (up, down,left, right)

*** pro tip ***
always print to see whether code is 
working desired way

if(s.find('m') != -1 || s.find('w') != -1)
        return cout << "0\n", 0;

    class cmp{
public:
    bool operator()(pii a,pii b){
        return a<b;
    }
};

https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/

*** vvvimp ***
coud(ans,6); - whenever says precision upto 10^-6
string(n,'b') -> bbb......ntimes

when que says half - without clarity take - (n/2 +(n&1))

The difference between maximum and maximal is subtle. A maximum
 element must be larger than (and hence comparable to) every 
other element of A, while a maximal element must only be larger 
than every other element of A to which it is comparable

The rule for divisibility by 9 is similar to divisibility 
rule for 3. That is, if the sum of digits of the number is 
divisible by 9, then the number itself is divisible by 9.

evenly divided---->>> remainder==0

https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwjL34TDt9qBAxVhwzgGHUigDWUQFnoECBAQAQ&url=https%3A%2F%2Fwww.geeksforgeeks.org%2Fcomma-in-cpp%2F&usg=AOvVaw0nTVMwNGmjFMM2Wl0f8W7w&opi=89978449

**** vv v v v v imp ****
memory limit-256 megabytes- 3*10^7 + x (x is v small compare to 10^7)
stack space even much much smaller - use iterative soln as much as possible 
as function calls also occupy space

dont use -ve index always for pre computation ques use 1 based indexing

dp can be made simple only when we consider 
cases which are impossible or will never yield 
the optimal answer ... let them be there ...
obviously they will never contribute to answer
but will make code easy ...

//The time complexity of cout is O(1).

The erase operation on a string and vector, when given
 an iterator to the character to be erased, has a time complexity of O(n),


**** time complexity of these loops is O(nlogn) *****
 for (i = 1; i <= n; i++)  //loop from 1 to n
   for (int j = i; j <= n; j += i)  //iterating through all multiples of i that are at most n

binary search :
min(max(…))
we set variable(x) as the upper limit---> abc<=x
max(min(…))
we set variable(x) as the lower limit---> abc>=x
** when two variables are given and one has a limit 
in the ques then the one with limit is to be calculated in
pred while the other is binary search variable

for sorting in descending order
sort(c,c+n,greater<long double>());

all bitset operations time complexity ->O(size/32)
or,xor,right shift,left shift

1 sec<10^8


***
The median minimizes the sum of absolute deviation
in even length can take any of the two

***
if (a-b)&m==0 => a%m == b%m


 two pointer 
at starting r=l-> search for good/bad segments
at starting l=0,r=n-1-> trying to converge to a target
in this... moving one pointer increases the value while the other decreases
that is moving of both pointers has opposite effect on the value

example finding a pair to get a desired sum

always consider repetion of no.s if it is possible

If the last three digits of a number are divisible by 8, then the number is completely divisible by 8


for only segtree where its associative and order of elements does not 
affect the answer - there u can make tree of size 2n 
:-
For(i,0,n){
    in x;
    tree[n+i]=x;
}
but where answer changes with order of elements(diff ans for diff permutations)
there tree size -> 4n

k=1;
while(k<n)k*=2;
tree[2*k];
For(i,0,n){
    in x:
    t[k+i];
}


*****
****
***
*

map<int, int> freq;
    for (auto [p,f] : freq) {
        sum += ((f - 1) * f) / 2;
    }

std::map is a self ordering red black tree(doesnt use hash table)-O(logn)
std::unordered_map uses a hash table
std::unordered_map-the worst-case complexity is O(n^2)

hence wherever possible prefer using map(not unordered_map)


***
.rbegin() -> pointer to last element of the container
rbegin()==(--.end()) 


1e9-in 30 bits


*** never use ceil - better use it like this->
ceil(a/b)=(a/b)+(a%b!=0);
ceil(pow(n,0.5)) = pow(n,0.5) + ((int)pow(n,0.5)*(int)pow(n,0.5)!=n)


****
in graphs alsways consider a case - if its disconnected

