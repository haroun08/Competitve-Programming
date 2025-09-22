public class Solution
{
    public int MaxFrequencyElements(int[] nums)
    {
        Dictionary<int, int> frequencies = new Dictionary<int, int>();
        foreach (int num in nums)
        {
            if (!frequencies.ContainsKey(num))
                frequencies[num] = 0;
            frequencies[num]++;
        }

        int maxFrequency = 0;
        foreach (var kvp in frequencies)
        {
            maxFrequency = Math.Max(maxFrequency, kvp.Value);
        }

        int frequencyOfMaxFrequency = 0;
        foreach (var kvp in frequencies)
        {
            if (kvp.Value == maxFrequency)
                frequencyOfMaxFrequency++;
        }

        return frequencyOfMaxFrequency * maxFrequency;
    }
}
