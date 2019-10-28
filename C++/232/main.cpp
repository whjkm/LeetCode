#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st1;
    stack<int> st2;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int res = st2.top();
        st2.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int res = st2.top();
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(st1.empty() && st2.empty())
        {
            return true;
        }
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
int main()
{
    return 0;
}
