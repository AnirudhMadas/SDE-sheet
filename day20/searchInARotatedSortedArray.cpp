#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to search target in rotated sorted array using brute force
    int search(vector<int>& nums, int target) {

        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++) {

            // If current element matches target, return index
            if (nums[i] == target) {
                return i;
            }
        }

        // If not found, return -1
        return -1;
    }
};

// Driver code
int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    Solution obj;
    int index = obj.search(nums, target);

    cout << index << endl;

    return 0;
}
