class Solution {
public:

    int firstOcc(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] == target) {
                ans = mid;
                high = mid - 1;  // go left
            }
            else if(arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] == target) {
                ans = mid;
                low = mid + 1;   // go right
            }
            else if(arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        return {firstOcc(arr, target), lastOcc(arr, target)};
    }
};