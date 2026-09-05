#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2
LiquidCrystal_I2C lcd(0x27, 20, 40);

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void) {
  lcd.init();
  lcd.backlight();
  sensors.begin();
  Serial.begin(9600);
}

void loop(void) {
  sensors.requestTemperatures();

  float tempc = sensors.getTempByIndex(0);
  float tempF = (tempC * 9.0) / 5.0 + 32.0;

  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("Temp: ");
  lcd.print(tempF);
  lcd.print(byte(0xDF));
  lcd.print("F");

  lcd.setCursor(0, 1);
  delay(2000);

  if (tempF <= 63.0){
    lcd.print("Sweater/Jacket")
    delay(7000);
    return;
  }else if (tempF >= 70.0){
    lcd.print("T-shirt")
    delay(7000);
    return;
  }else{
    lcd.print("Light Two-layer")
    delay(7000);
    return;
  }
}