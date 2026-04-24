#include <Arduino.h>

#include <DIYables_LCD_I2C.h>

uint8_t hand_1[8] = {
    0b00000, 0b00011, 0b01000, 0b00100, 0b01000, 0b00100, 0b00010, 0b00001};

uint8_t hand_2[8] = {
    0b00000, 0b00000, 0b10000, 0b01000, 0b00100, 0b00000, 0b00000, 0b00000};

uint8_t hand_down[8] = {
    0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b01111, 0b10000};

uint8_t ear_1[8] = {
    0b00000, 0b01110, 0b00101, 0b01010, 0b01010, 0b10011, 0b10001, 0b10001};

uint8_t ear_2[8] = {
    0b00000, 0b00000, 0b00000, 0b10000, 0b01000, 0b01000, 0b00100, 0b00000};

uint8_t eye[8] = {
    0b00000, 0b00000, 0b00110, 0b01001, 0b00000, 0b00000, 0b00000, 0b00000};

uint8_t back[8] = {
    0b00000, 0b10000, 0b01000, 0b00100, 0b00010, 0b00010, 0b00001, 0b00001};

uint8_t hand_back[8] = {
    0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11000, 0b00100};

DIYables_LCD_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();

  Serial.begin(115200);

  lcd.createChar(0, hand_1);
  lcd.createChar(1, hand_2);
  lcd.createChar(2, ear_1);
  lcd.createChar(3, ear_2);
  lcd.createChar(4, eye);

  lcd.createChar(6, hand_back);
  lcd.createChar(7, hand_down);

  lcd.setCursor(3, 0);
  lcd.write(2);
  lcd.write(3);

  lcd.setCursor(1, 1);
  lcd.write(7);
  lcd.write(6);

  // ушки
  // правое
  lcd.setCursor(7, 0);
  lcd.write(2);
  lcd.write(3);
  // левое
  lcd.setCursor(3, 0);
  lcd.write(2);
  lcd.write(3);

  // глаза
  // левое
  lcd.setCursor(3, 1);
  lcd.write(4);
  // правое
  lcd.setCursor(6, 1);
  lcd.write(0);
  lcd.write(1);
}

void loop()
{
  if (Serial.available())
  {
    lcd.setCursor(1, 1);
    lcd.write(0);
    lcd.write(1);

    lcd.setCursor(6, 1);
    lcd.write(7);
    lcd.write(6);

    Serial.println(Serial.read());
    delay(100);

    lcd.setCursor(1, 1);
    lcd.write(7);
    lcd.write(6);
    lcd.setCursor(6, 1);
    lcd.write(0);
    lcd.write(1);
  }
}