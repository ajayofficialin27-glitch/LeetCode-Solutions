class Solution {
    public int[] getConcatenation(int[] nums) {
      int n = nums.length;
      int[] num2 = new int [2*n];
      for(int i = 0; i < n; i++){
        num2[i] = nums[i];
        num2[n + i] = nums[i];

      }
      return num2;  
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna