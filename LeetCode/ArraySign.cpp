#include <vector>

class Solution {
public:
    int arraySign(std::vector<int>& nums) {
        int product = 1;
        for (int num : nums) {
            if (num == 0) {
                return 0; 
            } else if (num < 0) {
                product *= -1; 
            }
        }
        return product > 0 ? 1 : -1; 
    }
};
