class Solution {
private:
    bool is_pair(char last_ch, char ch) {
        return (last_ch == '(' && ch == ')') 
            || (last_ch == '[' && ch == ']')
            || (last_ch == '{' && ch == '}');
    }
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char ch : s) {
            switch (ch) {
                case '(':
                case '{':
                case '[':
                    stk.push(ch);
                    continue;
                case ')':
                case ']':
                case '}':
                    if (stk.empty()) {
                        return false;
                    }
                    char last_ch = stk.top();
                    stk.pop();

                    if (!is_pair(last_ch, ch)) {
                        return false;
                    }                    
            }            
        }
        return stk.empty();
    }
};
