#include <iostream>
#include <vector>

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<std::vector<int>> dp(nums1.size()+1, std::vector<int>(nums2.size()+1));
        int longestSubArray = 0;
        for(int i = 1; i < nums1.size()+1; i++){
            for(int j = 1; j < nums2.size()+1; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    longestSubArray = std::max(longestSubArray, dp[i][j]);
                } 
            }
        }
        return longestSubArray;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums1 = {1,2,3,2,1}, nums2 = {3,2,1,4,7};
    int ans = Solution().findLength(nums1,nums2);
    // 3
    std::cout << "output is: " << ans << std::endl;
    std::vector<int> nums3 = {0,0,0,0,0}, nums4 = {0,0,0,0,0};
    int ans1 = Solution().findLength(nums3,nums4);
    // 5
    std::cout << "output is: " << ans1 << std::endl;
    return 0;
}
