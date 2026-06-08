#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += arr[j];

                if (sum == 0)
                {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }

    // compute length of the longest subarray with sum 0
    int maxLen(int A[], int n)
    {
        // map prefix sum -> first index seen
        unordered_map<int, int> mpp;
        // best length so far
        int maxi = 0;
        // running prefix sum
        int sum = 0;

        // iterate over the array
        for (int i = 0; i < n; i++)
        {
            // update running sum
            sum += A[i];

            // if sum is zero, subarray [0..i] has zero sum
            if (sum == 0)
            {
                // update best length
                maxi = i + 1;
            }
            // otherwise check if this sum was seen before
            else
            {
                // when seen, zero-sum segment between previous index + 1 and i
                if (mpp.find(sum) != mpp.end())
                {
                    // maximize length
                    maxi = max(maxi, i - mpp[sum]);
                }
                // first time seeing this sum
                else
                {
                    // record index
                    mpp[sum] = i;
                }
            }
        }

        return maxi;
    }

    int main()
    {
        vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

        Solution obj;
        cout << obj.maxLen(arr);

        return 0;
    }
};