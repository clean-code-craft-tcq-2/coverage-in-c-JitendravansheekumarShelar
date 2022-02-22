#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(36, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(24, 20, 30) == NORMAL);
}

TEST_CASE("Classify temperature according to Cooling Type") {
  REQUIRE(classifyTemperatureBreach(0,-20) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(1,60) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(2,30) == NORMAL);
}

TEST_CASE("Invoke Alert Target to send email") {
  REQUIRE(invokeAlertTarget(0,TOO_LOW) == 0);
  REQUIRE(invokeAlertTarget(1,TOO_HIGH) == 1);
}

TEST_CASE("Check the breach & Alert the target") {
  BatteryCharacter batteryChar;
  batteryChar.coolingType = 1;
  REQUIRE(checkAndAlert(0,batteryChar,-20) == 0);
  REQUIRE(checkAndAlert(1,batteryChar,60) == 1);
}

TEST_CASE("Send message to Controller") {
  REQUIRE(sendToController(TOO_LOW) == 0);
  REQUIRE(sendToController(TOO_HIGH) == 0);
}

TEST_CASE("Print message for low or High breach") {
  REQUIRE(print_for_LOW_HIGH_breach(TOO_LOW,"Low") == 1);
  REQUIRE(print_for_LOW_HIGH_breach(TOO_HIGH,"High") == 1);
}

TEST_CASE("Send information to print") {
  REQUIRE(sendMessageBasedOnbreachType(TOO_LOW,"Low") == 1);
  REQUIRE(sendMessageBasedOnbreachType(TOO_HIGH,"High") == 1);
}

TEST_CASE("Send to email") {
  REQUIRE(sendToEmail(TOO_LOW) == 1);
  REQUIRE(sendToEmail(TOO_HIGH) == 1);
  REQUIRE(sendToEmail(NORMAL) == 1);
}
