class Solution {
public:
    void push(int value) {
        myStack.push_back(value);
        if (minValue.empty() || value < minValue.back())
            minValue.push_back(value);
        else
            minValue.push_back(minValue.back());
    }
    void pop() {
        minValue.pop_back();
        myStack.pop_back();
    }
    int top() {
        return myStack.back();
    }
    int min() {
        return minValue.back();
    }
private:
    list<int> myStack;
    list<int> minValue;
};