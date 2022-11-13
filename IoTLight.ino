/*
##########################################################################
Configuration and declarations for blynk and WiFi functions.
##########################################################################
*/

//Defines & declarations---------------------------------
//Use here your own template credentials
#define BLYNK_TEMPLATE_ID       "TMPLCQ23_1R8"
#define BLYNK_DEVICE_NAME       "MainComputer"
#define BLYNK_AUTH_TOKEN        "dYf-F21oVlNqwUNM5SIRoqJ3TV-539Wb"
#define BLYNK_PRINT Serial      //Use it for check connection to your blynk server on serial monitor
#include <BlynkSimpleEsp8266.h>

//Variables
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
char ssid[] = "INFINITUM64DC";
char pass[] = "UQs3CTyPyg";


/*
##########################################################################
Declarations and initializations of functions and variables
for the main program.
##########################################################################
*/

#define LED 2
int value = 0;
int light1_status = 0;
BlynkTimer timer;


//Functions------------------------------------------------------------------

// Function for get data from the blynk button
BLYNK_WRITE(V0)
{
  value = param.asInt();
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(LED,OUTPUT);

  //Connect to blynk console server.
  Blynk.begin(auth, ssid, pass);

  //Set interval for send data to Blynk for avoid disconnection from
  //flooding data.
  timer.setInterval(500L, get_status); 
  
}

void loop()
{
  
  Blynk.run(); //Run blynk services.
  
  lightRun(); // Run IoT Function.
   
  timer.run(); //Run blynk datasender timer.
}

void lightRun(){
  //Discomment this to debug this function works.
  //Serial.println("Switch value " + String(value));
  if(value == 1){
    digitalWrite(LED,HIGH);
    light1_status = 1;
  }else {
    digitalWrite(LED,LOW);
    light1_status = 0;
  }
}

//Sends status from light1 to blynk server.
void get_status(){
  Blynk.virtualWrite(V1,light1_status); 
}
