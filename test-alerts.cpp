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

TEST_CASE("Classify temperature according : Passive Cooling") {
  REQUIRE(classifyTemperatureBreach(0,20) == NORMAL);
}

TEST_CASE("Classify temperature according : Hi-Active limits") {
  REQUIRE(classifyTemperatureBreach(1,25) == NORMAL);
}

TEST_CASE("Classify temperature according : Med-Active limits") {
  REQUIRE(classifyTemperatureBreach(2,30) == NORMAL);
}

TEST_CASE("Classify temperature according : Default limits") {
  REQUIRE(classifyTemperatureBreach(3,0) == NORMAL);
}
