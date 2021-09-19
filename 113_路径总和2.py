from typing import List

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # def digui(self, tree_list: List, parent_num:int, LOR:int ) -> TreeNode:
    #     if LOR is 0:
    #         num = 2 * parent_num + 1
    #     elif LOR is 1:
    #         num = 2 * parent_num + 2
    #     if num >= len(tree_list):
    #         return None
    #     tree = TreeNode(tree_list[num])
    #     tree.left = self.digui(tree_list, num, 0)
    #     tree.right = self.digui(tree_list, num, 1)
    #     return tree
    # def buildTree(self, tree_list: List) -> TreeNode:
    #     tree = TreeNode(tree_list[0])
    #     tree.left = self.digui(tree_list, 0, 0)
    #     tree.right = self.digui(tree_list, 0, 1)
    #     return tree
    # def displayTree(self, root: TreeNode):
    #     if root is not None:
    #         print(root.val)
    #         self.displayTree(root.left)
    #         self.displayTree(root.right)
    ans = []
    def dfs(self, node: TreeNode, road: List, road_sum: int, sum: int):
        if node.left is None and node.right is None:
            if road_sum == sum:
                ans.push(road)
        if node.left is not None:
            new_left_road = road
            new_left_road.push(node.left.val)
            self.dfs(node.left, new_left_road, road_sum + node.left.val)
        if node.right is not None:
            new_right_road = road
            new_right_road.push(node.right.val)
            self.dfs(node.right, new_right_road, road_sum + node.right.val)
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if TreeNode is not None:
            self.dfs(root, [], 0, sum)
        return self.ans


if __name__ == '__main__':
    tree_list_str = input()
    sum = input()

    tree_list = tree_list_str.strip('[').strip(']').split(',')
    # print(tree_list)
    tree = Solution().buildTree(tree_list)
    Solution().displayTree(tree)
    # print(Solution().pathSum(tree, sum))