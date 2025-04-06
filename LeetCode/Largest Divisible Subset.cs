public class Solution {
    public IList<int> LargestDivisibleSubset(int[] nums) {
        if (nums == null || nums.Length == 0) {
            return new List<int>();
        }

        Array.Sort(nums);

        int n = nums.Length;
        int[] dp = new int[n];
        int[] prev = new int[n];  
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            prev[i] = -1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        List<int> result = new List<int>();
        while (maxIndex != -1) {
            result.Add(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }

        result.Reverse();
        return result;
    }
}
