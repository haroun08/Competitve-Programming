class Solution {
public:
    string getHappyString(int n, int k) {
        string result;
        int count = 0;
        generateHappyStrings(n, k, "", count, result);
        return result;
    }

private:
    void generateHappyStrings(int n, int k, string current, int& count, string& result) {
        if (current.size() == n) {
            count++;
            if (count == k) {
                result = current;
            }
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!current.empty() && current.back() == ch) continue;
            generateHappyStrings(n, k, current + ch, count, result);
            if (count == k) return;  
        }
    }
};
