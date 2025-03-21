//BRUTE (TC: O(N^2), SC: O(1))
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i <= n + 1; i++) { 
            bool found = false;
            for (int num : nums) {
                if (num == i) {
                    found = true;
                    break;
                }
            }
            if (!found) return i;
        }
        return n + 1; // This line will never be reached
    }
};

//BETTER
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i <= n + 1; i++) {
        if (numSet.find(i) == numSet.end()) return i;
    }
    return n + 1;
}
};

//OPTIMAL
class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while (i < n) {
            if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1 ||
                arr[i] == arr[arr[i] - 1])
                i++;
            else
                swap(arr[i], arr[arr[i] - 1]);
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1)
                return i + 1;
        }
        return n+1;
    }
};
