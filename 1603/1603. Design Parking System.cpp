#include <cstdlib>
#include <iostream>
#include <vector>

class ParkingSystem {
private:
    std::vector<int> parkingSpaces;
public:
    ParkingSystem(int big, int medium, int small) {
        this -> parkingSpaces = {big, medium, small};
    }
    
    bool addCar(int carType) {
        // cartype starts at 1 vs. vector starting at 0
        int carLot = this->parkingSpaces[carType - 1];
        if(carLot == 0) return false; 
        int spaceAvaliable = (carLot - 1);
        if(spaceAvaliable >= 0){
            this->parkingSpaces[carType - 1] = spaceAvaliable;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main(int argc, char const *argv[])
{
    enum carSize : int {
        SMALL = 3,
        MEDIUM = 2,
        LARGE = 1
    };
    int big = 1;
    int medium = 2;
    int small = 3;
    ParkingSystem* obj = new ParkingSystem(big, medium, small);
    int FiatMini = carSize::SMALL;
    bool param_1 = obj->addCar(FiatMini);
    if(param_1){ 
        std::cout << "You can park your car" << std::endl;
    } else{
        std::cout << "Sorry, no room" << std::endl;
    }
    enum Suit : char {Clubs, Diamonds='e', Hearts, Spades};
    std::cout<<Suit::Diamonds<<std::endl; 
    return 0;
}

