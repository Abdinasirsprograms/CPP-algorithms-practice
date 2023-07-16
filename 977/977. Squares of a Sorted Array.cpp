#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> results = {};
        for(int num: nums){
            results.push_back(num * num);
        }
        /*
        Which is bigger - left or right?
        swap the positions
        
        */
        return results;
    }
};


int main(int argc, char const *argv[])
{
    Solution answer;
    std::vector<int> nums = {-4,-1,0,3,10};
    std::vector<int> results = answer.sortedSquares(nums); 
    for(int num: results){
        std::cout << num << ", ";
    }
    return 0;
}
