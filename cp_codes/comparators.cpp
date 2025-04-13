    class cmp{
public:
    bool operator()(pii a,pii b){
        return a<b;
    }
};

less<int> - > ascending order
greater<int> -> descending order
less_equal<int> -> ascending for using like multiset