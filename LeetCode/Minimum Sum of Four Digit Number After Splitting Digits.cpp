class Solution {
public:
    int minimumSum(int num) {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string temp = to_string(num);

        sort(temp.begin(), temp.end());

        int left = 0, right = temp.length() - 1;

        int sum = 0;

        while (left < right) {
            sum += (temp[left] - '0') * 10 + (temp[right] - '0');
            left++;
            right--;
        }

        if (left == right)
            sum += temp[left] - '0';

        return sum;
    }
};
