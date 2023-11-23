#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int snacks;
    vector<TreeNode*> children;

    TreeNode(int snacks) : snacks(snacks) {}
};

void printTree(TreeNode* node, int depth = 0) {
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << "- " << node->snacks << endl;

    for (TreeNode* child : node->children) {
        printTree(child, depth + 1);
    }
}

int maxSnacks = 0;

pair<int, int> postOrderTraversal(TreeNode* node) {
    int friendsCount = 0;
    int totalSnacks = 0;

    for (TreeNode* child : node->children) {
        pair<int, int> childData = postOrderTraversal(child);
        friendsCount += childData.first;
        totalSnacks += childData.second;
    }

    // Check if the current node has snacks
    if (node->snacks > 0) {
        friendsCount++;
        totalSnacks += node->snacks;
    }

    // Calculate the maximum number of snacks enjoyed at this node
    maxSnacks = max(maxSnacks, totalSnacks - friendsCount);

    return {friendsCount, totalSnacks};
}

int calculateMaxSnacks(TreeNode* root) {
    maxSnacks = 0;
    postOrderTraversal(root);
    return maxSnacks;
}

int main() {
    // Create the tree
    TreeNode* root = new TreeNode(0); // Assuming root node has no snacks

    // Add nodes and edges to the tree
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(1);

    root->children.push_back(node1);
    root->children.push_back(node2);
    node1->children.push_back(node3);
    node1->children.push_back(node4);

    // Print the tree
    cout << "Tree Structure:" << endl;
    printTree(root);

    // Calculate the maximum number of snacks enjoyed
    int maxSnacks = calculateMaxSnacks(root);

    cout << "Maximum number of snacks enjoyed: " << maxSnacks << endl;

    // Clean up memory
    delete node4;
    delete node3;
    delete node2;
    delete node1;
    delete root;

    return 0;
}
