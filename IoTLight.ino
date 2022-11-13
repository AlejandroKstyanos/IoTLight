/*
##########################################################################
Configuration and declarations for blynk and WiFi functions.
##########################################################################
*/

//Includes--------------------------------
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

//Defines---------------------------------
//Use here your own template credentials
#define BLYNK_TEMPLATE_ID       "TMPLcRB5Eolz"
#define BLYNK_DEVICE_NAME       "IoTLight"
#define BLYNK_AUTH_TOKEN        "A_R1MI_gdPrfcUcqH17V19wQMmlP4t06"
#define BLYNK_PRINT Serial      //Use it for check connection to your blynk on serial monitor

//Variables
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
char ssid[] = "INFINITUM64DC";
char pass[] = "UQs3CTyPyg";

//Initialization of NTP timer with UDP.

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "3.mx.pool.ntp.org",-0,6000);


/*
##########################################################################
Declarations and initializations of functions and variables
for the main program.
##########################################################################
*/

#define LED 2
int value = 0;

// Function for 
BLYNK_WRITE(V0)
{
  value = param.asInt();
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  
  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();
  lightRun();
}

void lightRun(){ 
  Serial.println("Switch value " + String(value));
  if(value == 1){
    digitalWrite(LED,HIGH);
  }else {
    digitalWrite(LED,LOW);
  }
  delay(1000);
}
