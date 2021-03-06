
#include <Wire.h>   
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Ustawienie adresu ukladu na 0x27

void setup()  
{
  lcd.begin();   
  lcd.backlight(); // zalaczenie podwietlenia 
  lcd.setCursor(0,0); 
  lcd.print("I na co sie");
  delay(500);
  lcd.setCursor(0,1); 
  lcd.print("gapisz ?");
}

void loop() 
{
   /*lcd.backlight(); // zalaczenie podswietlenia
   delay(5000);
   lcd.noBacklight(); // wylaczenie podswietlenia
   delay(5000);*/
}
