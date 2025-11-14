#include "box_optimizer.hpp"
#include <unordered_map>
#include <algorithm>

std::pair<int,int> findItemsForBox(const std::vector<int>& item_weights, int box_capacity) {
    // map weight -> index (first occurrence)
    std::unordered_map<int,int> idx;
    for (int i = 0; i < (int)item_weights.size(); ++i) {
        int w = item_weights[i];
        int need = box_capacity - w;
        auto it = idx.find(need);
        if (it != idx.end()) {
            int a = it->second;
            int b = i;
            if (a > b) std::swap(a,b);
            return {a,b};
        }
        // store current weight -> index
        // only store first occurrence (not necessary but fine)
        if (idx.find(w) == idx.end()) idx[w] = i;
    }
    return {-1, -1};
}
