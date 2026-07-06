    int search(vector<int>& nums, int target) {
        if(nums.size() <= 0) return -1;
        int mid = nums.size()/2;
        int left = 0;
        int right = nums.size()-1;
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        do {
            if(nums[mid] < target) {
                left = mid;
                mid = (mid + right)/2;
            }
            else if(nums[mid] > target) {
                right = mid;
                mid = (mid + left)/2;
            }
            else {
                return mid;
            }
        } while(mid > left && mid < right);
        
        return -1;
    }
