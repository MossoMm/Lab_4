use binary_tree::BinaryTree;

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
