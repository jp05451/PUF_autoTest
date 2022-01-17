#include <Arduino.h>

const int selectionLine[] = {2, 3, 4, 5, 6, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40};
const int dataLine[] = {A0, A1, A2, A3, A4, A5, A6, A7};
const bool WE_control = 1; //When selected LOW, a WRITE is conducted. When selected HIGH, a READ is conducted
const bool CE_control = 0; //When LOW, selects the chip. When HIGH, deselects the chip
const bool OE_control = 0; //Output Enable. Controls the direction of the I/O pins. When LOW, the I/O pins behave as outputs. When deasserted HIGH, I/O pins are tristated, and act as input data pins
const int WE = 52;
const int CE = 48;
const int OE = 50;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(WE, OUTPUT);
  digitalWrite(WE, WE_control);
  pinMode(CE, OUTPUT);
  digitalWrite(CE, CE_control);
  pinMode(OE, OUTPUT);
  digitalWrite(OE, OE_control);

  for (int i = 0; i < sizeof(selectionLine) / sizeof(selectionLine[0]); i++)
  {
    pinMode(selectionLine[i], OUTPUT);
  }
  for (int i = 0; i < sizeof(dataLine) / sizeof(dataLine[0]); i++)
  {
    pinMode(dataLine[i], INPUT);
  }
}

void readData()
{
  for (int i = 0; i < sizeof(dataLine) / sizeof(dataLine[0]); i++)
  {
    Serial.print(analogRead(dataLine[i]));
  }
  Serial.println();
}

void pufTest()
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 15; i++)
  {
    digitalWrite(selectionLine[i], 1);
    readData();
    digitalWrite(selectionLine[i], 0);
  }
  Serial.println("**************************************");
}

void loop()
{
  pufTest();
  delay(1000);
}
