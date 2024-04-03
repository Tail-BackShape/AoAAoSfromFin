#include <SPI.h>

float Vref = 5.0;

const int _MISO = 4;  // AKA SPI RX
const int _MOSI = 7;  // AKA SPI TX
const int _CS = 5;
const int _SCK = 6;
SPISettings settings(1000000, MSBFIRST, SPI_MODE0);

void setup() {
  pinMode(_CS, OUTPUT);
  Serial.begin(9600);
  SPI.setCS(_CS);
  SPI.setRX(_MISO);
  SPI.setSCK(_SCK);
  SPI.setTX(_MOSI);
  SPI.begin();
}

void loop() {
  SPI.beginTransaction(settings);
  digitalWrite(_CS, LOW);
  byte highByte = SPI.transfer(0b01101000);  // CH0 singleEnd
  byte lowByte = SPI.transfer(0x00);         // dummy
  digitalWrite(_CS, HIGH);
  SPI.endTransaction();
  unsigned int dataCh0 = ((highByte & 0x03) << 8) + lowByte;
  float volts = dataCh0 * Vref / 1024;
  Serial.println("highByte= " + String(highByte, DEC) + "lowByte= " + String(lowByte, DEC));
  Serial.println("CH0 " + String(volts, 3) + "V");
}