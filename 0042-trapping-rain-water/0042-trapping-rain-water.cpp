class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int total = 0;

        while(left <= right){

            if(height[left] <= height[right]){

                if(leftMax > height[left]){
                    total += leftMax - height[left];
                }
                else{
                    leftMax = height[left];
                }

                left++;
            }

            else{

                if(rightMax > height[right]){
                    total += rightMax - height[right];
                }
                else{
                    rightMax = height[right];
                }

                right--;
            }
        }

        return total;
    }
};