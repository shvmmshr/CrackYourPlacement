class MyQueue {
public:
    stack<int>* input;
    stack<int>* output;
    MyQueue() {
        input=new stack<int>;
        output=new stack<int>;
    }
    
    void push(int x) {
        input->push(x);
    }
    
    int pop() {
        peek();
        int temp=output->top();
        output->pop();
        return temp;
    }
    
    int peek() {
        if(output->empty()){
            while(!input->empty()){
                output->push(input->top());
                input->pop();
            }
        }
        return output->top();
    }
    
    bool empty() {
        if(input->empty() && output->empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */