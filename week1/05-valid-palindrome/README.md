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

这类题叫做 ad-hoc 问题。ad-hoc 是拉丁语的 this。一般都是题目定义了某些规则，按规则执行就行了。

本题的题意是：给一个字符串，忽略符号空格，对英文字母无视大小写，判断字符串是否是回文。回文的定义是正着读反着读都一样。常见解法有两种：

1. 首先移除符号空格，并把整个字符串转化成小写，然后判断是否回文
2. 回文的定义是正着读和反着读一样，因此维护两个指针，每次找到正着和反着读对应的字符，并比较是否相等。


## 细节实现

### 简单与效率的权衡

### cctype
C++ 从 C 语言里继承了 `#include <cctype>` 头文件，包含了一些常用函数，比如本题需要用到的 isalnum，tolower，直接调用，避免重复发明轮子会让代码更好看

### 防止数组下标越界
