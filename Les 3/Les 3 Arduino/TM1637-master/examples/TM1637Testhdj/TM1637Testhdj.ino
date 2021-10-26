#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 8
#define DIO 9
#define KnopLinks 3
#define KnopRechts 12
#define KnopKlein 4
#define LEDGroenLinks 2
#define LEDGroenRechts 11
#define LEDRood 5
#define PotMeter A0
#define ContactDenderTijd 50

#define RapportInterval 2000

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
	SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
	SEG_C | SEG_E | SEG_G,                           // n
	SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
	};

TM1637Display display(CLK, DIO);

void setup()
{
  pinMode(KnopLinks, INPUT_PULLUP);
  pinMode(KnopRechts, INPUT_PULLUP);
  pinMode(KnopKlein, INPUT_PULLUP);
  pinMode(LEDGroenLinks, OUTPUT);
  pinMode(LEDGroenRechts, OUTPUT);
  pinMode(LEDRood, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  int k;
  int KnopLinksStatus;
  int KnopLinksWaardeNu;
  int KnopLinksStabiel;
  unsigned long TijdVanLaatsteStatus;
  unsigned long KnopLinksTijd;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);
  long LusTelling;
  unsigned long PuntenLinks;
  
  KnopLinksStatus = digitalRead(KnopLinks);
  KnopLinksStabiel = KnopLinksStatus;
  
  LusTelling = 0;
  PuntenLinks = 0;
  
  TijdVanLaatsteStatus = millis();
  
  // All segments on
  display.setSegments(data);  
  delay(TEST_DELAY);
  
  
  digitalWrite(LEDGroenLinks, HIGH);
  delay(300);
  digitalWrite(LEDGroenRechts, HIGH);
  digitalWrite(LEDGroenLinks, LOW);
  delay(300);
  digitalWrite(LEDGroenRechts, LOW);
  digitalWrite(LEDRood, HIGH);
  delay(300);
  digitalWrite(LEDRood, LOW);
  
  
  while(true) {
    KnopLinksWaardeNu = digitalRead(KnopLinks);
    if(millis()>TijdVanLaatsteStatus + RapportInterval) {
      Serial.print(digitalRead(KnopLinks));
      Serial.print("    KnopLinksWaardeNu=");
      Serial.print(KnopLinksWaardeNu);
      Serial.print("    KnopLinksStatus=");
      Serial.print(KnopLinksStatus);
      Serial.print("    LusTelling=");
      Serial.print(LusTelling);
      Serial.print("    PuntenLinks=");
      Serial.println(PuntenLinks);
      TijdVanLaatsteStatus = millis();
      LusTelling = 0;
    }
    if (KnopLinksWaardeNu != KnopLinksStatus) {
      digitalWrite(LEDGroenLinks,!KnopLinksWaardeNu);
      KnopLinksStatus = KnopLinksWaardeNu;
//      Serial.print(KnopLinksTijd);
//      Serial.print("    ");
//      Serial.print(millis());
      Serial.print(KnopLinksWaardeNu)
      Serial.print("    ");
      Serial.println(millis() - KnopLinksTijd );
      KnopLinksTijd = millis();
    }
        
        
    if ((millis() > KnopLinksTijd + ContactDenderTijd) && (KnopLinksWaardeNu != KnopLinksStabiel)) {
      if (KnopLinksWaardeNu == 0) PuntenLinks += 1;
      KnopLinksStabiel = KnopLinksWaardeNu; 
      
    }
    LusTelling = LusTelling + 1;
  }
  
  
  
  while(true) {
    digitalWrite(LEDGroenLinks,! digitalRead(KnopRechts));
    digitalWrite(LEDGroenRechts,! digitalRead(KnopLinks));
    digitalWrite(LEDRood, !digitalRead(KnopKlein));
    delay(500);
     
      for(k = 0; k < 4; k++)
	data[k] = 0xff;
      k = map(analogRead(PotMeter),0,1024,8,16);
      Serial.print(analogRead(PotMeter));
      Serial.print("   ");
      Serial.println(k);
      
      display.setBrightness(k);
      display.showNumberDec(analogRead(PotMeter), false, 4, 4);
      

  }
  
  
  // Selectively set different digits
  data[0] = 0b01001001;
  data[1] = display.encodeDigit(1);
  data[2] = display.encodeDigit(2);
  data[3] = display.encodeDigit(3);
  
  for(k = 3; k >= 0; k--) {
	display.setSegments(data, 1, k);
	delay(TEST_DELAY);
	}
	
  display.setSegments(data+2, 2, 2);
  delay(TEST_DELAY);
  
  display.setSegments(data+2, 2, 1);
  delay(TEST_DELAY);
  
  display.setSegments(data+1, 3, 1);
  delay(TEST_DELAY);
 
  
  // Show decimal numbers with/without leading zeros
  bool lz = false;
  for (uint8_t z = 0; z < 2; z++) {
	for(k = 0; k < 10000; k += k*4 + 7) {
		display.showNumberDec(k, lz);
		delay(TEST_DELAY);
	}
	lz = true;
  }
  
  // Show decimal number whose length is smaller than 4
  for(k = 0; k < 4; k++)
	data[k] = 0;
  display.setSegments(data);
  
  display.showNumberDec(153, false, 3, 1);
  delay(TEST_DELAY);
  display.showNumberDec(22, false, 2, 2);
  delay(TEST_DELAY);
  display.showNumberDec(0, true, 1, 3);
  delay(TEST_DELAY);
  display.showNumberDec(0, true, 1, 2);
  delay(TEST_DELAY);
  display.showNumberDec(0, true, 1, 1);
  delay(TEST_DELAY);
  display.showNumberDec(0, true, 1, 0);
  delay(TEST_DELAY);

  // Brightness Test
  for(k = 0; k < 4; k++)
	data[k] = 0xff;
  for(k = 0; k < 16; k++) {
    display.setBrightness(k);
    display.setSegments(data);
    delay(TEST_DELAY);
  }
    
  // Done!
  display.setSegments(SEG_DONE);
  
  while(1);
}
