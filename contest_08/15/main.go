type BinaryTreeNode struct {
	value int
	left  *BinaryTreeNode
	right *BinaryTreeNode
}

func NewBinaryTreeNode(value int) *BinaryTreeNode {
	var tree BinaryTreeNode
	tree.value = value
	tree.left = nil
	tree.right = nil
	return &tree
}

func (t *BinaryTreeNode) insertNode(value int) {
	if value < t.value {
		if t.left == nil {
			t.left = NewBinaryTreeNode(value)
		} else {
			t.left.insertNode(value)
		}
	} else {
		if t.value == value {
			return
		}
		if t.right == nil {
			t.right = NewBinaryTreeNode(value)
		} else {
			t.right.insertNode(value)
		}
	}
}

func (t *BinaryTreeNode) getMax() *BinaryTreeNode {
	if t == nil {
		return nil
	}
	if t.right == nil {
		return t
	}
	return t.right.getMax()
}

func (t *BinaryTreeNode) removeNode(value int) *BinaryTreeNode {
	if t == nil {
		return nil
	} else if value < t.value {
		t.left = t.left.removeNode(value)
	} else if value > t.value {
		t.right = t.right.removeNode(value)
	} else {
		if t.left == nil || t.right == nil {
			if t.left == nil {
				t = t.right
			} else {
				t = t.left
			}
		} else {
			max := t.left.getMax()
			t.value = max.value
			t.left = t.left.removeNode(max.value)
		}
	}
	return t
}

func (t *BinaryTreeNode) findNode(value int) *BinaryTreeNode {
	if t == nil {
		return nil
	}
	if t.value == value {
		return t
	}
	if value < t.value {
		return t.left.findNode(value)
	} else {
		return t.right.findNode(value)
	}
}

func (t *BinaryTreeNode) String() string {
	var list []*BinaryTreeNode
	treeStr := ""
	list = append(list, t)
	for len(list) != 0 {
		treeStr += fmt.Sprintf("%d", list[0].value) + " "
		if list[0].left != nil {
			list = append(list, list[0].left)
		}
		if list[0].right != nil {
			list = append(list, list[0].right)
		}
		list = list[1:]
	}
	return treeStr
}