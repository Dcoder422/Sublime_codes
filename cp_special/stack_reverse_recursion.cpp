void inbo(stack<int> &s,int d){ //insert bottom
    if(s.empty()){s.push(d);return;}
    int r = s.top();
    s.pop();
    inbo(s,d);
    s.push(r);
}
void my(stack<int> &s){ 
    if(s.empty())return;
    int d= s.top();
    s.pop();
    my(s);
    inbo(s,d);
}
// reverse stack using recursion
void reverseStack(stack<int> &stack) {
    // Write your code here
    my(stack);
}