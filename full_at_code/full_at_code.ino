#include <SoftwareSerial.h>

SoftwareSerial sim(50,52);//sim digital pin

void setup()
{
  Serial.begin(9600);
  sim.begin(9600);
  Serial.println("Starting...");//printin fast
}

void loop()
{
  
  sim.println("AT");
  delay(100);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(100);

 sim.println("ATH");
  delay(100);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(100);

sim.println("AT+CSQ");
  delay(100);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(100);

sim.println("AT+CGATT?");
  delay(100);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(100);

 sim.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(100);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(100);

 sim.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"");
  delay(100);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(100);

sim.println("AT+SAPBR=1,1");
  delay(100);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(1500);

 sim.println("AT+HTTPINIT");
  delay(1500);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(100);

 sim.println("AT+HTTPPARA=\"URL\",\"http://crash.microinstance.com/api/accident-log?device_number=33333&latitude=2222&longitude=11000000000000000111\"");
  delay(2000);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(100);

sim.println("AT+HTTPACTION=0");
  delay(4000);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(100);

 sim.println("AT+HTTPTERM");
  delay(1000);
  while(sim.available())
  {
    Serial.write(sim.read());
  }
 delay(1000);
}
