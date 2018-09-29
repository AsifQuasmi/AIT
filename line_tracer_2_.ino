const int mod1 = A0;
const int mod2 = A1;
const int mod3 = A2;
const int mod4 = A3;
const int mod5 = A4;
const int a = 4; //2
const int b = 5; //3
const int c = 6; //4
const int d = 7; //1
//#define debug

void goBackward()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}
void Stop()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void goForward()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
}
void softRight()
{ digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}
void Right()
{ digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}

void softLeft()
{ digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
}

void Left()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}
int val1, val2, val3, val4, val5;
//int avg;
void serialprint()
{
  Serial.print("val1::  ");
  Serial.println(val1);
  Serial.print("val2::  ");
  Serial.println(val2);
  Serial.print("val3::  ");
  Serial.println(val3);
  Serial.print("val4::  ");
  Serial.println(val4);
  Serial.print("val5::  ");
  Serial.println(val5);
  /* Serial.print("avg :: ");
    Serial.println(avg);*/
  Serial.println("_______________________");
  delay (400);
}


void setup() {

  Serial.begin(9600);

  pinMode(mod1, INPUT);
  pinMode(mod2, INPUT);
  pinMode(mod3, INPUT);
  pinMode(mod4, INPUT);
  pinMode(mod5, INPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  delay(1000);
}

void loop() {
  val1 = analogRead(mod1);
  val2 = analogRead(mod2);
  val3 = analogRead(mod3);
  val4 = analogRead(mod4);
  val5 = analogRead(mod5);
  // avg=(val1+val2-val4-val5);
#ifdef debug
  serialprint();
#endif
  if (val1 < 512 && val2 > 512 && val3 > 512 && val4 > 512 && val5 < 512)
  { goForward();
  }

  else if (val1 > 512 && val2 > 512 && val3 > 512 && val4 < 512 && val5 < 512)
  { do
    {
      softLeft();
    }
    while (val3 > 512 );
  }
  else if (val1 < 512 && val2 > 512 && val3 > 512 && val4 < 512 && val5 < 512)
  { do
    {
      softLeft();
    }
    while (val3 > 512 );
  }

  else if (val1 > 512 && val2 > 512 && val3 < 512 && val4 < 512 && val5 < 512)
  { do
    {
      Left();
    }
    while (val3 > 512);
  }
  else if (val1 > 512 && val2 < 512 && val3 < 512 && val4 < 512 && val5 < 512)
  { do
    {
      Left();
    }
    while (val3 > 512);
  }
  else if (val1 > 512 && val2 > 512 && val3 > 512 && val4 > 512 && val5 < 512)
  { do
    {
      Left();
    }
    while (val3 > 512);
  }
  else if (val1 > 512 && val2 > 512 && val3 > 512 && val4 > 512 && val5 < 512)
  { do
    {
      softLeft();
    }
    while (val3 > 512 );
  }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if (val1 < 512 && val2 > 512 && val3 > 512 && val4 > 512 && val5 > 512)
  { do
    {
      softRight();
    }
    while (val3 > 512);
  }
  else if (val1 < 512 && val2 < 512 && val3 > 512 && val4 > 512 && val5 > 512)
  { do
    {
      softRight();
    }
    while (val3 > 512);
  }
  else if (val1 < 512 && val2 < 512 && val3 > 512 && val4 > 512 && val5 < 512)
  { do
    {
      softRight();
    }
    while (val3 > 512);
  }

  else if (val1 < 512 && val2 < 512 && val3 < 512 && val4 > 512 && val5 > 512)
  { do
    {
      Right();
    }
    while (val3 > 512 );
  }
  else if (val1 < 512 && val2 < 512 && val3 < 512 && val4 < 512 && val5 > 512)
  { do
    {
      Right();
    }
    while (val3 > 512 );
  }
  else if (val1 < 512 && val2 > 512 && val3 > 512 && val4 > 512 && val5 > 512)
  { do
    {
      Right();
    }
    while (val3 > 512 );
  }
  else if (val1 > 512 && val2 > 512 && val3 > 512 && val4 > 512 && val5 > 512)
  {
    goForward();
  }
  else if (val1 < 512 && val2 < 512 && val3 < 512 && val4 < 512 && val5 < 512)
  {
    goBackward();
  }
  delay(0);
}
