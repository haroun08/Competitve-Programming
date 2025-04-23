public class Solution {
    public int CountLargestGroup(int n) {
        var hashMap = new Dictionary<int, int>();
        int maxCount = 0;

        for (int i = 1; i <= n; i++) {
            int sum = DigitSum(i);

            if (hashMap.ContainsKey(sum)) {
                hashMap[sum]++;
            } else {
                hashMap[sum] = 1;
            }

            maxCount = Math.Max(maxCount, hashMap[sum]);
        }

        int count = 0;
        foreach (var val in hashMap.Values) {
            if (val == maxCount) count++;
        }

        return count;
    }

    private int DigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
