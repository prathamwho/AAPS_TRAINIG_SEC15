//BRUTE
//push i = n-1 to n elements
//push i = 0 to n-k  elements
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        k = k % n; 
        for(int i = n - k; i < n; i++) {
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < n - k; i++) {
            ans.push_back(nums[i]);
        }
        nums = ans;
    }
};

//BETTER/OPTIMAL
// 1)reverse the array
// 2) reverse 0 - k part
// 3) reverse k+1 to n part
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
