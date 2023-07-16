#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>

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
    std::map<int, std::map<int, std::multiset<int>>> grid;
    void DFS(TreeNode* node, int row, int col){
        if(!node) return;
        this->grid[col][row].insert(node->val);
        DFS(node->left, row+1, col-1);
        DFS(node->right, row+1, col+1);

    };
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        DFS(root, 0,0);
        for (auto row : this->grid)
        {
            ans.push_back(std::vector<int>());
            for (auto col : row.second)
            {
                for (auto val : col.second)
                {
                    ans.back().push_back(val);                    
                }
            }
            
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    // root *2 +1 left, +2 right
    // 2*2 = 4 +1 = 5, +2 = 6
    // 1*2 = 2+1=null, +2=4
    // std::vector<int> root = {9,20,NULL,NULL,15,7};
    TreeNode* root = new TreeNode(3);
    TreeNode* nine = new TreeNode(9);
    TreeNode* tweenty = new TreeNode(20);
    TreeNode* fiveteen = new TreeNode(15);
    TreeNode* seven = new TreeNode(7);
    root -> left = nine;
    root -> right = tweenty;
    tweenty -> right = seven;
    tweenty -> left = fiveteen;    
    std::vector<std::vector<int>> ans = Solution().verticalTraversal(root);
    std::cout << "[";
    for (auto i : ans)
    {
        std::cout << "[";
        for (auto val : i){
            if(val != i.back()){

                std::cout << val << ", ";
            }else {

                std::cout << val << "";
                std::cout << "]";
            }
        }    
    }
    std::cout << "]";
    std::cout << std::endl;
    
    return 0;
}
