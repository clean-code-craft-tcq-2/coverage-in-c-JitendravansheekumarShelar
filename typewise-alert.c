#include "typewise-alert.h"
#include <stdio.h>

const coolingTypeInfo_st coolingTypeInfo_pst[NoOfCoolingType] = 
            {/*   COOLING TYPE                   LOWER LIMIT                          UPPER LIMIT */
                {PASSIVE_COOLING         ,PASSIVE_COOLING_LOWERLIMIT         ,PASSIVE_COOLING_UPPERLIMIT},\
                {HI_ACTIVE_COOLING       ,HI_ACTIVE_COOLING_LOWERLIMIT       ,HI_ACTIVE_COOLING_UPPERLIMIT},\
                {MED_ACTIVE_COOLING      ,MED_ACTIVE_COOLING_LOWERLIMIT      ,MED_ACTIVE_COOLING_UPPERLIMIT}
            };
            
const breachTypeInfo_st breachTypeInfo_pst[NoOfBreachType] = 
            {/*   BREACH TYPE               MESSAGE */
                {TOO_LOW                ,"Hi, the temperature is too low\n"},\
                {TOO_HIGH               ,"Hi, the temperature is too high\n"},\
                {NORMAL                 ,""}
            };

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {

  return inferBreach(temperatureInC, coolingTypeInfo_pst[coolingType].CoolingLowerLimit, 
  coolingTypeInfo_pst[coolingType].CoolingUpperLimit);
}

int invokeAlertTarget(AlertTarget alertTarget,BreachType breachType)
{
    if(alertTarget == TO_CONTROLLER)
        return sendToController(breachType);
    if(alertTarget == TO_EMAIL)
        return sendToEmail(breachType);
}

int checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

      return invokeAlertTarget(alertTarget,breachType);
}

int sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return 0;
}

int print_for_LOW_HIGH_breach(BreachType breachType,const char* recepient)
{
    printf("To: %s\n", recepient);
    if (breachTypeInfo_pst[breachType].emailMessage != "")
        printf("%s",breachTypeInfo_pst[breachType].emailMessage);
        
    return 1;
}

int sendMessageBasedOnbreachType(BreachType breachType,const char* recepient)
{
    if ((breachType == TOO_LOW) || (breachType == TOO_HIGH))
        return print_for_LOW_HIGH_breach(breachType,recepient);
    
    return 1;
}

int sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  
  return sendMessageBasedOnbreachType(breachType,recepient);
}
