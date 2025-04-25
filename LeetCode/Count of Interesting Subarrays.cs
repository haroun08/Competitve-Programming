public class Solution {
    public long CountInterestingSubarrays(IList<int> nums, int modulo, int k) {
        var countDict = new Dictionary<int, int>();
        countDict[0] = 1;
        long result = 0;
        int currentSum = 0;
        
        foreach (int num in nums) {
            int remainder = num % modulo;
            remainder = remainder < 0 ? remainder + modulo : remainder;
            if (remainder == k) {
                currentSum++;
            }
            
            int key = (currentSum - k + modulo) % modulo;
            if (countDict.TryGetValue(key, out int count)) {
                result += count;
            }
            
            int currentKey = currentSum % modulo;
            if (countDict.TryGetValue(currentKey, out int currentCount)) {
                countDict[currentKey] = currentCount + 1;
            } else {
                countDict[currentKey] = 1;
            }
        }
        
        return result;
    }
}
