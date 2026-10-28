#pragma once
#include "order.hpp"
#include <vector>
#include <optional>

using namespace engine;

class OrderBook {
private:

public:
  std::vector<Trade> submit(const Order &order);

  bool cancel(uint64_t id);

  std::optional<uint64_t> bestBidPrice();
  std::optional<uint64_t> bestAskPrice();
  uint32_t quantityResting(uint64_t price, Side side);
};
