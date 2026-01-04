#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to print pattern3
    static void pattern3(int n) {
        
        // Outer loop which will loop for the rows.
        for (int i = 1; i <= n; i++) {
            
            // Inner loop which loops for the columns.
            for (int j = 1; j <= i; j++) {
                cout << j;
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
    
    sol.pattern3(N);

    return 0;
}


