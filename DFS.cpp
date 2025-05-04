// Simple DFS (Depth-First Search) traversal
void dfs(Node* node) {
    if (node == nullptr)
        return;

    cout << node->data << " ";  // Visit the node
    dfs(node->left);            // Traverse left subtree
    dfs(node->right);           // Traverse right subtree
}

