#include <map>

bool containsDuplicate(std::vector<int>& nums) {
    std::map<int, int> m;
    for(int i : nums) {
        if(m.contains(i)) return true;
        m.insert(std::pair<int, int>{i, 1});
    }
    return false;
}