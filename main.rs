use binary_tree::BinaryTree;

fn main() {
    let mut tree = BinaryTree::new();
    
    println!("Inserting values: 10, 5, 15, 3, 7");
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    
    println!("Size: {}", tree.size());
    println!("Search 7: {}", tree.search(7));
    println!("Search 20: {}", tree.search(20));
    
    println!("\nRemoving 5...");
    tree.remove(5);
    println!("Size after removal: {}", tree.size());
    println!("Search 5: {}", tree.search(5));
    
    println!("\nClearing tree...");
    tree.clear();
    println!("Size after clear: {}", tree.size());
}
