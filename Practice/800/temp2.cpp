class Solution {
public:
    
long long merge(vector<int> &arr,int l,int mid,int r){
    int cnt = 0;
    int j = mid+1;
    
    for(int i=l;i<=mid;++i){
        while(j<=r && arr[i] > 2LL*arr[j]){
            ++j;
        }
        cnt += (j-(mid+1));//read no of ele to the left of right subarray ele
    }
        
    vector<int> temp;
    int left = l,right=mid+1;
    
    while((left <= mid) && (right<=r)){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }
        
    while(left <= mid){
        temp.push_back(arr[left++]);
    }
    
    while(right<=r){
        temp.push_back(arr[right++]);
    }
    
    for(int i=l;i<=r;++i){
        arr[i] = temp[i-l];
    }
    return cnt;
}

int mergesort(vector<int> &nums,int low,int high){
    if(low >= high){
        return 0;
    }
        int mid = (low+high)/2;
        int inv_count = mergesort(nums,low,mid);
        inv_count += mergesort(arr,mid+1,high);
        inv_count += merge(arr,low,mid,high);
    
    return inv_count;
}
    
  
    int reversePairs(vector<int>& nums) {
       return mergesort(nums,0,nums.size()-1);
    }
};