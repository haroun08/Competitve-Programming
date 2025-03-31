public class Solution {
    public long PutMarbles(int[] weights, int k) {
        int n = weights.Length;
        if (n == 0 || k == 0) return 0;
        
        int[] pairWeights = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            pairWeights[i] = weights[i] + weights[i + 1];
        }
        
        Array.Sort(pairWeights);
        
        long result = 0;
        for (int i = 0; i < k - 1; i++) {
            result += pairWeights[pairWeights.Length - 1 - i] - pairWeights[i];
        }
        
        return result;
    }
}
