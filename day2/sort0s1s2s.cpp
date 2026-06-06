#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort the array containing only 0s, 1s and 2s
    void sortZeroOneTwo(vector<int>& nums) {
        // Initialize count variables for 0s, 1s, and 2s
        int count0 = 0, count1 = 0, count2 = 0;

        // Count the frequency of 0s, 1s, and 2s in the array
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }

        // Overwrite the array with the counted values
        int index = 0;

        // Fill with 0s
        while(count0--) {
            nums[index++] = 0;
        }

        // Fill with 1s
        while(count1--) {
            nums[index++] = 1;
        }

        // Fill with 2s
        while(count2--) {
            nums[index++] = 2;
        }
    }

    // Function to sort an array containing only 0s, 1s, and 2s
    void sortZeroOneTwo(vector<int>& nums) {
        // Count of 0s, 1s, and 2s
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        // First pass: Count the number of 0s, 1s, and 2s
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) cnt0++;
            else if (nums[i] == 1) cnt1++;
            else cnt2++;
        }

        // Second pass: Fill the array with 0s, then 1s, then 2s

        // Fill the first 'cnt0' elements with 0
        for (int i = 0; i < cnt0; i++) {
            nums[i] = 0;
        }

        // Fill the next 'cnt1' elements with 1
        for (int i = cnt0; i < cnt0 + cnt1; i++) {
            nums[i] = 1;
        }

        // Fill the remaining elements with 2
        for (int i = cnt0 + cnt1; i < nums.size(); i++) {
            nums[i] = 2;
        }
    }

    // Function to sort array containing 0s, 1s, and 2s using Dutch National Flag Algorithm
    void sortZeroOneTwo(vector<int>& nums) {
        // Initialize three pointers: low, mid starting from 0, high from end of array
        int low = 0, mid = 0, high = nums.size() - 1;

        // Process elements until mid pointer crosses high pointer
        while (mid <= high) {
            // If current element is 0, swap with low and move both pointers forward
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            // If current element is 1, it's already in correct place → move mid forward
            else if (nums[mid] == 1) {
                mid++;
            }
            // If current element is 2, swap with high and move only high pointer backward
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Driver code
int main() {
    vector<int> nums = {1, 0, 2, 1, 0};

    Solution obj;
    obj.sortZeroOneTwo(nums);

    for(int x : nums) {
        cout << x << " ";
    }

    return 0;
}
