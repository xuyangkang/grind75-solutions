# [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
## Solution in C++
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void insert_tail(ListNode *&tail, int val) {
        ListNode *n = new ListNode(val);
        tail->next = n;
        tail = tail->next;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode *tail = &head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                insert_tail(tail, list1->val);
                list1 = list1->next;
            } else {
                insert_tail(tail, list2->val);
                list2 = list2->next;
            }
        }
        
        while (list1 != nullptr) {
            insert_tail(tail, list1->val);
            list1 = list1->next;
        }
        
        while (list2 != nullptr) {
            insert_tail(tail, list2->val);
            list2 = list2->next;
        }
        
        return head.next;
    }
};
```

## 解题思路

看到题目：Merge ... Sorted .....? 很容易想到 mergesort。
Mergesort 的过程是：先递归到单个元素，单个元素组成的子数组必然有序。（实际中考虑到递归的消耗，经常在数组长度小于10的时候
使用冒泡等方法返回一个有序子数组），然后 merge 函数是关键：将两个有序数组合并为一个。一个教科书的写法如下：
维护三个指针，指向两个子数组的开头和输出的数组，尝试比较两个数组的头，将较小的放到输出数组。如果两个数组中某个拿空了，则把另一个全都放到输出数组。

```cpp
void merge(int arr1[], int size1, int arr2[], int size2, int arr_out[]) {
  int i = 0, j = 0, k = 0;
  while (i < size1 && j < size2) {
    if (arr1[i] < arr2[j]) {
      arr_out[k++] = arr1[i++];
    } else {
      arr_out[k++] = arr2[j++];
    }
  }
  while (i < size1) {
    arr_out[k++] = arr1[i++];
  }
  while (j < size2) {
    arr_out[k++] = arr2[j++];
  }
}
```
这个题也是同样的方法，只是输入从数组变成了链表。结合上面的 merge 函数和链表的从尾部插入操作就可以得到解。


## 实现技巧
### Be defensive
这个题目直接用 list1，list2 中的 node 也能过，但是这是个坏的习惯。和前面说的一样，如果这个算法库的用户调用 mergeTwoLists(list1, list2) 之后 list1 和 list2 变了，这或许并不是想要的。

### 提炼 helper function
```cpp
void insert_tail(ListNode *&tail, int val) {
    ListNode *n = new ListNode(val);
    tail->next = n;
    tail = tail->next;
}
```
较早的一个版本，这段代码重复了4次。在实践中避免重复，定义一个 helper function 会提高代码的整洁度

### 链表头的空节点
题解中使用了这个编码的技巧：先建立一个空的 head 节点，然后将后面来的节点都接在他的后面。
```cpp
ListNode head;
ListNode *tail = &head;
```
这样处理链表为空的情况会更简单。
如果改成：
```cpp
ListNode *head = nullptr, *tail = nullptr;
```
那么在插入节点的时候每次都要判断：
```cpp
ListNode *n = new ListNode(list1->val);
if (head == nullptr) {
   head = tail = n;
   list1 = list1->next;
} else {
    tail->next = n;
    tail = tail->next;
    list1 = list1->next;
}
```
逻辑就更复杂了。
