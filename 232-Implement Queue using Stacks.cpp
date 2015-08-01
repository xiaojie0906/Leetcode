class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        forpush.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        trans();
        forpop.pop();
    }

    // Get the front element.
    int peek(void) {
        trans();
        return forpop.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return forpush.empty() && forpop.empty();
    }
    void trans(){
        if(forpop.empty())
            while(!forpush.empty()){
                forpop.push(forpush.top());
                forpush.pop();
            }
    }
    Queue(){
        
    }
    ~Queue(){
        
    }
private:
    stack<int> forpush;
    stack<int> forpop;
};