class BST:
    def __init__(self, data=None) -> None:
        self.data = data
        self.left = None
        self.right = None

    def insert(self, data):
        if self.data is None:
            self.data = data
        else:
            if data < self.data:
                if self.left:
                    self.left.insert(data)
                else:
                    self.left = BST(data)
            else:
                if self.right:
                    self.right.insert(data)
                else:
                    self.right = BST(data)

    def order(self, lst):
        if self.left:
            self.left.order(lst)
        lst.append(self.data)
        if self.right:
            self.right.order(lst)
        return lst

    def pre_order(self, lst):
        lst.append(self.data)
        if self.left:
            self.left.pre_order(lst)
        if self.right:
            self.right.pre_order(lst)
        return lst

    def post_order(self, lst):
        if self.left:
            self.left.post_order(lst)
        if self.right:
            self.right.post_order(lst)
        lst.append(self.data)
        return lst

    def level_order(self):
        current_node = self
        lst = []
        queue = []
        queue.insert(0, current_node)
        while len(queue) > 0:
            current_node = queue.pop()
            lst.append(current_node.data)
            if current_node.left:
                queue.insert(0, current_node.left)
            if current_node.right:
                queue.insert(0, current_node.right)
        return lst


test = BST()

test.insert(7)
test.insert(4)
test.insert(9)
test.insert(0)
test.insert(5)
test.insert(8)
test.insert(13)

print(f"Order: {test.order([])}")
print(f"Pre-Order: {test.pre_order([])}")
print(f"Post-Order: {test.post_order([])}")
print(f"Level-Order: {test.level_order()}")
