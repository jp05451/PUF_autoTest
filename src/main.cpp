#include <Arduino.h>
#define LEVEL 676
#define END_BYTES 8
#define BEGIN_BYTES 0

const int selectionLine[] = {2, 3, 4, 5, 6, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40};
const int dataLine[] = {A0, A1, A2, A3, A4, A5, A6, A7};
const bool CE_control = 0; // When LOW, selects the chip. When HIGH, deselects the chip
const bool OE_control = 0; // Output Enable. Controls the direction of the I/O pins. When LOW, the I/O pins behave as outputs. When deasserted HIGH, I/O pins are tristated, and act as input data pins
const bool WE_control = 1; // When selected LOW, a WRITE is conducted. When selected HIGH, a READ is conducted
const int CE = 48;
const int OE = 50;
const int WE = 52;

int seccess = 0; // secceful number
int times = 0;   // total number

bool first_data[END_BYTES - BEGIN_BYTES][8];
bool seecond_data[END_BYTES - BEGIN_BYTES][8];

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(WE, OUTPUT);
  digitalWrite(WE, WE_control);
  pinMode(CE, OUTPUT);
  digitalWrite(CE, CE_control);
  pinMode(OE, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(OE, OE_control);

  // selection line pin mode
  for (int i = 0; i < 8; i++)
  {
    pinMode(selectionLine[i], OUTPUT);
    digitalWrite(selectionLine[i], 0);
  }

  // dataline pin mode
  for (int i = 0; i < 8; i++)
  {
    pinMode(dataLine[i], INPUT);
  }
  for (int i = 0; i < 15; i++)
  {
    digitalWrite(selectionLine[i], 0);
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(13, 1);
    delay(100);
    digitalWrite(13, 0);
    delay(100);
  }
}

void readAnalogData()
{
  for (int i = 0; i < 8; i++)
  {
    double temp = analogRead(dataLine[i]);
    Serial.print(temp * 5 / 1023);
    Serial.print("\t");
  }
  Serial.println();
}
void readDigitalData()
{
  for (int i = 0; i < 8; i++)
  {
    int temp = analogRead(dataLine[i]);
    if (temp >= LEVEL * 0.5)
      Serial.print("1");
    else
      Serial.print("0");
    Serial.print(" ");
  }
  Serial.println();
}

void pushData(int line)
{
  for (int i = 0; i < 8; i++)
  {
    int temp = analogRead(dataLine[i]);
    if (temp >= LEVEL * 0.5)
      first_data[line][i] = 1;
    else
      first_data[line][i] = 0;
  }
}

bool compare()
{
  for (int i = 0; i < END_BYTES - BEGIN_BYTES; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (first_data[i][j] != seecond_data[i][j])
      {
        return 0;
      }
    }
  }
  return 1;
}

void copy()
{
  for (int i = 0; i < END_BYTES - BEGIN_BYTES; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      seecond_data[i][j] = first_data[i][j];
    }
  }
}
void pufTest()
{
  // change selection line signal
  for (int i = BEGIN_BYTES; i < END_BYTES; i++)
  {
    // read digital data
    digitalWrite(selectionLine[i], 1);
    // read every 8 bit
    readDigitalData();
    pushData(i);
    digitalWrite(selectionLine[i], 0);
  }

  Serial.println("--------------------------------------");
  // analog data
  for (int i = BEGIN_BYTES; i < END_BYTES; i++)
  {
    digitalWrite(selectionLine[i], 1);
    // read every 8 bit
    readAnalogData();
    digitalWrite(selectionLine[i], 0);
  }
  Serial.println("**************************************");

  // compare if two data same
  // if (compare() == 1)
  // {
  //   Serial.println("compare");
  //   seccess++;
  // }
  // else
  // {
  //   Serial.println("not compare");
  // }
  // copy();
  // Serial.println((double)seccess / times);
}

void loop()
{
  times++;
  Serial.println(LEVEL / 2);
  digitalWrite(7, 1);
  delay(1000);
  pufTest();

  digitalWrite(7, 0);
  delay(9000);
}
