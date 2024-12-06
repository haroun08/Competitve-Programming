class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        int result = 0;

        for(int number = 1 ;number<=n;number++){
            if(numberExist(banned,number)){
                continue;
            }
            maxSum -= number;

            if(maxSum < 0 ){
                break;
            }
            result++;
        }
        return result;

    }
private:
    bool numberExist(vector<int>& arr, int number){
        int left = 0;
        int right = arr.size() -1;

        while(left <= right){
            int mid = left + ((right - left)/2);
            if(arr[mid]==number) {
                return true;
            }
            if (arr[mid]>number){
                right = mid -1;
            }
            else {
                left = mid +1;
            }
        }
        return false;
    }
};