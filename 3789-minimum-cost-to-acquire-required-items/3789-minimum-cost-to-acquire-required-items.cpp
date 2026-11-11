class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long option1 = (long long)need1 * cost1 + (long long)need2 * cost2;

        long long option2 = (long long)max(need1, need2) * costBoth;

        long long common = min(need1, need2);

        long long option3 = (long long)common * costBoth
                          + (long long)(need1 - common) * cost1
                          + (long long)(need2 - common) * cost2;

        return min({option1, option2, option3});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna