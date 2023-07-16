#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
    traverse from root to leaf nodes and build a path for each node
    each path should have 1 digit that is unique to count
*/
class Solution {
public:
    bool checkPalindrom(std::vector<int> &nodeValFreuqency){
            int isPalindrom = 0;
            for(int nodeCount: nodeValFreuqency){
                isPalindrom += nodeCount & 1;
            }
            return isPalindrom == 0 || isPalindrom == 1;
        }

    void DFSpre(TreeNode* node, std::vector<int> &curNodePath, int &maxCount){
        if(!node) return;
        curNodePath[node->val]++;
        if(node -> right == nullptr && node -> left == nullptr){
            if(checkPalindrom(curNodePath)){
                maxCount++;
            } 
            curNodePath[node->val]--;
            return;
        }
        if(node -> left) DFSpre(node->left, curNodePath, maxCount);
        if(node -> right) DFSpre(node->right, curNodePath, maxCount);
        curNodePath[node->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int maxCount = 0;
        std::vector<int> curNodePath(10);
        DFSpre(root, curNodePath, maxCount);
        return maxCount;
    }
};


bool checkPalindrom1(std::vector<int> &nodeValFreuqency){
        std::map<int,int> seenVal;
        int isPalindrom = 0;
        // build frequency of each value
        for(int i = 0; i < nodeValFreuqency.size(); i++){
            int val = nodeValFreuqency[i];
            seenVal[val] += 1;
        };
        // a path is pseudo-palindromic, if it has at most one digit with an odd frequency
        for(int i = 1; i < 10; i++){
            if(seenVal.count(i) > 0){
                // odd count
                if(seenVal[i] % 2 == 1){
                    isPalindrom++;
                    if(isPalindrom > 1){
                        return false;
                    }
                }
            } 
        }
        return true;
    }

TreeNode* buildTree(int nodes[], int i, int size){
    TreeNode* newNode = nullptr;
    if(i < size){
        newNode = new TreeNode(nodes[i]);
        newNode-> left = buildTree(nodes, 2*i+1, size);
        newNode-> right = buildTree(nodes, 2*i+2, size);
    }
    return newNode;
}

void printBST(TreeNode* root){
    if(root){
        if(root -> val){
        std::cout << root -> val << " ";
        if(root -> left){
            printBST(root -> left);
        }
        if(root -> right){
            printBST(root -> right);
        }}
    }
}

int main(int argc, char const *argv[])
{
    // int r[] = {2,3,1,3,1,NULL,1};
    // TreeNode* root = buildTree(r, 0, sizeof(r)/sizeof(r[0]));
    // std::cout << std::endl;
    // int ans = Solution().pseudoPalindromicPaths(root);
    // // 2
    // std::cout << "the root node " << root -> val << " has " << ans << " palindromic paths" << std::endl;
    // int r1[] = {2,1,1,1,3,NULL,NULL,NULL,NULL,NULL,1};
    // TreeNode* root1 = buildTree(r1, 0, sizeof(r1)/sizeof(r1[0]));
    // std::cout << std::endl;
    // int ans1 = Solution().pseudoPalindromicPaths(root1);
    // // 1
    // std::cout << "the root node " << root1 -> val << " has " << ans1 << " palindromic paths" << std::endl;
    // int r2[] = {2,1,1,1,3,NULL,NULL,NULL,NULL,NULL,1};
    // TreeNode* root2 = buildTree(r2, 0, sizeof(r2)/sizeof(r2[0]));
    // int ans2 = Solution().pseudoPalindromicPaths(root2);
    // // 1
    // std::cout << "the root node " << root2 -> val << " has " << ans2 << " palindromic paths" << std::endl;
    // printBST(root2);
    int r2[] = {2,3,1,3,1,NULL,1};
    TreeNode* root2 = buildTree(r2, 0, sizeof(r2)/sizeof(r2[0]));
    int ans2 = Solution().pseudoPalindromicPaths(root2);
    // 1
    std::cout << "the root node " << root2 -> val << " has " << ans2 << " palindromic paths" << std::endl;
    printBST(root2);
    return 0;
}
