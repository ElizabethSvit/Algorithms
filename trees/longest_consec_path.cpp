/*
 Google GetAhead program task

 Write a function that computes the length of the longest path of consecutive integers in a tree.
 
 A node in the tree has a value and a set of children nodes. A tree has no cycles and each node has exactly one parent. A path where each node has a value 1 greater than its parent is a path of consecutive integers (e.g. 1,2,3 not 1,3,5).
 
 A few things to clarify:
 - Integers are all positive
 - Integers appear only once in the tree
 
 Test Cases
 Note that there may be other valid answers.
 
 For the below tree, the length of the longest path is 2 (for path 1->2)
 1 -> 2 -> 4
   -> 3
 
 For the below tree, the max length is 4 (7->8->9->10)
 5 -> 6
   -> 7 -> 12
        -> 8 -> 9 -> 15
                  -> 10
 
 Pseudo code
 
 int longest_path(root):
    if (!root) return 0
 
    longest_right = 1
    longest_left = 1
 
    if (root->right) longest_right = longest_path(root->right)
        if (root->right->val - 1 == root->val) longest_right ++
    if (root->left) longest_left = longest_path(root->left)
        if (root->left->val - 1 == root->val) longest_left ++
 
    return max(longest_right, longest_left)
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int val;
    Node() {};
    Node(int v) : val(v) {};
};

int longest_path(Node* root) {
     // executes only if there is one node (root) and it's null
    if (!root) return 0;
    
    int longest_left = 1;
    int longest_right = 1;
    
    if (root->right) {
        longest_right = longest_path(root->right);
        if (root->right->val - 1 == root->val) longest_right++;
    }
    if (root->left) {
        longest_left = longest_path(root->left);
        if (root->left->val - 1 == root->val) longest_left++;
    }
    return max(longest_right, longest_left);
}

int main(int argc, const char * argv[]) {
    // Test case 1
    /*
    Node* root = new Node(1);
    root -> right = new Node(2);
    root -> left = new Node(3);
    root -> left -> right = new Node(4);
    */
    
    // Test case 2
    /*
    Node* root = new Node(5);
    root -> right = new Node(6);
    root -> left = new Node(7);
    root -> left -> right = new Node(12);
    root -> left -> left = new Node(8);
    root -> left -> left -> right = new Node(9);
    root -> left -> left -> right -> right = new Node(15);
    root -> left -> left -> right -> left = new Node(10);
    */
    
    // Test case 3
    // Node* root = nullptr;
    
    // Test case 4
    Node* root = new Node(100);
    
    cout << longest_path(root);
    return 0;
}

