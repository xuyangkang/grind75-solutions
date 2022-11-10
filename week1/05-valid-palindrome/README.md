# [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
## Solution in C++
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int l = 0;
        int r = len - 1;
        while (l <= r) {
            while (l < len && !isalnum(s[l])) {
                l++;
            }
            while (r >= 0 && !isalnum(s[r])) {
                r--;
            }
            if (l > r) {
                break;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
```
## 解题思路

这类问题是所谓的 ad hoc 问题，按照题目意思做就行了：给一个字符串，忽略符号空格，对英文字母无视大小写，判断字符串是否是回文。


## 细节实现

### cctype
C++ 从 C 语言里继承了 `#include <cctype>` 头文件，包含了一些常用函数，包括 isalnum，tolower，直接调用，避免重复发明轮子会让代码更好看

### 防止数组下标越界

### 简单与效率的权衡
