#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <vector>
// per github issue: https://github.com/gravitino/cudaGSEA/issues/1
// to use std::iota
#include <numeric>



class Solution {
public:
    Solution(){};
    std::vector<int> decompressRLElist(std::vector<int>& nums) {
       std::vector<int>list;
       // elems are evaluated in pairs 
       for(int i = 0; i <= nums.size();i+=2){
        // trying to access the next val when i == nums.end() will lead to
        // dangerous perils of overflowing buffers 
        if(nums.size() <= i+1){return list;}
        int freq = nums[i], val = nums[i+1];
        for(int j = 0; j <= freq - 1; j++){
            list.push_back(val);
        }
       }
    return list;
    }
    ~Solution(){};
};


int main(int argc, char const *argv[])
{
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
    std::vector<int> nums = {7,1,2,8,2,3};
    std::cout << "My list" << std::endl;
    for(int i: nums){
        std::cout << i << std::endl;
    };
    Solution mySolution; 
    std::vector<int> myList = mySolution.decompressRLElist(nums);
    for(int i: myList){
        std::cout << i << std::endl;
    };
    _CrtDumpMemoryLeaks();
    return 0;
}
