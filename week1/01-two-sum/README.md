# [Two Sum](https://leetcode.com/problems/two-sum/)

## Solution in C++

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> last_seen;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            auto it = last_seen.find(target - num);
            if (it != last_seen.end()) {
                return {it->second, i};
            }
            last_seen[num] = i;
        }
        return {};
    }
};
```

## 解题思路

### O(n^2) Brute-Force

显然有两层循环的 O(n^2) 暴力解法:

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};
```

### 常见的算法和复杂度

1. 指数级，O(n!) ≈ O(2^n)，常见于暴力生成排列，生成集合所有子集
2. 多项式级，O(n^4), O(n^3), O(n^2)，包含多重循环的暴力枚举，动态规划和许多经典算法
3. O(n^1.5)，较为稀少，有机会细讲
4. O(nlogn)，这个复杂度常见于二分，排序，分治，以及树数据结构
5. O(n)，这个复杂度只能支持每个元素访问一遍或固定的几遍，比如 Hash，2-pointer，DP 等算法

优于 O(n) 的算法意味着算法不能遍历每个元素，往往需要输入数据有序或者证明大部分的输入和求解无关。

6. O(sqrt(n))，同 3，有机会细讲
7. O(log(n))，常见于二分
8. O(1)，常见于可证明结论（游戏必胜 or 必输，计数问题可找到通项公式）

### 辅助问题：如果数组有序？

波利亚在怎样解题中说，如果无法解决原问题，不妨考虑一个辅助问题。对于这个问题，

基于经验我们有：对于可以交换顺序的数据，排序后往往有新发现

检查手里的工具，可以想到：
1. O(n) 的方法是下限，因为至少要知道每个数是什么
2. 优于 O(n^2) 的方法有 O(nlogn) 和 O(n)，所以可选的工具有O（nlog）的 二分，排序，分治，树，O（n）的哈希，2-pointer，动态规划等方法。

因此我们尝试排序。如果输入数组有序，那么会有以下这些解法：

1. Early break：在二重循环中先选定 num1，再枚举 num2，如果num1 + num2 > target 则可以 break。
Early break 有一定的优化作用，但效果赖于数据。可构造出：target = 10000, nums = [1, 9998, 3, 9996, 5, 9994..., 5000, 5000]. Worst case 仍然是 O(n^2)。

2. 二分法：选定 num1 之后因为数组有序，比起循环一个一个尝试，可以通过二分查找最远能走到哪。问题转化为在有序的子数组里查找 num2 = target - num1

3. 2-pointers，留到 2-pointers 专门的问题细说。

所以，排序后二分或者2-pointer 是可行的。

### Any better solution than O(nlogn)?
上面的辅助问题中启示了我们：将原问题转化为：给定 num1，查找 target - num1 是否存在。Hash Table 可以在 O(1) 的时间加入，删除，查询某个元素是否存在。所以用 HashTable 可以解决这个问题。

## 细节实现

### 处理重复元素 6, [3, 3] 

TBD
