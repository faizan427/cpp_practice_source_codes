#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to print pattern9
    void pattern9(int n) {
        erect_pyramid(n);
        inverted_pyramid(n);
    }
private: 
    void erect_pyramid(int n) {
        // Outer loop which will loop for the rows.
        for (int i = 0; i < n; i++){
            // For printing the spaces before stars in each row
            for (int j = 0; j < n - i - 1; j++) {
                cout<< " ";
            }
            
            // For printing the stars in each row
            for (int j = 0; j < 2 * i + 1; j++) {
                cout<< "*";
            }

            /* As soon as the stars for each iteration are printed,
            we move to the next row and give a line break */
            cout << endl;
        }
    }
    void inverted_pyramid(int n){
        // Outer loop which will loop for the rows.
        for (int i = 0; i < n; i++){
            // For printing the spaces before stars in each row
            for (int j =0; j<i; j++){
                cout<< " ";
            }
       
            // For printing the stars in each row
            for(int j=0;j< 2*n -(2*i +1);j++){
                cout<< "*";
            }
       
            /* As soon as the stars for each iteration are printed,
            we move to the next row and give a line break */
            cout<< endl;
        }
    }
};

int main() {
    int N = 5;

    //Create an instance of Solution class
    Solution sol;

    sol.pattern9(N);

    return 0;
}

