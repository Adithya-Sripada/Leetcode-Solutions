
int majorityElement(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    map<int, int> m;
    for(int i : nums) {
        try{
            m.at(i) += 1;
            if(m.at(i) > nums.size()/2) return i;
        }
        catch(const std::out_of_range& ex) {
            m.insert(std::pair<int, int>{i, 1});
        }
    }
    return 0;
}
