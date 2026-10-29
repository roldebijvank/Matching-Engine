#pragma once
#include "order.hpp"
#include <functional> // for std::greater
#include <list>
#include <map>
#include <optional>
#include <unordered_map>
#include <vector>

namespace engine {

class OrderBook {
public:
  std::vector<Trade> submit(const Order &order);

  bool cancel(uint64_t id);

  std::optional<int64_t> bestBidPrice() const;
  std::optional<int64_t> bestAskPrice() const;
  uint64_t quantityResting(int64_t price, Side side) const;

private:
  // use list since removing from middle is O(1)
  using Level = std::list<Order>;

  struct OrderRef {
    Side side;
    int64_t price;
    Level::iterator it;
  };

  // insert and read take O(log(n)) with n = # price levels
  std::map<int64_t, Level, std::greater<int64_t>> bids; // bids sorted highest first
  std::map<int64_t, Level> asks;                        // asks sorted lowest first

  std::unordered_map<uint64_t, OrderRef> orderRefs;
};

} // namespace engine