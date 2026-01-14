#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string str = "Hello my name is Faizan";
    stringstream ss(str);
    string word;
    vector<string> words;

    // 1. Store words in a vector
    while (ss >> word) {
        words.push_back(word);
    }

    int n = words.size();
    bool isPalindrome = true;

    cout << "Reversed: ";
    for (int i = n - 1; i >= 0; i--) {
        // 2. Small Change: Compare current word with its opposite partner
        if (words[i] != words[n - 1 - i]) {
            isPalindrome = false;
        }
        
        cout << words[i] << (i == 0 ? "" : " ");
    }

    // 3. Output result
    cout << "\nIs Word-Palindrome: " << (isPalindrome ? "Yes" : "No") << endl;

    return 0;
}
