#include <ESP8266WiFi.h>
char ssid[] = "xxxxxx";        
char pass[] = "xxxxxx";         
byte ack[20];
IPAddress server(192,168,43,95);
WiFiClient client;
long int i = 0;
void setup() {
  Serial.begin(115200);               
  WiFi.begin(ssid, pass);      
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
   Serial.print("IP: ");     Serial.println(WiFi.localIP());
}

void loop () {
if (client.connect(server,8080))
  {

    while (client.connected() || client.available())
    {
      if (client.available())
      {
        String line = client.readStringUntil('\n');
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
