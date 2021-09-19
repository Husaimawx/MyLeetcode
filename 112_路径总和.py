class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        elif not root.left and not root.right:
            return sum == root.val
        else :
            return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)