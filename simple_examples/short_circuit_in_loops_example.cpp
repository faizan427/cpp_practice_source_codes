#include <iostream>
using namespace std;

int main()
{
    int* ptr = nullptr;

    /*
        VERY IMPORTANT PATTERN:

        ptr != nullptr   &&   *ptr == 10

        If ptr == nullptr:
        - Left side is false
        - Right side (*ptr) is NEVER evaluated
        - No crash
    */

    while (ptr != nullptr && *ptr == 10)
    {
        cout << "This will never execute\n";
    }

    cout << "Program did not crash due to short-circuit\n";
    return 0;
}

