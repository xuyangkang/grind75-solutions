# [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

## Solution in C++
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_seen = prices[0];
        int ans = 0;
        for (int p : prices) {
            if (p - min_seen > ans) {
                ans = p - min_seen;
            }
            if (p < min_seen) {
                min_seen = p;
            }
        }
        return ans;
    }
};
```

## 解题思路

### O(n^2) Brute-Force

显然有 O(n^2) 的两层循环枚举解法，但是对 n = 10^5 是过不去的

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};
```

### 动态规划？不，只需要数学变形

很多人认为这是动态规划的第一题，但本题还没有逃离数学变形的范围。暴力求解法相当于对所有i<=j，找到最大的 p[j] - p[i]

$$ans = \max\limits_{i \leq j}\({p_{j} - p_{i}}\)$$

假设我们固定 i，令 p[i] 为常数 c，可以进行数学变形：

$$\max\limits_{i \leq j}\({p_{j} - c}\) = \max\limits_{i \leq j}\({p_{j}}\) - c $$

这个数学变形的意思是：p[j] - c, p[j+1] - c ... p[n] - c 的最大值，等于 p[j], p[j+1], ... p[n] 的最大值 - c

因此可以预处理一下最大值的后缀，然后减少一个循环，这个题目就做出来了。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffix_max = prices;
        for (int i = n - 1; i > 0; i--) {
            suffix_max[i - 1] = max(suffix_max[i - 1], suffix_max[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int c = prices[i];
            ans = max(ans, suffix_max[i] - c);
        }
        return ans;
    }
};
```

### 滚动维护最大值

本题虽然过了，但是内存使用还很多，还有优化余地。对于前缀最大/最小/求和等问题，有时候可以维护一个值代替使用数组。先修改一下枚举 i 的顺序，易知正着反着枚举 i 并不影响结果正确性：

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffix_max = prices;
        for (int i = n - 1; i > 0; i--) {
            suffix_max[i - 1] = max(suffix_max[i - 1], suffix_max[i]);
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int c = prices[i];
            ans = max(ans, suffix_max[i] - c);
        }
        return ans;
    }
};
```
然后可以发现，每一步在第二个循环用到的 suffix_max[i] 不需要提前处理，占用一个数组。维护一个变量即可：
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int suffix_max = prices[n - 1];
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix_max = max(prices[i], suffix_max);
            ans = max(ans, suffix_max - prices[i]);
        }
        return ans;
    }
};
```
