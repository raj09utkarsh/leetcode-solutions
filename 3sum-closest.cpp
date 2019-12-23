class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MIN, diff = INT_MAX;
        for(int i=0; i<n; i++){
            int sum = target - nums[i];
            
            int low = i+1, high = n-1;
            while(low < high){
                int x = nums[low] + nums[high];
                if(abs((x+nums[i]) - target) < diff){
                    ans = x+nums[i];
                    diff = abs((x+nums[i]) - target);
                }
                if(x == sum){
                    return target;
                }
                else if(x < sum){
                    low++;
                }
                else {
                    high--;
                }
            }
        }
        return ans;
    }
};