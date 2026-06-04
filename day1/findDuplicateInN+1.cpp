#include <bits/stdc++.h>
using namespace std;

// find the duplicate by sorting and checking adjacent elements
int findDuplicate(vector<int>& arr) {
  // get size
  int n = arr.size();
  // sort array in-place
  sort(arr.begin(), arr.end());
  // scan adjacent pairs
  for (int i = 0; i < n - 1; i++) {
    // return when a duplicate is found
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
  // fallback if no duplicate found
  return -1;
}

// find the duplicate using a frequency array
int findDuplicate(vector<int>& arr) {
  // get size
  int n = arr.size();
  // allocate frequency array initialized to 0
  vector<int> freq(n + 1, 0);
  // scan elements
  for (int i = 0; i < n; i++) {
    // return current value if already seen
    if (freq[arr[i]] == 0) {
      // mark as seen
      freq[arr[i]] += 1;
    } else {
      // duplicate found
      return arr[i];
    }
  }
  // fallback if none (per original)
  return 0;
}

// find the duplicate using Floyd's Tortoise and Hare cycle detection
int findDuplicate(vector<int>& nums) {
  // initialize pointers at the start
  int slow = nums[0];
  int fast = nums[0];

  // move slow by 1 step and fast by 2 steps until they meet
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);

  // reset fast to start to find the entrance to the cycle
  fast = nums[0];

  // move both by 1 step until they meet at the duplicate
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }

  // return the duplicate value
  return slow;
}


// program entry
int main() {
  // declare and initialize array
  vector<int> arr = {1, 3, 4, 2, 2};
  // print result
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
  // exit
  return 0;
}
