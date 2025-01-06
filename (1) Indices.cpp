#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_map;  
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i}; 
        }
        num_map[nums[i]] = i; 
    }
    return {};
}

int main() {
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    auto result1 = twoSum(nums1, target1);
    std::cout << "[" << result1[0] << "," << result1[1] << "]" << std::endl;

    return 0;
}