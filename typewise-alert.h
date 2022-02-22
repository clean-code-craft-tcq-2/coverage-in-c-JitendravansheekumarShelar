#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

#define PASSIVE_COOLING_LOWERLIMIT 0u
#define PASSIVE_COOLING_UPPERLIMIT 35u
#define HI_ACTIVE_COOLING_LOWERLIMIT 0u
#define HI_ACTIVE_COOLING_UPPERLIMIT 45u
#define MED_ACTIVE_COOLING_LOWERLIMIT 0u
#define MED_ACTIVE_COOLING_UPPERLIMIT 40u
