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
    auto it = tiers.upper_bound(score);
    if (it == tiers.begin()) {
        return it->second;
    }
    --it;
    return it->second;
}
