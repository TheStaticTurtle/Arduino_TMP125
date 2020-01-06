#include <SPI.h>

void setup() {
  Serial.begin(115200);
 
  Serial.print("beginTransaction");
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  //SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE2));
  Serial.println(" DONE");

  
  
  //Serial.print("endTransaction");
  //SPI.endTransaction();
  //Serial.println(" DONE");
}

void loop() {
  digitalWrite(SS, LOW);
  Serial.println("Sensor polled");
  delay(200);
 
  SPI.transfer(1);
  
  Serial.println("Reading");
  byte msb = SPI.transfer(0);
  Serial.print(msb,BIN);
  Serial.print(" / ");
  
  byte lsb = SPI.transfer(0);
  Serial.println(lsb,BIN);
  
  int m = (msb << 8 )| lsb;
  m = m & 0b0000111111111111;

  Serial.println(m,BIN);
  Serial.println(m);
  
  digitalWrite(SS, HIGH);

  delay(1000);
}
