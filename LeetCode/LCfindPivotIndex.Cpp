class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> prefixSumArray(n);
        prefixSumArray[0] = nums[0];

        vector<int> postfixSumArray(n);
        postfixSumArray[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            prefixSumArray[i] = nums[i] + prefixSumArray[i - 1];
        }

        for (int j = n - 2; j >= 0; j--)
        {
            postfixSumArray[j] = nums[j] + postfixSumArray[j + 1];
        }

        for (int i = 0; i < n; i++)
        {
            if ((prefixSumArray[i] - postfixSumArray[i]) == 0)
            {
                return i;
            }
        }
        return -1;
    }
};