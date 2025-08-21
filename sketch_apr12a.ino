#include <LiquidCrystal_I2C.h>
#include<string.h>
#include<stdlib.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();

}
void loop()
{
  char arr[1000];
  char out[500];
  int i = 0, k = 0;
  if ((digitalRead(12)) == 1)
  {
    delay(100);
    if (digitalRead(12) == 0)
    {
      delay(100);
      if ((digitalRead(12)) == 1)
      {
        while (true)
        { char var;
          if (digitalRead(12) == 0)
          {
            var = '1';
          }
          else
          {
            var = '0';
          }
          //Serial.print(var);
          arr[i] = char(var);
          arr[i + 1] = '\0';
          if (i >= 7 && i % 7 == 0 && arr[i - 6] == '0' && arr[i - 5] == '0' && arr[i - 4] == '0' && arr[i - 3] == '0' && arr[i - 2] == '0' && arr[i - 1] == '0' && arr[i] == '0')
          {
            break;
          }
          ++i;
          delay(100);
        }
        for (int i = 0; arr[i + 1] != '\0'; i++)
        {
          arr[i] = arr[i + 2];
        }
        /*Serial.print('\n');
        for (int j = 0; j <= i; ++j)
        {
          Serial.print(arr[j]);
        }
        Serial.println();*/
        i = 0;
        char c;
        while (c != '\0')
        {
          char bin[8];
          for (int j = 0; j < 7; ++j)
          {
            bin[j] = arr[i];
            bin[j + 1] = '\0';
            ++i;
          }
          c = strtol(bin, 0, 2);
          //Serial.print(c);
          out[k++] = c;
          out[k] = '\0';
        }
        k=0;
        lcd.clear();
        lcd.setCursor(0,0);
        while(out[k]!='\0')
        {
          lcd.print(out[k]);
          if(k>=14)
          {
            lcd.command(0x18);
          }
          delay(250);
          k++;
        }
      }
      //Serial.println();
    }
  }
}
