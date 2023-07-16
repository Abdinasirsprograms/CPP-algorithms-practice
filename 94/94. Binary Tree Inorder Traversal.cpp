#include <cstdlib>
#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void DFS(TreeNode* node, std::vector<int>& val){
        if(node == nullptr) return;
        if(node -> left){
            DFS(node -> left, val);
        }
        val.push_back(node -> val);
        if(node -> right){
            DFS(node -> right, val);
        }
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> val;
        DFS(root, val);
        return val;        
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    root -> right = two;
    two -> left = three;
    Solution answer = Solution();
    std::vector<int> result = answer.inorderTraversal(root);
    for(int v: result){
        std::cout << v << std::endl; 
    }
    return 0;
}
