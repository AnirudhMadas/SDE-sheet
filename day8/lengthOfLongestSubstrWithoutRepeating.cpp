#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNonRepeatingSubstring(string &s) {
        
        // Length of the input string
        int n = s.size(); 
        
        //Variable to store max length
        int maxLen = 0;    
        
        /* Iterate through all possible 
        starting points of the substring*/
        for (int i = 0; i < n; i++) {
            
            /* Hash to track characters in 
            the current substring window*/
            // Assuming extended ASCII characters
            vector<int> hash(256, 0);  
            
            for (int j = i; j < n; j++) {
                
                /* If s[j] is already in the
                current substring window*/
                if (hash[s[j]] == 1) break;  
                
                /* Update the hash to mark s[j]
                as present in the current window*/
                hash[s[j]] = 1;
                
                /* Calculate the length of
                the current substring*/
                int len = j - i + 1;
                
                /* Update maxLen if the current
                substring length is greater*/
                maxLen = max(maxLen, len);
            }
        }
        
        // Return the maximum length
        return maxLen; 
    }

    /* Function to find the longest substring
    without repeating characters*/
    int longestNonRepeatingSubstring(string& s) {
        int n = s.size();
        
        // Assuming all ASCII characters
        int HashLen = 256; 
        
        /* Hash table to store last
        occurrence of each character*/
        int hash[HashLen]; 
        
        /* Initialize hash table with
        -1 (indicating no occurrence)*/
        for (int i = 0; i < HashLen; ++i) {
            hash[i] = -1;
        }

        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
            
            /* If current character s[r] 
            is already in the substring*/
            if (hash[s[r]] != -1) {
                
                /* Move left pointer to the right
                of the last occurrence of s[r]*/
                l = max(hash[s[r]] + 1, l);
            }
            
            // Calculate the current substring length
            int len = r - l + 1;
            
            // Update maximum length found so far
            maxLen = max(len, maxLen);
            
            /* Store the index of the current
            character in the hash table*/
            hash[s[r]] = r;
            
            // Move right pointer to next position
            r++;
        }
       
        // Return the maximum length found
        return maxLen;
    }

    
};

int main() {
    string input = "cadbzabcd";
    
    //Create an instance of Solution class
    Solution sol;
    
    int length = sol.longestNonRepeatingSubstring(input);
    
    //Print the result
    cout << "Length of longest substring without repeating characters: " << length << endl;
    
    return 0;
}
