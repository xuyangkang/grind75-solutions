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

很多人认为这是动态规划的第一题，但实际上还没有逃离数学变形的范围。

$ Max_{i<j}(p_{j} - p_{i}) $
