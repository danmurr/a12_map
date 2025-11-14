#include "api_monitor.hpp"
#include <unordered_map>
#include <algorithm>

std::pair<std::vector<std::string>, int> find_most_frequent_endpoints(const std::vector<std::string>& log_data) {
    std::unordered_map<std::string,int> freq;
    for (const auto& ep : log_data) ++freq[ep];

    int max_count = 0;
    for (const auto& kv : freq) {
        if (kv.second > max_count) max_count = kv.second;
    }

    std::vector<std::string> top;
    for (const auto& kv : freq) {
        if (kv.second == max_count) top.push_back(kv.first);
    }

    std::sort(top.begin(), top.end());
    return {top, max_count};
}
