//BRUTE
/**
1) Traverse the array and mark the index as "j";
2) Traverse again from j to size and use a third variable to swap with non zero element
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j =0;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        for(int i =j; i<nums.size();i++)
        if(nums[i] !=0){
           int temp = nums[i];
           nums[i] = nums[j];
           nums[j] = temp;
           j++;
        }
    }
};

//BETTER
/*
1) Find non zero element and add them to the begining of array
2) Fill the rest of the array with zeroes
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[index++] = nums[i];
            }
        }
        while(index<nums.size()){
            nums[index++]=0;
        }
    }
};

//OPTIMAL
/*
1) Do swapping in one pass and move zeroes to the right
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[j], nums[i++]);
            }
        }
    }
};
