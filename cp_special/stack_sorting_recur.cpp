void ins(stack<int> &s,int d){
    if(s.empty()){s.push(d);return;}
    int t = s.top();
    if(d>=t){s.push(d);return;}
    else{
        s.pop();
        ins(s,d);
    }
    s.push(t);
}
// 9 3 -7
void my(stack<int> &s){
    if(s.empty())return;
    int r=s.top();
    s.pop();
    my(s);
    if(s.empty()){s.push(r);return;}
    ins(s,r);
}