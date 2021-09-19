# Definition for a binary tree node.
from typing import List
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    root = TreeNode(0)
    def displayTree(self, root: TreeNode):
        if root is not None:
            print(root.val)
            self.displayTree(root.left)
            self.displayTree(root.right)

    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        ordernum = len(inorder)
        if ordernum != len(postorder) or ordernum is 0:
            return None
        if ordernum is 1:
            return TreeNode(inorder[0])
        test_root = TreeNode(postorder[ordernum - 1])
        inorder_pre_node = inorder[:inorder.index(test_root.val)]
        inorder_suf_node = inorder[inorder.index(test_root.val) + 1:]

        pre_num = len(inorder_pre_node)
        postorder_pre_node = postorder[:pre_num]
        postorder_suf_node = postorder[pre_num:ordernum-1]

        test_root.left = self.buildTree(inorder_pre_node, postorder_pre_node)
        test_root.right = self.buildTree(inorder_suf_node, postorder_suf_node)
        return test_root


if __name__ == '__main__':
    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
    node = Solution().buildTree(inorder, postorder) 
    Solution().displayTree(node)
    # print(inorder)
    # print(postorder)
    # print(buildTree)