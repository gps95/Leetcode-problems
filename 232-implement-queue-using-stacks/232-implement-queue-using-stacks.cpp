#include <stack>

class MyQueue {
private:
    int selector;
    vector<stack<int>> vs;
public:
    MyQueue() {
        vs = vector<stack<int>>(2);
        selector=1;
    }
    
    void push(int x) {
        selector= (selector+1)%2;
        vs[selector].push(x);
        vector<int> v;
        int aux = (selector+1)%2;
        while(!vs[aux].empty()){
            v.push_back(vs[aux].top());
            vs[aux].pop();
        }
        for(int i=v.size()-1;i>=0;--i){
            vs[selector].push(v[i]);
        }
    }
    
    int pop() {
        int res = vs[selector].top();
        vs[selector].pop();
        return res;
    }
    
    int peek() {
        return vs[selector].top();
    }
    
    bool empty() {
        return vs[0].empty() && vs[1].empty();
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