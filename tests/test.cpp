#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "box_optimizer.hpp"
#include "cart_analysis.hpp"
#include "customer_loyalty.hpp"
#include "api_monitor.hpp"

TEST_CASE("Module 1: Box Fitting Optimizer") {
    std::vector<int> weights = {10, 20, 30, 40, 50};
    int capacity = 70;

    auto result = findItemsForBox(weights, capacity);

    REQUIRE(result.first == 2);
    REQUIRE(result.second == 3);
}

TEST_CASE("Module 2: Trending Products Across Carts") {
    std::vector<std::vector<std::string>> carts = {
        {"laptop", "mouse", "keyboard"},
        {"laptop", "mouse", "monitor"},
        {"mouse", "laptop", "webcam"}
    };

    auto common = commonProductsAcrossCarts(carts);

    REQUIRE(common.size() == 2);
    REQUIRE(std::find(common.begin(), common.end(), "laptop") != common.end());
    REQUIRE(std::find(common.begin(), common.end(), "mouse") != common.end());
}

TEST_CASE("Module 3: Customer Loyalty Tier") {
    auto tiers = createLoyaltyTiers();

    REQUIRE(getLoyaltyTier(tiers, 0) == "Bronze");
    REQUIRE(getLoyaltyTier(tiers, 499) == "Bronze");
    REQUIRE(getLoyaltyTier(tiers, 500) == "Silver");
    REQUIRE(getLoyaltyTier(tiers, 1200) == "Gold");
    REQUIRE(getLoyaltyTier(tiers, 5000) == "Platinum");
}

TEST_CASE("Module 4: API Endpoint Tracker") {
    std::vector<std::string> logs = {
        "/api/login", "/api/cart", "/api/checkout",
        "/api/cart", "/api/login", "/api/cart", "/api/login"
    };

    auto result = find_most_frequent_endpoints(logs);

    auto endpoints = result.first;
    int count = result.second;

    REQUIRE(count == 3);
    REQUIRE(endpoints.size() == 2);

    REQUIRE(std::find(endpoints.begin(), endpoints.end(), "/api/cart") != endpoints.end());
    REQUIRE(std::find(endpoints.begin(), endpoints.end(), "/api/login") != endpoints.end());
}
