#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();
}
void loop()
{ 
  int i, j;
  String str, s;
  char arr[1000] = {'1', '0', '1'};
  if (Serial.available())
  {
    getchar();
    str = Serial.readStringUntil('\n');
    //Serial.println('\n'+str);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(str);
    for (i = 0; str[i] != '\0'; ++i)
    {
      if (isdigit(str[i]) != 0)
      {
        s = String(int(str[i]) + 48, BIN);
      }
      else
      {
        s = String(int(str[i]), BIN);
      }
      if (s.length() != 6)
      {
        for (j = 0; s[j] != '\0'; ++j)
        {
          arr[i * 7 + j + 3] = s[j];
          arr[i * 7 + j + 4] = '\0';
        }
      }
      else
      {
        arr[i * 7 + 3] = '0';
        for (j = 0; s[j] != '\0'; ++j)
        {
          arr[i * 7 + j + 4] = s[j];
          arr[i * 7 + j + 5] = '\0'; 
        }
      }
    }
    for (i = 0; arr[i] != '\0'; ++i)
    {
      Serial.print(arr[i]);
      if (arr[i] == '1')
      {
        digitalWrite(13, HIGH);
      }
      else
      {
        digitalWrite(13, LOW);
      }
      delay(100);
      digitalWrite(13, LOW);
    }
  }
}
