#include <iostream>

struct ControlBlock {
    int count; // The "Logbook"
};

class SimpleShared {
public:
    int* data;                // The "Car"
    ControlBlock* control;    // The "Logbook"

    // 1. New Rental (Constructor)
    SimpleShared(int* input_data) {
        data = input_data;
        control = new ControlBlock;
        control->count = 1; // I am the first person using this car
        std::cout << "Created. Count is 1\n";
    }

    // 2. Share the Keys (Copy Constructor)
    SimpleShared(const SimpleShared& other) {
        data = other.data;
        control = other.control;
        control->count++; // Another person is now using this car
        std::cout << "Shared. Count is " << control->count << "\n";
    }

    // 3. Return the Keys (Destructor)
    ~SimpleShared() {
        control->count--; // I'm done with the car
        std::cout << "Returning. Count is " << control->count << "\n";

        if (control->count == 0) {
            delete data;    // No one left? Return the car!
            delete control; // Throw away the logbook!
            std::cout << "Memory Deleted (Last person left).\n";
        }
    }
};

int main() {
    SimpleShared p1(new int(500)); // Count starts at 1
    {
        SimpleShared p2 = p1;      // Count becomes 2
    } // p2 dies here, Count becomes 1
    
    return 0; 
} // p1 dies here, Count becomes 0, Memory deleted!
