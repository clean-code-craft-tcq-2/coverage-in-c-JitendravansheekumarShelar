#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according : Lower limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according : Higher limits") {
  REQUIRE(inferBreach(36, 20, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according : Normal limits") {
  REQUIRE(inferBreach(24, 20, 30) == NORMAL);
}
