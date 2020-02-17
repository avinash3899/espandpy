#include <ESP8266WiFi.h>
class Flasher
{
  int ledPin;
  long OnTime;
  long OffTime;
  int ledState;                
  unsigned long previousMillis;
  public:
  Flasher(int pin, long on, long off)
  {
  ledPin = pin;
  pinMode(ledPin, OUTPUT);     
    
  OnTime = on;
  OffTime = off;
  
  ledState = LOW; 
  previousMillis = 0;
  }
 
  void Update()
  {
    unsigned long currentMillis = millis();
     
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      ledState = LOW;
      previousMillis = currentMillis;
      digitalWrite(ledPin, ledState);
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;
      previousMillis = currentMillis;
      digitalWrite(ledPin, ledState);
    }
  }
};
char ssid[] = "AvinashNetGear";        
char pass[] = "Avinash!@#3899";         
byte ack[20];
IPAddress server(192,168,1,24);
WiFiClient client;
long int i = 0;
  Flasher led(4, 300, 600);
  Flasher blue(12, 300, 600);
  Flasher red(13, 300, 600);
  Flasher green(16, 300, 600); 

void setup() {
  Serial.begin(115200);   
         
  WiFi.begin(ssid, pass);      
  while (WiFi.status() != WL_CONNECTED) {
    
      led.Update();
  }
        
}

void loop () {
if (client.connect(server,8080))
  {

    while (client.connected() || client.available())
    {
      if (client.available())
      {
        String line = client.readStringUntil('\n');
        red.Update();
        Serial.println(line);
        while(!Serial.available())delay(5);
        String resp=Serial.readString();
        resp.getBytes(ack,20);
        client.write(ack,20);
        i++;
      }
    }
    Serial.print(i);
    Serial.println(" lines received");
    client.stop();
   while(true){delay(2000);};
  }
 
}
