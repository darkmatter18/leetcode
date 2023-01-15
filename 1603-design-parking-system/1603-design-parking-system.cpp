class ParkingSystem {
    int slot[3];
public:
    ParkingSystem(int big, int medium, int small) {
        slot[0] = big;
        slot[1] = medium;
        slot[2] = small;
    }
    
    bool addCar(int carType) {
        carType--;
        if(slot[carType] > 0){
            slot[carType]--;
            return true;
        }
        else return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */