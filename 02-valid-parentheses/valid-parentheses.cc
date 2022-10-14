class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char pair_of[128] = {};
        pair_of[')'] = '(';
        pair_of[']'] = '[';
        pair_of['}'] = '{';
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
                    char pair_ch = pair_of[ch];

                    if (stk.empty()) {
                        return false;
                    }
                    char top = stk.top();
                    stk.pop();

                    if (top != pair_ch) {
                        return false;
                    }                    
            }            
        }
        return stk.empty();
    }
};
