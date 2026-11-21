class Solution {
public:
    int minimizeSum(vector<int>& nums) {
     sort(nums.begin(), nums.end());
int n = nums.size();
if(n <= 3) return 0;
int choice1 = nums[n -3]-nums[0];
int choice2 = nums[n-2]-nums[1];
int choice3 = nums[n-1]-nums[2];
return min(choice1, min(choice2, choice3));

}
    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna