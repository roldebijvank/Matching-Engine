#include <gtest/gtest.h>
#include "engine/order.hpp"
#include "engine/order_book.hpp"

using namespace engine;

TEST(Sanity, Builds) {
  Order = { 1, Side::Buy, 1000, 2 };
  Trade = { 1, 2, 1000, 2 };
}

