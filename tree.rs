#[derive(Debug, PartialEq, Eq)]
struct TreeNode {
    data: i32,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

impl TreeNode {
    fn new(data: i32) -> Self {
        TreeNode { data, left: None, right: None }
    }
}

pub struct BinaryTree {
    root: Option<Box<TreeNode>>,
    count: usize,
}

impl BinaryTree {
    pub fn new() -> Self {
        BinaryTree { root: None, count: 0 }
    }

    pub fn insert(&mut self, value: i32) {
        self.root = Self::insert_rec(self.root.take(), value);
        self.count += 1;
    }

    fn insert_rec(node: Option<Box<TreeNode>>, value: i32) -> Option<Box<TreeNode>> {
        match node {
            None => Some(Box::new(TreeNode::new(value))),
            Some(mut node) => {
                if value < node.data {
                    node.left = Self::insert_rec(node.left.take(), value);
                } else if value > node.data {
                    node.right = Self::insert_rec(node.right.take(), value);
                }
                Some(node)
            }
        }
    }

    pub fn search(&self, value: i32) -> bool {
        let mut current = self.root.as_ref();
        while let Some(node) = current {
            if value == node.data { return true; }
            if value < node.data { current = node.left.as_ref(); }
            else { current = node.right.as_ref(); }
        }
        false
    }

    fn find_min(node: &Box<TreeNode>) -> &Box<TreeNode> {
        let mut current = node;
        while let Some(ref left) = current.left {
            current = left;
        }
        current
    }

    fn remove_rec(node: Option<Box<TreeNode>>, value: i32) -> Option<Box<TreeNode>> {
        match node {
            None => None,
            Some(mut node) => {
                if value < node.data {
                    node.left = Self::remove_rec(node.left.take(), value);
                    Some(node)
                } else if value > node.data {
                    node.right = Self::remove_rec(node.right.take(), value);
                    Some(node)
                } else {
                    match (node.left.take(), node.right.take()) {
                        (None, None) => None,
                        (Some(left), None) => Some(left),
                        (None, Some(right)) => Some(right),
                        (Some(left), Some(right)) => {
                            let min = Self::find_min(&right);
                            node.data = min.data;
                            node.right = Self::remove_rec(Some(right), min.data);
                            node.left = Some(left);
                            Some(node)
                        }
                    }
                }
            }
        }
    }

    pub fn remove(&mut self, value: i32) -> bool {
        if !self.search(value) { return false; }
        self.root = Self::remove_rec(self.root.take(), value);
        self.count -= 1;
        true
    }

    pub fn size(&self) -> usize {
        self.count
    }

    pub fn clear(&mut self) {
        self.root = None;
        self.count = 0;
    }
}

impl Default for BinaryTree {
    fn default() -> Self {
        Self::new()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_insert_and_search() {
        let mut tree = BinaryTree::new();
        tree.insert(10);
        assert!(tree.search(10));
        assert!(!tree.search(5));
        assert_eq!(tree.size(), 1);
    }

    #[test]
    fn test_insert_multiple() {
        let mut tree = BinaryTree::new();
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        
        assert!(tree.search(10));
        assert!(tree.search(5));
        assert!(tree.search(15));
        assert_eq!(tree.size(), 3);
    }

    #[test]
    fn test_remove_leaf() {
        let mut tree = BinaryTree::new();
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        
        assert!(tree.remove(5));
        assert!(!tree.search(5));
        assert_eq!(tree.size(), 2);
    }

    #[test]
    fn test_remove_root() {
        let mut tree = BinaryTree::new();
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        
        assert!(tree.remove(10));
        assert!(!tree.search(10));
        assert_eq!(tree.size(), 2);
    }

    #[test]
    fn test_clear() {
        let mut tree = BinaryTree::new();
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        
        tree.clear();
        assert_eq!(tree.size(), 0);
        assert!(!tree.search(10));
    }
}
