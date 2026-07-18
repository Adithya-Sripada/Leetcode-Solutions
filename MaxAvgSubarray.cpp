double findMaxAverage(vector<int>& nums, int k) {
    double total = 0.0;
    double max;
    for(int i = 0; i < k; i++) total += nums[i];
    max = total;
    if(k == nums.size()) return total/k;
    for(int i = 0, j = k; i+k < nums.size(); i++,j++){
        total = (total - nums[i]) + nums[j];
        if(total > max) max = total;
    }
    return max/k;
}
