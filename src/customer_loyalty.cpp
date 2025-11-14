#include "customer_loyalty.hpp"
#include <stdexcept>

std::map<int, std::string> createLoyaltyTiers() {
    std::map<int, std::string> tiers;
    tiers[0]    = "Bronze";
    tiers[500]  = "Silver";
    tiers[1000] = "Gold";
    tiers[2000] = "Platinum";
    return tiers;
}

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score) {
    if (tiers.empty()) return "";

    // upper_bound gives first key > score
    auto it = tiers.upper_bound(score);
    if (it == tiers.begin()) {
        // score < smallest key (shouldn't happen with 0 present) -> return first tier
        return it->second;
    }
    // move back to the greatest key <= score
    --it;
    return it->second;
}
