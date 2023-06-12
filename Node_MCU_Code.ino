#define BLYNK_TEMPLATE_ID "TMPLUeoE95KX"
#define BLYNK_DEVICE_NAME "Weather and Pollution Monitoring"

#include<Wire.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
WidgetLED led4(V3);
WidgetLED led5(V4);
WidgetLED led6(V5);
WidgetLED led7(V6);

char auth[] = "VZrM6Ekrgur8JERPEliIBBvGOcPp--sk";              
char ssid[] = "Hotspot";                                      
char pass[] = "12345678@@##";

void setup() {
  Wire.begin();
  Serial.begin(9600);
   Blynk.begin(auth, ssid, pass);
}


void loop() {
  Blynk.run();
  Wire.requestFrom(2,15);
  String string,string1,string2,string3;
  do
  {
    char c = Wire.read();
    string = string+c;
    string1 = string.substring(0);
    string2 = string.substring(2);
    string3 = string.substring(5);
   } while (Wire.available());
   
 char buf1[10];
 char buf2[10];
 char buf3[10];
 
 Serial.println(string);
 string1.toCharArray(buf1, 10);
 int air = atoi(buf1);
 Serial.println(air);
 string2.toCharArray(buf2, 10);
 int temp = atoi(buf2);
 Serial.println(temp);
 string3.toCharArray(buf3, 10);
 int hum = atoi(buf3);
 Serial.println(hum);
  
    Blynk.virtualWrite(V0, (air));
    Blynk.virtualWrite(V1, String(temp));
    Blynk.virtualWrite(V2, String(hum));
    
    if (air<=50)
 {
 led4.on();
 delay(10);
 led4.off();
 delay(10);
 }
 else
 {
 led4.off();
 } 
if (air>=200)
 {
 led5.on();
 delay(10);
 led5.off();
 delay(10);
 }
 else
 {
 led5.off();
 } 
if (temp<=35)
 {
 led6.on();
 delay(10);
 led6.off();
 delay(10);
 }
 else
 {
 led6.off();
 } 
if (temp>=50)
 {
 led7.on();
 delay(10);
 led7.off();
 delay(10);
 }
 else
 {
 led7.off();
 }
} 
