#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <vector>
// per github issue: https://github.com/gravitino/cudaGSEA/issues/1
// to use std::iota
#include <numeric>




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
    Solution(){};
    int traverseNodePostOrder(TreeNode* currNode, int low, int high, int sum){
        int val = currNode -> val;
        if(!(val)){return 0;};
        int rightSum = 0;
        int leftSum = 0;
        if(currNode -> left){
            leftSum = traverseNodePostOrder(currNode -> left, low, high, sum);
        }
        if(currNode -> right){
            rightSum = traverseNodePostOrder(currNode -> right, low, high, sum);
        }
        sum += rightSum;
        sum += leftSum;
        if(val >= low && val <= high){
            sum += val;
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!(root -> val)) {return -1;};
        TreeNode* currNode = root;
        int sum = 0;
        sum = this->traverseNodePostOrder(currNode, low, high, sum);
        return sum;
    }
    ~Solution(){};
};


int main(int argc, char const *argv[])
{
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
    TreeNode Tree;
    TreeNode leaf1;
    TreeNode leaf2;
    TreeNode leaf3;
    TreeNode leaf4;
    TreeNode leaf5;
    TreeNode leaf6;
    TreeNode leaf7;
    Tree.val = 10;
    leaf1.val = 5;
    leaf2.val = 15;
    leaf3.val = 3;
    leaf4.val = 7;
    leaf5.val = 18;
    leaf6.val = 1;
    leaf7.val = 6;
    Tree.left = &leaf1;
    Tree.right = &leaf2;
    leaf1.left = &leaf3;
    leaf1.right = &leaf4;
    leaf2.right = &leaf5;
    leaf3.left = &leaf6;
    leaf4.left = &leaf7;
    Solution myLove = Solution();
    int sum = myLove.rangeSumBST(&Tree, 6, 10);
    std::cout << "And the results are " << sum << std::endl;
    _CrtDumpMemoryLeaks();
    return 0;
}
