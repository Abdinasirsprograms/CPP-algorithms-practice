#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) {
        // sort by descending attack
        std::sort(properties.begin(), properties.end(), [](std::vector<int> &a, std::vector<int> &b){
            if(a[0] != b[0]){
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        int numWeakCharacters = 0;
        int maxDefense = 0;
        for (std::vector<int> currCharacter: properties)
        {
            if(maxDefense > currCharacter[1]) numWeakCharacters++;
            else maxDefense = currCharacter[1];
        }
        return numWeakCharacters;
    }
};

int main(int argc, char const *argv[])
{
    // std::vector<std::vector<int>> properties = {{5,5},{6,3},{3,6}};
    // std::vector<std::vector<int>> properties = {{1,5},{10,4},{4,3}};
    std::vector<std::vector<int>> properties = {{2,2},{3,3}};
    int answer = Solution().numberOfWeakCharacters(properties);
    std::cout << "max character count is " << answer << std::endl;
    return 0;
}
