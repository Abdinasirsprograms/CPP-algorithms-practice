#include <cstdlib>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        int lengthOfArray = nums.size();
        int runningTotal = 0;
        for(int i =0; i < lengthOfArray; i++){
            runningTotal += nums[i];
            nums[i] = runningTotal;
        }
        return nums;
    }
};


int main(int argc, char const *argv[])
{
    Solution mySolution;
    std::vector<int> nums = {5,8,6,7};
    std::vector<int> result = mySolution.runningSum(nums);
    for(int i: result){
        std::cout << i << std::endl;
    }
    return 0;
}

