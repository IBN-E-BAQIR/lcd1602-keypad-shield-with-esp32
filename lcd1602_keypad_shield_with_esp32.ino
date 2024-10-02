#include <LiquidCrystal.h>

// Initialize the LCD with the chosen pins
//In arduino UNO lcd(rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(21, 19, 23, 22, 5, 4);

void setup() {
  pinMode(21, OUTPUT); // RS
  pinMode(19, OUTPUT); // EN
  pinMode(23, OUTPUT); // D4
  pinMode(22, OUTPUT); // D5
  pinMode(5, OUTPUT);  // D6
  pinMode(4, OUTPUT);  // D7

  // Start the LCD
  lcd.begin(16, 2);
  lcd.print("Test LCD!"); // Print something simple
}

int read_LCD_buttons() {
  int adc_key_in = analogRead(34);  // Change this to your analog pin
  if (adc_key_in > 4000) return 0;  // No button pressed
  if (adc_key_in < 100)   return 1;  // Right
  if (adc_key_in < 1100)  return 2;  // Up
  if (adc_key_in < 2400)  return 3;  // Down
  if (adc_key_in < 3400)  return 4;  // Left
  if (adc_key_in < 4000)  return 5;  // Select not working for me because it not return any value. May be issue is with my lcd keypad shield
  
  return 0;  // Default no button pressed
}

void loop() {
  lcd.setCursor(0, 1);
  int button = read_LCD_buttons();
  switch (button) {
    case 1: lcd.print("Right "); break;
    case 2: lcd.print("Up    "); break;
    case 3: lcd.print("Down  "); break;
    case 4: lcd.print("Left  "); break;
    case 5: lcd.print("Select"); break;
    default: lcd.print("No btn");
  }
}
