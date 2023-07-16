#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

/*

tree2str(root) -> root - (nodes == 0) 

string = []
go into node with string
    if the node is empty: 
        return 
    add val to string
    if there's a left child: 
        add '(' to string
        call tree2str(left, string)
    if there's a right child:
        add '(' to string
        call tree2str(right, string)
    add ')' to string'
    return 
*/




//  Definition for a binary tree node.
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
        std::string tree2str(TreeNode* node) {
            if(node == nullptr) return "";
            std::string currVal = std::to_string(node -> val);
            // if no children then return value
            if(node -> left == nullptr && node -> right == nullptr){
                return currVal + "";
            }
            // if there's a left child but no right then return the left child wrapped 
            // in paranthesis regardless of its value
            if(node -> right == nullptr){
                return currVal + "(" + tree2str(node -> left) + ")";
            }
            return currVal + "(" + tree2str(node -> left) + ")(" + tree2str(node -> right) + ")";
        }
};

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    root -> left = two;
    root -> right = three;
    two -> left = four;
    Solution answer = Solution();
    std::string treeAsString = answer.tree2str(root);
    std::cout << "tree as string " << treeAsString << std::endl;
    std::cout << "tree as string is correct " << (bool(treeAsString == "1(2(4))(3)") ? "true" : "false") << std::endl;
    two -> left = nullptr;
    two -> right = four;
    treeAsString = answer.tree2str(root);
    std::cout << "tree as string is " << treeAsString << std::endl;
    return 0;
}
