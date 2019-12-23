class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        
        int n = nums.size();
        for(int i=0; i<n-3; i++) 
        {
            if(i == 0 || nums[i]!=nums[i-1])
            {
                int target2 = target - nums[i];
                // now the problem turns into 3sum problem with target as target2
                for(int j=i+1; j<n-2; j++) 
                {
                    if(j == i+1 || nums[j] != nums[j-1])
                    {
                        int target3 = target2 - nums[j];

                        int low = j+1, high = n-1;
                        while(low < high)
                        {
                            int sum = nums[low] + nums[high];
                            if(sum == target3)
                            {
                                vector<int> v;
                                v.push_back(nums[i]);
                                v.push_back(nums[j]);
                                v.push_back(nums[low]);
                                v.push_back(nums[high]);
                                ans.push_back(v);

                                while(low<high && nums[low] == nums[low+1])
                                {
                                    low++;
                                }
                                low++;
                                while(low < high && nums[high] == nums[high-1])
                                {
                                    high--;
                                }
                                high--;
                            }
                            else if(sum < target3){
                                while(low<high && nums[low] == nums[low+1])
                                {
                                    low++;
                                }
                                low++;
                            }
                            else{
                                while(low < high && nums[high] == nums[high-1])
                                {
                                    high--;
                                }
                                high--;
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};