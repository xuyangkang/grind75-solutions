# [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
## Solution in C++
```cpp
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
```
## 解题思路

本题是“教学关”。括号匹配是计算器（Grind 75 里后面几道的 [Basic calculator](https://leetcode.com/problems/basic-calculator/)）的穷人版，计算器又只是 CS 大课里《编译原理》大作业的穷人版。这里篇幅有限，没有办法概述所有相关知识。但是引用两条有用的知识：

1. 借用编译原理 Tokenizer 的思路，输入的字符串应当被当成一个字符数组而不是一整个串。每个字符应当被当成一个 Token。我们的类对不同种类 Token 进行对应的的处理
2. 借用计算器的解法，计算器需要符号栈和数字栈。这里只需要维护符号栈。见到左括号入栈，见到右括号尝试和栈顶的左括号匹配，匹配成功则消除一对括号，匹配失败则返回非法。

## 实现技巧
### 忘记不确定的运算符优先级，好好加括号
冷知识，&& 的优先级大于 ||，所以这个 is_pair 函数中的括号实际上没有必要。但为什么还是加上了括号呢？代码终究是给人看的，而很多读者或许会搞不清楚。刻意加上括号可以减少给人带来的混乱。
```cpp
bool is_pair(char last_ch, char ch) {
    return last_ch == '(' && ch == ')' 
        || last_ch == '[' && ch == ']'
        || last_ch == '{' && ch == '}';
}
```
### Switch 快于多个 if
使用多个 if 的写法也是正确的：
```cpp
for (char ch : s) {
    if (ch == '(' || ch == '[' || ch == '{') {
        stk.push(ch);
    } else {
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
```
但在 C++ 中，switch 进行一次判断就可以跳转到正确的分支，效率更高。
