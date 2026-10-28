#include <LiquidCrystal.h>

// Initialize the library with the interface pins: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Custom character design (Heart pixel array)
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

void setup() {
  // Set up the LCD's number of columns and rows (16x2)
  lcd.begin(16, 2);
  
  // Register custom character at index 0
  lcd.createChar(0, heart);
}

void loop() {
  // -------------------------------------------------------------
  // FEATURE 1 & 5: Position Text & Print Text
  // -------------------------------------------------------------
  lcd.clear();
  lcd.setCursor(0, 0);       // Position cursor at Column 0, Row 0
  lcd.print("1. Print Text");
  lcd.setCursor(0, 1);       // Position cursor at Column 0, Row 1 (Positioning)
  lcd.print("5. Positioned!");
  delay(3000);

  // -------------------------------------------------------------
  // FEATURE 2: Scroll Text
  // -------------------------------------------------------------
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("2. Scroll Text");
  delay(1000);
  for (int i = 0; i < 8; i++) {
    lcd.scrollDisplayLeft();
    delay(400);
  }
  delay(1000);

  // -------------------------------------------------------------
  // FEATURE 3: Make Custom Characters
  // -------------------------------------------------------------
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("3. Custom Char:");
  lcd.setCursor(0, 1);
  lcd.write(byte(0));        // Display the heart custom character
  lcd.print(" NC A&T ");
  lcd.write(byte(0));
  delay(3000);

  // -------------------------------------------------------------
  // FEATURE 4: Blink Text / Cursor
  // -------------------------------------------------------------
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("4. Blink Text");
  lcd.blink();               // Enable blinking cursor effect
  delay(3000);
  lcd.noBlink();             // Disable blinking cursor
}