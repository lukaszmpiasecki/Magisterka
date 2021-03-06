#include "DHT.h"
#include <Wire.h>   
#include <LiquidCrystal_I2C.h> 
#define DHT11_PIN 8
DHT dht;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Ustawienie adresu ukladu na 0x27
void setup()
{
  Serial.begin(9600);
  dht.setup(DHT11_PIN);
  lcd.begin();   
  lcd.backlight(); // zalaczenie podwietlenia 
  lcd.setCursor(0,0); 
  lcd.print("PROGRAM");
  //delay(500);
  lcd.setCursor(0,1); 
  lcd.print("STARTUJE");
}
 
void loop()
{
  //Pobranie informacji o temperaturze
  int temperatura = dht.getTemperature();
  Serial.print(temperatura);
  Serial.println("*C");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURA");
  lcd.setCursor(0,1);
  lcd.print(temperatura);
  lcd.setCursor(3,1);
  lcd.print("st. C");
  delay(5000); //Odczekanie wymaganego czasu
  //Pobranie informacji o wilgotnosci
  int wilgotnosc = dht.getHumidity();
  Serial.print(wilgotnosc);
  Serial.print("%RH | ");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WILGOTNOSC");
  lcd.setCursor(0,1);
  lcd.print(wilgotnosc);
  lcd.setCursor(3,1);
  lcd.print("%");
  delay(5000); //Odczekanie wymaganego czasu
}
