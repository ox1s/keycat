#include <Arduino.h>

#include <DIYables_LCD_I2C.h>

uint8_t hand_first_part[8] = {
    0b00000,
    0b00011,
    0b01000,
    0b00100,
    0b01000,
    0b00100,
    0b00010,
    0b00001};

uint8_t hand_second_part[8] = {
    0b00000,
    0b00000,
    0b10000,
    0b01000,
    0b00100,
    0b00000,
    0b00000,
    0b00000};

uint8_t hand_first_part_down[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b01111,
    0b10000};

uint8_t ear_first_part[8] = {
    0b00000,
    0b01110,
    0b00101,
    0b01010,
    0b01010,
    0b10011,
    0b10001,
    0b10001};

uint8_t ear_second_part[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b10000,
    0b01000,
    0b01000,
    0b00100,
    0b00000};

uint8_t eye[8] = {
    0b00000,
    0b00000,
    0b00110,
    0b01001,
    0b00000,
    0b00000,
    0b00000,
    0b00000};

uint8_t hand_second_part_down[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b11000,
    0b00100};

uint8_t back[8] = {
    0b00000,
    0b10000,
    0b01000,
    0b00100,
    0b00010,
    0b00010,
    0b00001,
    0b00001};

DIYables_LCD_I2C lcd(0x27, 16, 2);

int left = 1;

void createChars()
{
  lcd.createChar(0, hand_first_part);
  lcd.createChar(1, hand_second_part);
  lcd.createChar(2, ear_first_part);
  lcd.createChar(3, ear_second_part);
  lcd.createChar(4, eye);
  lcd.createChar(6, hand_second_part_down);
  lcd.createChar(7, hand_first_part_down);
}
void printHandDown()
{
  lcd.write(7);
  lcd.write(6);
}

void printHandUp()
{
  lcd.write(0);
  lcd.write(1);
}

void printEar()
{
  lcd.write(2);
  lcd.write(3);
}

void printEye()
{
  lcd.write(4);
}

void setup()
{
  lcd.init();
  lcd.backlight();

  Serial.begin(115200);

  createChars();

  lcd.setCursor(1, 1);
  printHandDown();
  lcd.setCursor(6, 1);
  printHandUp();

  lcd.setCursor(7, 0);
  printEar();
  lcd.setCursor(3, 0);
  printEar();

  lcd.setCursor(3, 1);
  printEye();
  lcd.setCursor(5, 1);
  printEye();
}

void loop()
{
  if (Serial.available())
  {
    Serial.read();
    // left
    lcd.setCursor(1, 1);
    lcd.write(left == 1 ? 0 : 7);
    lcd.write(left == 1 ? 1 : 6);

    // right
    lcd.setCursor(6, 1);
    lcd.write(left == 1 ? 7 : 0);
    lcd.write(left == 1 ? 6 : 1);

    left = left == 1 ? 0 : 1;
  }
}