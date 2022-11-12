# [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
## Solution in C++
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode *tail = &head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            } else {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        
        if (list1 != nullptr) {
            tail->next = list1;
        }
        
        if (list2 != nullptr) {
            tail->next = list2;
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
### 是否允许破坏输入
按照本题的实现方法，虽然结果是对的，但是一个 side effort 就是输入的 list1 和 list2 被修改了。如果作为这个类库的用户，
调用 mergeTwoLists(list1, list2) 之后发现 list1 和 list2 变了，这个结果可能并不是想要的。要避免这个问题，应当每次复制一个节点再接在 head 后面。
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode *tail = &head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                ListNode *n = new ListNode(list1->val);
                tail->next = n;
                tail = tail->next;
                list1 = list1->next;
            } else {
                ListNode *n = new ListNode(list2->val);
                tail->next = n;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        
        while (list1 != nullptr) {
            ListNode *n = new ListNode(list1->val);
            tail->next = n;
            tail = tail->next;
            list1 = list1->next;
        }
        
        while (list2 != nullptr) {
            ListNode *n = new ListNode(list2->val);
            tail->next = n;
            tail = tail->next;
            list2 = list2->next;
        }
        
        return head.next;
    }
};
```
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
代码会变得更复杂。
