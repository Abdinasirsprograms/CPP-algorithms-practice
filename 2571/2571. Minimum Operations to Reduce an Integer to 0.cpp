#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

/*


DNTF:

Didn't finish - couldn't think of a solution as of 04/15/23

The hint seems to be using binary operations to calculate how many operations
can be done to bring the number down to 0.

Fundemental concept is that computers operate in this manner: it's just literally bit manipulation.
I didn't solve this because I failed to understand that I'm just bitshifting left and right.

shifting left will get rid of the most significant bit and will add a 0 at the end
0010 << 1 -> 0100
0010 << 2 -> 1000
if you shift left once then it's like multiplying by 2
shifting right will
*/


enum op_T {add, subtract};

struct Node {
    int val = NULL;
    op_T operation;
    std::vector<Node>* prevNode = {nullptr};
};

class Solution {
private:
    std::unordered_map<int,int> prevVals;
    int calcValueWithOperation(int value, op_T operation,int power){
        int result = 0;
        switch(operation){
            case add:
                result = value + std::pow(2,power);
                std::cout << "val: " << value << " + " << std::pow(2,power) << " = " << result << std::endl;
                return result;
            case subtract: 
                result = value - std::pow(2,power);
                std::cout << "val: " << value << " - " << std::pow(2,power) << " = " << result << std::endl;
                return result;
        }
        return -1;
    }
    int enumerateAllPosibillities(int val){
            double base2val = std::log2(val);
            int floor = std::floor(base2val); 
            int ceil = std::ceil(base2val);
            int result = 0;
            std::cout << "floor: " << floor << " ceil: " << ceil << std::endl;
            if(floor == ceil) floor--; 
            // conver back to int for helper function
            std::cout << "subtractCeil: " << std::endl;
            int subtractCeil = calcValueWithOperation(val, subtract, ceil);
            std::cout << "subtractFloor: " << std::endl;
            int subtractFloor = calcValueWithOperation(val, subtract, floor);
            std::cout << "addCeil: " << std::endl;
            int addCeil = calcValueWithOperation(val, add, ceil);
            std::cout << "addFloor: " << std::endl;
            int addFloor = calcValueWithOperation(val, add, floor);
            if(subtractCeil == 0 || subtractFloor == 0){
                return 0;
            }
            if(subtractCeil < 0){
                subtractCeil = -1;
            } 
            if(subtractFloor < 0){
                subtractFloor = -1;
            }
            if(subtractCeil == -1 && subtractFloor == -1){
                return std::min(addCeil, addFloor);
            }
            if(subtractCeil == -1 && 0 < subtractFloor){
                return std::min(subtractFloor, std::min(addCeil, addFloor));
            }
            if(subtractFloor == -1 && 0 < subtractCeil){
                return std::min(subtractCeil, std::min(addCeil, addFloor));
            }
            return std::min(std::min(subtractFloor, subtractCeil), std::min(addCeil, addFloor));
    }

public:
    int minOperations(int n) {
        int val = n;
        int operations = 0;
        op_T add = op_T::add;
        op_T subtract = op_T::subtract;
        while(val > 0){
            val = enumerateAllPosibillities(val);
            operations++;
            if(val <= 0){
                return operations;
            }
            if(operations > 1000) return operations; //safegaurd against buffer overflow
        }
        return operations;
    }
};


void outPut(int n,int result){
    std::cout << "to convert " << n << " to 0 using only addition and subtraction" \
    << " of powers of 2" << " will take " << result << " operations." << std::endl;
    std::cout << "**********************" << std::endl;
};

int main(int argc, char const *argv[])
{
    Solution myAnswer;
    int n = 39; // o = 3 
    int result = myAnswer.minOperations(n);
    outPut(n, result);
    n = 54; // o = 3
    result = myAnswer.minOperations(n);
    outPut(n, result);
    n = 72; // o = 2 (?)
    result = myAnswer.minOperations(n);
    outPut(n, result);
    return 0;
}
