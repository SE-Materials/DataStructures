class Solution {
    
    int nextGreater(vector<int>& nums, int i) 
    {
        
        int n = nums.size();
        int j = i + 1;
        
        while ( j < n && nums[i] >= nums[j]) 
        {
            j++;
        }
        
        return j == n ? -1 : nums[j];
    }
    
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        
        unordered_map<int,int> numberToIndex;
        
        for (int i=0; i<nums2.size(); i++)
            if (numberToIndex.count(nums2[i]) == 0)
                numberToIndex[nums2[i]] = i;
                
        for (auto num1 : nums1)
        {
            int idx = numberToIndex[num1];
            // cout << num1 << " " << idx;
            
            int num2 = nextGreater(nums2, idx);
            // cout << " - " << num2 << endl;
            
            ans.push_back(num2);
        }
        
        
        return ans;
    }
};