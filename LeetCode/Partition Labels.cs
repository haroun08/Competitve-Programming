public class Solution {
    public IList<int> PartitionLabels(string s) {
        int[] lastOccurrence = new int[26];
        for (int i = 0; i < s.Length; i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        
        int partitionEnd = 0, partitionStart = 0;
        List<int> result = new List<int>();
        for (int i = 0; i < s.Length; i++) {
            partitionEnd = Math.Max(partitionEnd, lastOccurrence[s[i] - 'a']);
            if (i == partitionEnd) {
                result.Add(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return result;
    }
}
