class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        if(nums.empty())
        {
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int target_3=target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                int target_2=target_3 - nums[j];
                int front=j+1;
                int back=n-1;
                while(front<back)
                {
                    int two_sum=nums[front]+nums[back];
                    if(two_sum<target_2)
                    {
                        front++;
                    }
                    else if(two_sum>target_2)
                    {
                        back--;
                    }
                    else
                    {
                        vector<int>quardruplet(4,0);
                        quardruplet[0]=nums[i];
                        quardruplet[1]=nums[j];
                        quardruplet[2]=nums[front];               
                        quardruplet[3]=nums[back];
                        
                        res.push_back(quardruplet);
                        
                        while(front<back &&nums[front]==quardruplet[2])
                        {
                            front++;
                        }
                        while(front<back &&nums[back]==quardruplet[3])
                        {
                            back--;
                        }
                    }                    
                }
                while(j+1<n && nums[j+1]==nums[j])
                {
                    j++;
                } 
            }
            while(i+1<n && nums[i+1]==nums[i])
            {
                i++;
            }
        }
       return res; 
    }
    
};