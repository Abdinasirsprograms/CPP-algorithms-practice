#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        std::deque<int> deq;
        for(int curNum = 0;curNum < nums.size(); curNum++){
            if(nums[curNum] % 2 == 0){
                deq.push_front(nums[curNum]);
            } else {
                deq.push_back(nums[curNum]);
            }
        }
        std::vector<int> evenOdd(deq.begin(),deq.end());
        return evenOdd;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {6,3,5,8,7,4};
    Solution solver;
    std::vector<int> answer = solver.sortArrayByParity(nums);
    std::cout << "order of the list -> \n";
    for (int num: answer)
    {
        std::cout << num << ", ";
    }
    
    return 0;
}
