using int64 = int64_t;

class Solution {
private:
    int to_int(const string &s) {
        int tmp;
        sscanf(&s[0], "%d", &tmp);
        return tmp;
    }
    int64 eval(int64 a, int64 b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int64> num_stack;
        for (const auto &token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int64 a = num_stack.top();
                num_stack.pop();

                int64 b = num_stack.top();
                num_stack.pop();

                num_stack.push(eval(b, a, token[0]));
            } else {
                num_stack.push(to_int(token));
            }
        }
        return num_stack.top();
    }
};