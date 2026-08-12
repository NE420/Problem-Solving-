lass Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
        {
            int check = target - nums[i]; 
            if(hash.find(check) != hash.end())//check if number is found in hashmap ie we saw it before
            {
                return {hash[check], i};
            }
            hash[nums[i]] = i;//if not found add the current number to hashmap to mark it as seen before 
        }
        return {};
    }
};
