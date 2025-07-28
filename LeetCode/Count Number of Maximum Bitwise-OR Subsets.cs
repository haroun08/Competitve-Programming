public class Solution {
    public int CountMaxOrSubsets(int[] nums) {
        int max = 0;
        int size = 1 << 17;
        int[] dp = new int[size];
        dp[0] = 1;
        
        foreach (int num in nums) {
            for (int i = max; i >= 0; i--) {
                if (dp[i] != 0) {
                    dp[i | num] += dp[i];
                }
            }
            max |= num;
        }
        
        return dp[max];
    }
}
