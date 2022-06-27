#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en,d4, d5, d6, d7);

void setup() {
  
  lcd.begin(16, 2);
  lcd.print("Temp is loading");

  delay(1000);
  lcd.clear();
}

void loop() {
  const float BETA = 3950; // Beta Coefficient - acelasi cu al senzorului folosit

  // citim valoarea primita prin senzor
  int analogValue = analogRead(A0);

  // transformam voltajul primit de la senzor in grade celsius
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;

  //afisam temperatura
  lcd.print("Temp is: ");
  lcd.print(celsius);
  lcd.print(" C");

  lcd.setCursor(0,1);
  lcd.print("Fan speed: ");

  if(celsius < 30)
  {
    lcd.print("OFF");
  }

  if(celsius >= 30 && celsius < 50)
  {
    lcd.print("*");
  }

  if(celsius >= 50 && celsius < 60)
  {
    lcd.print("**");
  }

  if(celsius >= 60 && celsius < 70)
  {
    lcd.print("***");
  }

  if(celsius >= 70 && celsius < 80)
  {
    lcd.print("****");
  }

    if(celsius >= 80)
  {
    lcd.print("*****");
  }

  delay(500);
  lcd.clear();

}
