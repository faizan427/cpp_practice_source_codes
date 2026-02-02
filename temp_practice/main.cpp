#include <iostream>
#include <cstring> // Required for strlen and strcpy

class MyString {
private:
    char* data;    // Pointer to heap memory
    size_t length; // Length of the string

public:
    // 1. Constructor: Initializes memory from a C-string
    MyString(const char* input = "") {
        if (input == nullptr) {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            length = std::strlen(input);
            data = new char[length + 1];
            std::strcpy(data, input);
        }
        std::cout << "[Log] Created: " << data << std::endl;
    }

    // 2. Copy Constructor: Handles "Deep Copy"
    // This prevents two objects from pointing to the same memory address
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        std::cout << "[Log] Copied: " << data << std::endl;
    }

    // 3. Destructor: Clean up the heap memory
    ~MyString() {
        std::cout << "[Log] Destroying: " << data << std::endl;
        delete[] data;
    }

    // 4. Subscript Operator (Non-Const): For Reading & Writing
    char& operator[](size_t index) {
        if (index >= length) {
            std::cerr << "Index out of bounds!" << std::endl;
            return data[length]; // Returns null terminator as fallback
        }
        return data[index];
    }

    // 5. Subscript Operator (Const): For Reading only
    const char& operator[](size_t index) const {
        if (index >= length) {
            return data[length];
        }
        return data[index];
    }

    // Helper to print
    void display() const {
        std::cout << "String: " << data << " (Len: " << length << ")" << std::endl;
    }
};

int main() {
    // Creating a string
    MyString s1("Hello");

    // Accessing and modifying via []
    std::cout << "Original s1[0]: " << s1[0] << std::endl;
    s1[0] = 'J'; // Modify 'H' to 'J'
    s1.display();

    // Copying s1 to s2
    MyString s2 = s1; 
    s2[1] = 'a'; // Modify 'e' to 'a' in s2 only
    
    std::cout << "After modification:" << std::endl;
    s1.display(); // Jello
    s2.display(); // Jallo

    return 0;
}
