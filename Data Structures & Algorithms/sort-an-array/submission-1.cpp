class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int left = low;
        int right = high;
        while(left < right) {
            while (nums[left] <= pivot && left <= high) {
                left++;
            }
            while (nums[right] > pivot && right >= low) {
                right--;
            }
            if (left < right) {
                swap(nums[left], nums[right]);
            }
        }
        swap(nums[low], nums[right]);
        return right;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int pIndex = partition(nums, low, high);
        quickSort(nums, low, pIndex - 1);
        quickSort(nums, pIndex + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};