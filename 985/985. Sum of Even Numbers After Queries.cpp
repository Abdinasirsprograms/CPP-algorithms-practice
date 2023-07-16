#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<int> sumEvenAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::vector<int> output;
        int curEvenCount = 0;
        for(int val: nums){
            if((val % 2) == 0){
                curEvenCount += val;
            }
        }
        for(int i = 0; i < queries.size(); i++){
            int curVal = queries[i][0], curIdx = queries[i][1];
            if(nums[curIdx] % 2 == 0){
                curEvenCount -= nums[curIdx]; 
            }
            if((nums[curIdx] += curVal) % 2 == 0){ 
                curEvenCount += nums[curIdx];
            } 
            output.push_back(curEvenCount);
        }
        return output;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1,2,3,4};
    std::vector<std::vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
    std::vector<int> ans = Solution().sumEvenAfterQueries(nums, queries);
    std::cout << "[";
    for(int val: ans){
        std::cout << val << ", ";
    }
    std::cout << "]" << std::endl;
    return 0;
}
