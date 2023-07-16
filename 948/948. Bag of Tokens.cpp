#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

/*
    sort list;
    face it up: if score >= 1
    face it down: if power >= token[i]
    for each token
        decide, should I face it up? or face it down?
        I need to decide for each token to get the max score possible
    tokens = {100,200,300,400}, power = 200, score = 0;
    if I can buy the begning then it's possible to get a score > 1;
        therefore buy the max from the other end;

    
     
*/
class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        int maxPoints = 0;
        sort(tokens.begin(), tokens.end());
        int max = tokens.size()-1;
        int i = 0;
        int points = 0;
        while(i <= max){
            if(power >= tokens[i]){
                points++;
                power -= tokens[i++];
                maxPoints = std::max(points, maxPoints);
            } 
            else if(points > 0){
                points--;
                power += tokens[max--];
            } 
            else{
                return maxPoints;
            }
        }
        return maxPoints;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> tokens = {100,200,300};
    int power = 100;
    int result = Solution().bagOfTokensScore(tokens, power);
    std::cout << "max score achiavble = " << result << std::endl;  // score = 1
    tokens = {500,100,40,10};
    power = 85;
    result = Solution().bagOfTokensScore(tokens, power);
    std::cout << "max score achiavble = " << result << std::endl; // score = 2 
    tokens = {100,200,300,400};
    power = 200;
    result = Solution().bagOfTokensScore(tokens, power);
    std::cout << "max score achiavble = " << result << std::endl; // score = 2 
    return 0;
}

