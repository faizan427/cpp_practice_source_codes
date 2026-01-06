#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to print pattern7
    static void pattern7(int n) {
        
        // Outer loop which will loop for the rows.
        for (int i = 0; i < n; i++) {
            
            //This loop will print the spaces
            for(int j = 0; j < n-i-1; j++){
                cout << " ";
            }
            
            // This loop will print asterisk.
            for (int j = 0; j < 2*i+1; j++) {
                cout << "*";
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
    
    sol.pattern7(N);

    return 0;
}


