class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        int x;
        if (tokens.size() < 2)
            return stoi(tokens[0]);
        for (string i : tokens) 
        {
            if (i == "+") {
                x = num.top();
                num.pop();
                x = num.top() + x;
                num.pop();
                num.push(x);
            }
            else if (i == "-") {
                x = num.top();
                num.pop();
                x = num.top() - x;
                num.pop();
                num.push(x);
            }
            else if (i == "*") {
                x = num.top();
                num.pop();
                x = num.top() * x;
                num.pop();
                num.push(x);
            }
            else if (i == "/") {
                x = num.top();
                num.pop();
                x = num.top() / x;
                num.pop();
                num.push(x);
            }
            else {
                num.push(stoi(i));
            }
        }
        return num.top();
    }
};