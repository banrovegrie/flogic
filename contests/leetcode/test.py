import re
from typing import Optional, List

# Testing dicts
d = {0: "1", 1: "2"}
f = {1: "2", 0: "1"}
print(d == f)

"""
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
"""


def isPalindrome(self, s: str) -> bool:
    s = s.lower()
    s = re.sub(r"[^a-z0-9]", "", s)
    return s == s[::-1]


"""
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
"""


def maxProfit(self, prices: List[int]) -> int:
    if len(prices) < 2:
        return 0

    min_price = prices[0]
    ans = 0
    for i in prices[1:]:
        ans = max(ans, i - min_price)
        min_price = min(min_price, i)
    return ans


"""
Binary Search
"""


def search(self, nums: List[int], target: int) -> int:
    start = 0
    end = len(nums)

    while start < end:
        mid = (start + end) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            start = mid + 1
        elif nums[mid] > target:
            end = mid

    return -1


"""
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
"""


def lowestCommonAncestor(self, root, p, q):
    if not root:
        return None
    if root.val > p.val and root.val > q.val:
        return self.lowestCommonAncestor(root.left, p, q)
    if root.val < p.val and root.val < q.val:
        return self.lowestCommonAncestor(root.right, p, q)
    return root


"""
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as: 
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
"""


def depth(self, node):
    if not node:
        return 0
    return max(self.depth(node.left), self.depth(node.right)) + 1


def isBalanced(self, root) -> bool:
    if not root:
        return True
    left = self.depth(root.left)
    right = self.depth(root.right)
    if abs(left - right) > 1:
        return False
    return self.isBalanced(root.left) and self.isBalanced(root.right)


"""
Default dict
"""
from collections import defaultdict

d = defaultdict(int)
print(d[100])

"""
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
"""


def middleNode(self, head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow


"""
Add binary numbers
"""


def addBinary(self, a: str, b: str) -> str:
    if not a:
        return b
    if not b:
        return a
    if len(a) < len(b):
        a, b = b, a
    a = a[::-1]
    b = b[::-1]
    carry = 0
    ans = []
    for i in range(len(a)):
        if i < len(b):
            sum = int(a[i]) + int(b[i]) + carry
        else:
            sum = int(a[i]) + carry
        carry = sum // 2
        ans.append(str(sum % 2))
    if carry:
        ans.append(str(carry))
    return "".join(ans[::-1])


"""
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
"""


def longestPalindrome(self, s: str) -> int:
    d = defaultdict(int)
    for c in s:
        d[c] += 1
    ans = 0
    for v in d.values():
        ans += v // 2 * 2
        if ans % 2 == 0 and v % 2 == 1:
            ans += 1
    return ans


"""
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
"""


def diameterOfBinaryTree(self, root) -> int:
    if not root:
        return 0
    left = self.depth(root.left)
    right = self.depth(root.right)
    return max(
        left + right,
        self.diameterOfBinaryTree(root.left),
        self.diameterOfBinaryTree(root.right),
    )


"""
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.
"""


class MyQueue:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, x: int) -> None:
        self.stack1.append(x)

    #     self.stack.append(x)

    def pop(self) -> int:
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop()

    def peek(self) -> int:
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2[-1]

    def empty(self) -> bool:
        return not self.stack1 and not self.stack2


"""
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
"""


def levelOrder(self, root):
    if not root:
        return []
    ans = []
    queue = [root]
    while queue:
        ans.append([node.val for node in queue])
        queue = [child for node in queue for child in (node.left, node.right) if child]
    return ans
