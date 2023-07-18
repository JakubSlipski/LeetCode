#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int flipgame(std::vector<int>& fronts, std::vector<int>& backs) {
        std::unordered_set<int> seen;
        int n = fronts.size();
        int answer = INT_MAX;

        for (int i = 0; i < n; i++) {
            seen.insert(fronts[i]);
            seen.insert(backs[i]);
        }

        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                seen.erase(fronts[i]);
            }
        }

        for (int num : seen) {
            answer = std::min(answer, num);
        }

        return answer == INT_MAX ? 0 : answer;
    }
};