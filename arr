#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        // Create a sorted copy with indices
        std::vector<std::pair<int, int>> indexed;
        indexed.reserve(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            indexed.push_back({arr[i], i});
        }
        
        // Sort by value
        std::sort(indexed.begin(), indexed.end());
        
        // Assign ranks
        std::vector<int> result(arr.size());
        int rank = 1;
        for (int i = 0; i < indexed.size(); i++) {
            // If this is the first element or different from previous, assign new rank
            if (i == 0 || indexed[i].first != indexed[i-1].first) {
                rank = (i == 0) ? 1 : rank + 1;
            }
            // If same as previous, keep same rank (rank variable unchanged)
            result[indexed[i].second] = rank;
        }
        
        return result;
    }
};
