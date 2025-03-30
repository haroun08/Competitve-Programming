public class Solution {
    public IList<int> PartitionLabels(string s) {
        Dictionary<char, int> lastOccurrence = new Dictionary<char, int>();
        for (int i = 0; i < s.Length; i++) {
            char c = s[i];
            lastOccurrence[c] = i; 
        }
        
        int partitionEnd = 0, partitionStart = 0;
        List<int> partitionSizes = new List<int>();
        for (int i = 0; i < s.Length; i++) {
            char currentChar = s[i];
            partitionEnd = Math.Max(partitionEnd, lastOccurrence[currentChar]);
            if (i == partitionEnd) {
                partitionSizes.Add(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return partitionSizes;
    }
}
