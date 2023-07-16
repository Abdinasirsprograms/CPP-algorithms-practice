#include <cstdio>
#include <iostream>
#include <string>
#include <queue>

/*

output = []
visited (Queue)

1 ->  
3 -> 1 ->

BFS
base case:
    if node empty return
if node not in visited     
    add the node to visited
    add open bracket [
    add the val 
    add close bracket ]
    to output

go to it's children
run BFS

[ 1 -> [3, 2, 
*/


// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:

    std::vector<std::vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        std::queue<Node*> nodeToVisit;
        std::vector<std::vector<int>> answer;
        nodeToVisit.push(root);
        while(nodeToVisit.empty() == false){
            int count = nodeToVisit.size();
            std::vector<int> output;
            // if node has children
            for (int i = 0; i < count; i++)
            {
                Node* currNode = nodeToVisit.front();
                nodeToVisit.pop();
                output.push_back(currNode -> val);
                for(Node* child: currNode -> children){
                    nodeToVisit.push(child);
                }
            }
            answer.push_back(output);
        
        }        
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Node* root = new Node(1);
    std::vector<Node*> tree1 = {new Node(3),
        new Node(2),new Node(4)};
    root -> children = tree1;
    std::vector<Node*> tree2 = {new Node(5), new Node(6)};
    root -> children[2] -> children = tree2;
    std::vector<std::vector<int>> answer = Solution().levelOrder(root);
    std::cout << "[";
    for(std::vector<int> child: answer){
        std::cout << "[";
        for(int count = 0; count < child.size(); count++){
            std::cout << child[count];
            if(child.size() > 1 && count != child.size() - 1){
                std::cout << ", ";
            }
        }
        std::cout << "] ";
    }
    std::cout << "]";
    return 0;
}
