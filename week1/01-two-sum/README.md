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

### What if the array is sorted?

基于以下三点：
1. 已知：优于 O(n^2) 的方法只有 O(nlogn) 和 O(n)
2. O(n) 的方法是下限，因为必须至少要知道每个数是什么
3. 对于可以交换顺序的数据，将数据组织一下，比如按一定顺序排序后往往有新发现

因此我们尝试排序，花费 O(nlogn) 排序后，输入是个有序的数组，那么会有以下这些想法：

1. Early break：在二重循环中先选定 num1，再枚举 num2，如果num1 + num2 > target 则可以 break，例：
```cpp
vector<int> twoSumSorted(const vector<int> &nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = nums[i] + nums[j];
            if (sum > target) {
                break;
            }
            if (sum == target) {
                return {nums[i], nums[j]};
            }
        }
    }
    return {};
}
```
但 early break 往往依赖于数据，可构造出：target = 10000, nums = [1, 9998, 3, 9996, 5, 9994..., 5000, 5000]. Worst case 仍然是 O(n^2)。

2. 二分法：在选定数1之后，问题转化为在一个有序的子数组里查找是否存在数2，使数1 + 数2 = target，简单变形，也就是查找 num2 = target - num1 是否存在
```cpp
vector<int> twoSumSorted(const vector<int> &nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        auto j = lower_bound(nums.begin() + i, nums.end(), target - nums[i]);
        if (j != nums.end() && *j == target - nums[i]) {
            return {nums[i], target - nums[i]};
        }
    }
    return {};
}
```

3. 2-pointer
```cpp
vector<int> twoSumSorted(const vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l < r) {
        while (nums[l] + nums[r] > target) {
            r--;
        }
        if (nums[l] + nums[r] == target) {
            break;
        }
        l++;
    }
    return {nums[l], nums[r]};
}
```


### Any better solution than O(nlogn)?
在上面的方案中，我们学到了：将原问题：寻找 pair (num1, num2) 使 num1 + num2 = ans 转化为：给定 num1，查找 ans - num1 是否存在。Hash Table 可以在 O(1) 的时间加入，删除，查询某个元素是否存在。所以用 HashTable 可以解决这个问题。

## 代码实现

### 处理重复元素 6, [3, 3] 

TBD
