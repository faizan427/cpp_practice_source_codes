#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to print pattern6
    static void pattern6(int n) {
        
        // Outer loop which will loop for the rows.
        for (int i = 0; i < n; i++) {
            
            // Inner loop which loops for the columns.
            for (int j = 0; j < n-i; j++) {
                cout << j+1;
            }
            /* As soon as stars for each iteration are printed,
             move to the next row and give a line break */
            cout << endl;
        }
    }
};

int main() {
    int N = 5;
    
    //Create an instance of Solution class
    Solution sol;
    
    sol.pattern6(N);

    return 0;
}


