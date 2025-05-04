#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to create the bad character table
unordered_map<char, int> createBadCharacterTable(const string& pattern) {
    unordered_map<char, int> badCharTable;
    int m = pattern.size();

    // Initialize all characters in the table with -1
    for (int i = 0; i < m; i++) {
        badCharTable[pattern[i]] = i;
    }

    return badCharTable;
}

// Boyer-Moore String Search Algorithm
void boyerMooreSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    
    // Create the bad character table
    unordered_map<char, int> badCharTable = createBadCharacterTable(pattern);

    int shift = 0;  // Initial shift
    
    while (shift <= n - m) {
        int j = m - 1;

        // Check for a match, starting from the end of the pattern
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        // If we have found a match, print the position
        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;

            // Shift the pattern according to the bad character heuristic
            shift += (shift + m < n) ? m - badCharTable[text[shift + m]] : 1;
        } else {
            // Shift the pattern based on the bad character table
            shift += max(1, j - badCharTable[text[shift + j]]);
        }
    }
}

int main() {
    string text = "ABAAABCDABC";
    string pattern = "ABC";

    boyerMooreSearch(text, pattern);  // Should print the match positions

    return 0;
}
