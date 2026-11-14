class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;

            for (int j = i; j < nums.size() && j - i + 1 <= r; j++) {
                sum += nums[j];

                if (j - i + 1 >= l && sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna