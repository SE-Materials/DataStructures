stack<pair<int,int>> st;
MinStack::MinStack() {
    while (!st.empty())
        st.pop();
}

void MinStack::push(int x) {
    if (st.empty()) {
        st.push({x, x});
    }
    else {
        st.push({x, min(x, getMin())});
    }
}

void MinStack::pop() {
    if (!st.empty()) {
        st.pop();
    }
}

int MinStack::top() {
    if (st.empty())
        return -1;
    return st.top().first;
}

int MinStack::getMin() {
    if (st.empty())
        return -1;
    return st.top().second;
}


// Another way: 2 stacks

class MinStack {
    
    stack<int> values;
    stack<int> minStack;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }
    
    void pop() {
        if (values.empty())
            return;
        
        int val = values.top();
        values.pop();
        
        if (!minStack.empty() && minStack.top() == val)
            minStack.pop();
        
    }
    
    int top() {
        if (values.empty())
            return -1;
        return values.top();
    }
    
    int getMin() {
        if (minStack.empty())
            return -1;
        return minStack.top();
    }
};

// Another way: 2 stack optimized

class MinStack {
    
    stack<int> values;
    stack<pair<int,int>> minStack;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        if (minStack.empty() || val < minStack.top().first)
            minStack.push({val, 1});
        
        else if (val == minStack.top().first)
            minStack.top().second++;
    }
    
    void pop() {
        if (values.empty())
            return;
        
        int val = values.top();
        values.pop();
        
        if (!minStack.empty() && minStack.top().first == val)
            minStack.top().second--;
        
        if (minStack.top().second == 0)
            minStack.pop();
        
    }
    
    int top() {
        if (values.empty())
            return -1;
        return values.top();
    }
    
    int getMin() {
        if (minStack.empty())
            return -1;
        return minStack.top().first;
    }
};
