#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to print pattern13
    void pattern13(int n) {
        // starting the number
        int num =1;
      
        // Outer loop for the number of rows.
        for(int i=1;i<=n;i++){
          
            /*Inner loop will loop for i times and
            print numbers increasing by 1 each time*/
            for(int j=1;j<=i;j++){
                cout<<num<<" ";
                num =num+1;
            }
            /* As soon as the numbers for each iteration
            are printed, we move to the next row and give
            a line break otherwise all numbers would get
            printed in 1 line*/
            cout<<endl;
        }
    }

};

int main() {
    int N = 5;

    //Create an instance of Solution class
    Solution sol;

    sol.pattern13(N);

    return 0;
}

