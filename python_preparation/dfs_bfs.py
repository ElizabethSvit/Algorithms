class BinaryTree(object):
	def __init__(self, val, left=None, right=None):
		self.val = val
		self.right = right
		self.left = left

	def inorder(self, root):
		res = []
		if root:
			res = self.inorder(root.left)
			res.append(root.val)
			res += self.inorder(root.right)
		return res

	def preorder(self, root):
		res = []
		if root:
			res.append(root.val)
			res += self.preorder(root.left)
			res += self.preorder(root.right)
		return res

	def postorder(self, root):
		res = []
		if root:
			res = self.postorder(root.left)
			res += self.postorder(root.right)
			res.append(root.val)
		return res

left_node = BinaryTree(2)
right_node = BinaryTree(3)
binary_tree = BinaryTree(1, left_node, right_node)

print('Inorder: ', binary_tree.inorder(binary_tree))
print('Preorder: ', binary_tree.preorder(binary_tree))
print('Postorder: ', binary_tree.postorder(binary_tree))

#######

class Tree(object):
	def __init__(self, val, children=[]):
		self.val = val
		self.children = children

	def dfs(self, root, visited):
		if root not in visited:
			visited.add(root)
			print (root.val)
			for child in root.children:
				self.dfs(child, visited)

	def bfs(self, root):
		queue = [root]

		while queue:
			node = queue.pop(0)
			for child in node.children:
				queue.append(child)

tree = Tree(1)
tree.children.append(Tree(2))
tree.children.append(Tree(3))
tree.children.append(Tree(4))
tree.dfs(tree, set())
tree.bfs(tree)
