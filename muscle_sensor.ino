

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "XXXXXXXX";
const char* pass = "XXXXXXXX";

const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;

const int threshold = 1000;
int led = 2;           // the PWM pin the LED is attached to

WiFiClient espwifi;
PubSubClient client(espwifi);
  
void setup() 
{
  pinMode(led, OUTPUT);
  Serial.begin(115200); 
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
   }
  Serial.println("wifi connected");
   client.setServer(mqttServer,mqttPort);
   while(!client.connected())
   {
   if(client.connect("muscleSensor"))
    {
      Serial.println("mqtt established");
    }
   }
}

void loop() 
{
 int y1 = analogRead(A0);
 if(y1>threshold)
  {
  digitalWrite(led,LOW);
  client.publish("muscle/XXXX/mini","Person in danger");
  
  Serial.println("data sent");
  }
 digitalWrite(led,HIGH);
 Serial.println(y1);
 client.loop();
 delay(1500);
}
