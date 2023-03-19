class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else {
                mid++;
            }
        }
    }
};

/**
TC: O(n)
SC: O(1)

*/


/**
red = 0 whitle = 0 , blue = 5
[2,0,2,1,1,0]

red = 1 whitle = 0 , blue = 4
[0, 0, 2, 1, 1, 2]


red = 2 whitle = 1, blue = 4
[0, 0, 2, 1, 1, 2]


red = 3 whitle = 1, blue = 3
[0, 0, 1, 1, 2, 2]

*/








