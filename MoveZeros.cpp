void moveZeroes(vector<int>& nums) {
    if(nums.size() <= 1) return;
    int size = nums.size();
    int c = count(nums.begin(), nums.end(), 0);
    erase_if(nums, [](int x) {return x==0;});
    for(int i = 0; i < c; i++) nums.push_back(0);
}
