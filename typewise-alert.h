#pragma once

#define PASSIVE_COOLING_LOWERLIMIT 0u
#define PASSIVE_COOLING_UPPERLIMIT 35u
#define HI_ACTIVE_COOLING_LOWERLIMIT 0u
#define HI_ACTIVE_COOLING_UPPERLIMIT 45u
#define MED_ACTIVE_COOLING_LOWERLIMIT 0u
#define MED_ACTIVE_COOLING_UPPERLIMIT 40u

#define NoOfCoolingType 3u
#define NoOfBreachType 3u

//enum declarations
typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  TOO_LOW,
  TOO_HIGH,
  NORMAL
} BreachType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

//structure declarations
typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef struct
{
   CoolingType  CoolingType_en;
   int          CoolingLowerLimit;
   int          CoolingUpperLimit;
}coolingTypeInfo_st;

typedef struct
{
   BreachType   BreachType_en;
   char*        emailMessage;
}breachTypeInfo_st;

//function declarations
BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
int checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
int sendToController(BreachType breachType);
int sendToEmail(BreachType breachType);
int invokeAlertTarget(AlertTarget alertTarget,BreachType breachType);
int print_for_LOW_HIGH_breach(BreachType breachType,const char* recepient);
int sendMessageBasedOnbreachType(BreachType breachType,const char* recepient);

//variable declarations
extern const coolingTypeInfo_st coolingTypeInfo_pst[NoOfCoolingType];
extern const breachTypeInfo_st breachTypeInfo_pst[NoOfBreachType];
