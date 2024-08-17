class Solution {
public:
    stack<char> * a;
    stack<char> * b;
    bool backspaceCompare(string s, string t) {
        a=new stack<char>();
        b=new stack<char>();
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!a->empty()) a->pop();
            }else{
                a->push(s[i]);
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(!b->empty()) b->pop();
            }else{
                b->push(t[i]);
            }
        }
        if(a->size()==b->size()){
            while(!a->empty()){
                if(a->top()!=b->top()) return false;
                a->pop();
                b->pop();
            }
            return true;
        }
        return false;

    }
};