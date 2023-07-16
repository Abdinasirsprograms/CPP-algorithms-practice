#include <cstdio>
#include <iostream>

/**
 * Definition for a binary tree node.
**/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// pruneTree(root):
//     for(each node, prevNodes):
//         if val == 0: return null
//         traverse nodes
//         if current -> left: 
//              pruneTree(current -> left, prevNodes)
//         if current -> right: 
//              pruneTree(current -> left, prevNodes)
        

class Solution {
public:
    bool containsOne(TreeNode* node){
        if(node == NULL) return false;

        // check if left or right contain one
        bool leftContainsOne = containsOne(node -> left);
        bool rightContainsOne = containsOne(node -> right);
        
        // prune either side
        if(leftContainsOne == false) node -> left = nullptr;
        if(rightContainsOne == false) node -> right = nullptr;
        
        // return true if current node has 1 or one of its children contians a 1
        return node -> val == 1 || leftContainsOne || rightContainsOne;
    }

    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root) ? root : NULL;
    }

    void printTree(TreeNode* node){
        if(node){
            std::cout << node -> val <<  ", ";
        }
        if(node -> left != nullptr){
            printTree(node -> left);
        }
        if(node -> right != nullptr){
            printTree(node -> right);
        }
    }
};

int main(int argc, char const *argv[])
{
    // root = [1,null,0,0,1]
    TreeNode* pos0 = new TreeNode(1);
    TreeNode* pos1 = new TreeNode(NULL);
    pos0 -> left = pos1;
    TreeNode* pos2 = new TreeNode(0);
    pos0 -> right = pos2;
    TreeNode* pos3 = new TreeNode(0);
    TreeNode* pos4 = new TreeNode(1);
    pos2 -> left = pos3;
    pos2 -> right = pos4;
    Solution* answer = new Solution;
    std::cout << "Before pruning: " << std::endl;
    std::cout << "[";
    answer->printTree(pos0);
    std::cout << "]" << std::endl;
    std::cout << "After pruning: " << std::endl;
    answer->pruneTree(pos0);
    std::cout << "[";
    answer->printTree(pos0);
    std::cout << "]";
    /* code */
    return 0;
}
