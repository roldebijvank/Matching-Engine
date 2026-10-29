#pragma once
#include <cstdint>

namespace engine {

enum class Side {
  Buy,
  Sell,
};

struct Order {
  uint64_t id;
  Side side;
  int64_t ticks;
  uint32_t quantity;
};

struct Trade {
  uint64_t buyId;
  uint64_t sellId;
  int64_t execTicks;
  uint32_t quantity;
};

} // namespace engine