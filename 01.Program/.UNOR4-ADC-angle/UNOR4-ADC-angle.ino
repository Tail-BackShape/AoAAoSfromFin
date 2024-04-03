#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

const int finPin1 = A0;
const int finPin2 = A1;

void setup()
{
  Serial.begin(115200);

  while (!Serial)
    delay(1);

  pinMode(finPin1, INPUT);
  pinMode(finPin2, INPUT);
}

void loop()
{
  int value1 = analogRead(finPin1);
  int value2 = analogRead(finPin2);

  int degree1 = map(value1, 44, 977, 0, 270);
  int degree2 = map(value2, 44, 977, 0, 270);

  Serial.print("Value1: ");
  Serial.print(value1);
  Serial.print("\tValue2: ");
  Serial.print(value2);
  Serial.print("\tDegree1: ");
  Serial.print(degree1);
  Serial.print("\tDegree2: ");
  Serial.println(degree2);

  delay(100);
}
