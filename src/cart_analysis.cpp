#include "cart_analysis.hpp"
#include <unordered_map>
#include <vector>
#include <algorithm>

std::vector<std::string> commonProductsAcrossCarts(const std::vector<std::vector<std::string>>& carts) {
    std::vector<std::string> result;
    if (carts.empty()) return result;

    std::unordered_map<std::string,int> count;
    // Each cart has distinct products (per spec) but we'll protect against duplicates anyway:
    for (const auto& cart : carts) {
        for (const auto& product : cart) {
            // increment count for product
            ++count[product];
        }
    }

    int n = static_cast<int>(carts.size());
    for (const auto& kv : count) {
        if (kv.second == n) result.push_back(kv.first);
    }

    std::sort(result.begin(), result.end());
    return result;
}
