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
但是这个有手就行的解法显然是不够的。

### 了解你的武器

本系列教程假设读者掌握了一种编程语言，教科书范围的算法和数据结构。回顾一下常见的算法和数据结构及其复杂度：

1. 指数级，O(n!) ≈ O(2^n)，常见于暴力生成排列，生成集合所有子集
2. 多项式级，O(n^4), O(n^3), O(n^2)，包含多重循环的暴力枚举，动态规划和许多经典算法
3. O(n^1.5)，较为稀少，有机会细讲
4. O(nlogn)，这个复杂度常见于二分，排序，分治，以及树数据结构
5. O(n)，这个复杂度只能支持每个元素访问一遍或固定的几遍，比如 Hash，2-pointer，DP 等算法

优于 O(n) 的算法意味着算法不能遍历每个元素，需要输入数据有序或者证明大部分的输入和求解无关。

6. O(sqrt(n))，同 3，有机会细讲
7. O(log(n))，常见于二分
8. O(1)，常见于可证明结论（游戏必胜 or 必输，计数问题可找到通项公式）

### 怎样解题

著名数学家波利亚在怎样解题中说，解题就是找到已知和未知的关系。现在的状况是：

问题：在数组中找到 (num1, num2) 使: num1 + num2 = target。

已知：现在的解法为 O(n^2)，O(n) 的方法是下限，因为至少要知道每个数是什么，所以可选的武器在 O(nlogn) 和 O(n) 的范围



### 辅助问题：如果数组有序？

波利亚在怎样解题中说，如果对原问题没有想法，可以考虑寻找一个辅助问题。根据经验，对于可以交换顺序的输入，排序后往往有新发现。比如很多操作：找最大最小第K大，查询等在有序数组内可以高效执行。贪心算法需要先排序。因此我们尝试排序。

如果输入数组有序，那么会有以下这些方法：

1. Early break：在二重循环中先选定 num1，再枚举 num2，如果num1 + num2 > target 则可以 break。
Early break 有一定的优化作用，但效果赖于数据。可构造出：target = 10000, nums = [1, 9998, 3, 9996, 5, 9994..., 5000, 5000]. Worst case 仍然是 O(n^2)。

2. 二分法：选定 num1 之后因为整个数组有序，可以通过二分代替循环来得出最远能走到哪。问题转化为在有序的子数组里查找 num2 = target - num1 是否存在

3. 2-pointers，留到 2-pointers 专门的问题细说。

所以，排序后二分或 2-pointer 是可行的。

### Any better solution than O(nlogn)?
上面的辅助问题中启示了我们：原问题可以转化为：给定 num1，查找 target - num1 是否存在。Hash Table 可以在 O(1) 的时间加入，删除，查询某个元素是否存在。所以用 HashTable 可以解决原问问题。

## 细节实现

### 处理重复元素 6, [3, 3] => {0, 1}

按题意：`you may not use the same element twice.`，因此有两个处理方法：

方法1：动态维护 last_seen 保存 a[0...i - 1] 的坐标。对某个元素 nums[i], 在 last_seen 中查找，这样 last_seen 中包含的坐标都小于 i。然后将 (nums[i], i) 加入 last_seen 中，代码如开头题解。

方法2：对每个值只保存某次出现的下标。然后对每个 nums[i]，查找是否存在 nums[j] = target - num[i]，如果存在，且 i != j 则可以返回。

```cpp
class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            index[nums[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            auto it = index.find(target - nums[i]);
            if (it != index.end() && it->second != i) {
                return {i, it->second};
            }
        }
        return {};
    }
};
```

### Defensive Copy

至少 LeetCode 的所有 C++ 题目都有这个问题，方法接口传的是引用，这样导致对 nums 的所有修改都会传回 caller。假设我是某个算法库的用户，我传了个参数进去，结果返回值虽然正确，但是参数也被改成了不知什么样，作为用户我会是崩溃的。所以最为安全的写法是对输入创造一个 "Defensive Copy"，如下：

```cpp
class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        vector<int> nums_copy = nums;
        // ...
    }
};
```

### C++ unordered_map 的陷阱

unordered_map 对于精心构造的数据会产生哈希冲突, C++ 的实现和 Java 不同，是用链表实现的开散列。所以对精心构造的数据，C++ unordered_map 插入删除查找都会变成 O(n)，在竞赛中要注意。

### int or size_t？

一些编译器会在 `for (int i = 0; i < nums.size(); i++) {` 处报 warning，因为 i 是有符号整数，nums.size() 返回类型是 size_t，是无符号整数。在比较的时候存在出问题的理论可能，但实战中数组下标很难取到 int32 的上限，正常来说还好。

### 保存 find 的结果，避免多次查找

这一部分：
```
auto it = last_seen.find(target - num);
if (it != last_seen.end()) {
    return {it->second, i};
}
```

看上去繁琐，但这是 C++ 最效率的写法。it 是 C++ 的迭代器，可以理解成一个指向 (k, v) 的指针，last_seen.find 返回迭代器 it，或者 last_seen.end() 表示没找到。接下来的操作都可以通过 it，而不需要再次到 map 中查找。

### return 的语法糖

自从某个版本开始，C++ return vector 的时候也可以写 `return {it->second, i};` 了，好耶！

## 其他语言实现
TODO

## 参考：怎样解题表
TODO
