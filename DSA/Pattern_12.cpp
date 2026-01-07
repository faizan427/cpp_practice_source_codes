#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to print pattern12
    void pattern12(int n) {
        
      // Initial no. of spaces in row 1.
      int spaces = 2*(n-1);
      
      // Outer loop for the number of rows.
      for(int i=1;i<=n;i++){
          
          // For printing numbers in each row
          for(int j=1;j<=i;j++){
              cout<<j;
          }
          
          // For printing spaces in each row
          for(int j = 1;j<=spaces;j++){
              cout<<" ";
          }
          
          // For printing numbers in each row
          for(int j=i;j>=1;j--){
              cout<<j;
          }
          
          /* As soon as the numbers for each iteration
          are printed, we move to the next row and give
          a line break otherwise all numbers would get 
          printed in 1 line*/
          cout<<endl;
          
          /* After each iteration nos. increase by 
          2, thus spaces will decrement by 2*/
          spaces-=2;
        }
    }

};

int main() {
    int N = 5;

    //Create an instance of Solution class
    Solution sol;

    sol.pattern12(N);

    return 0;
}
