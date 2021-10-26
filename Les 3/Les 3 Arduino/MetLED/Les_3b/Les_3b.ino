#include <TM1637Display.h>
// ==== De globale declaraties (gelden voor het hele programma) ==========================

// Pennen van de Arduino. We geven ze een naam zodat we in het programma een naam kunnen 
// gebruiken (dat is makkelijker) en omdat we dan, als we een wijziging moeten maken 
// (bijvoorbeeld een knop op een andere pin aansluiten), slechts op 1 plek een wijziging
// hoeven te maken.

// Knoppen
#define KnopLinks 3                  // De linker knop zit op pen 3
#define KnopRechts 12                // De rechter knop zit op pen 12
#define KnopKlein 4                  // De kleine knop linksonder zit op pen 4

// LED's
#define LEDGroenLinks 2              // De groene LED links is aangesloten op pen 2
#define LEDGroenRechts 11            // De rechter groene LED is aangesloten op pen 11
#define LEDRood 5                    // De rode LED zit op pen 5
#define LEDGroen 9                    // De rode LED zit op pen 5
#define LEDBlauw 6                    // De rode LED zit op pen 5
#define LEDNano 13                   // De kleine LED op de Arduino Nano zelf

// Analoge ingangen
#define PotMeter A0                  // De potentiometer (potmeter) is een regelbare 
					// weerstand. Die is aangesloten op pen A0

// De 4 cijfers worden bestuurd door een chip TM1637 die aan de onderkant zit 
// (je kunt het transparante plaatje omdraaien en dan zie je de chip met het nummer. 
// Je ziet dan ook dat er 4 pennen zijn: GND, VCC, CLK en DIO.
// VCC en GND zijn de draden voor de voeding.
// Die gaan naar resp. +5 volt en GND (= 0 volt)op de Arduino zodat de chip en het
// blok cijfers spanning krijgen.
// DIO staat voor Digitale Input / Output. Over deze draad gaat de data die vertelt welke
// cijfers moeten oplichten.
// CLK staat voor klok (clock in het Engels). Die vertelt wanneer de TM1637 chip op de 
// DIO draad de data moet bekijken.
#define CLK 7                        // Dit is de klok
#define DIO 8                        // Dit is de digitale input / output
// ==== setup ================================================================================
// Wat tussen de accolades achter setup staat wordt (eenmaal) uitgevoerd nadat de 
// Arduino is gestart.
TM1637Display VierCijfers(CLK, DIO);
void setup(){    // Dit is openingsaccolade die bij setup hoort.

  pinMode(KnopLinks, INPUT_PULLUP);    // De pen waaraan de linker knop zit is voor invoer
                                       // (input). 
                                       // En er moet een optrekweerstand (pullup) worden
                                       // geconfigureerd om te zorgen dat 
                                       // er een 5 volt signaal (HIGH) op de pen staat als de
                                       // knop NIET wordt ingedrukt.
                                       // Als er op de knop wordt gedrukt komt er 0 volt (LOW)
                                       // op.
  pinMode(KnopRechts, INPUT_PULLUP);   // Idem voor de rechter knop
  pinMode(KnopKlein, INPUT_PULLUP);    // Idem voor de kleine knop links onder
  
  pinMode(LEDGroenLinks, OUTPUT);      // De pen waaraan de linker groene LED zit is een
                                       // uitvoer (output).
  pinMode(LEDGroenRechts, OUTPUT);     // Idem voor de rechter groene LED.
  pinMode(LEDRood, OUTPUT);            // Idem voor de rode LED.
  
  Serial.begin(115200);                // Deze opdracht is nodig om straks te kunnen zien op 
                                       // de Raspberry Pi wat de Arduino aan het doen is.
                                       // 115200 wil zeggen dat de communicatie zal gaan met
                                       // 115200 bit/seconde.
                                       // Hoe je op de Raspberry Pi kunt zien wat de Arduino 
                                       // doet komt later.
}                                      // Dit is de sluitaccolade die bij setup() hoort. 
                                       // Dit sluit de rij opdrachten af die bij
                                       // het starten van de Arduino worden uitgevoerd.




 // ==== loop ================================================================================
// Wat tussen de accolades staat wordt uitgevoerd na setup(). En dat wordt eindeloos herhaald.

void loop(){
  int StatusKnopKleinNu;
  digitalWrite(LEDGroenLinks, HIGH);  // Laat de linker LED branden
  delay(500);                        // Wacht 1000 milliseconde (ms) = 1 seconde

  digitalWrite(LEDGroenLinks, LOW);   // Doe de linker LED weer uit
  delay(500);                        // Wacht 1000 milliseconde (ms) = 1 seconde
  
  digitalWrite(LEDRood, HIGH);        // Laat de rode LED branden
  delay(500);                          // Wacht 500 milliseconde (ms) = 0,5 seconde

  digitalWrite(LEDRood, LOW);         // Doe de rode LED weer uit
  delay(100);                         // Wacht 100 milliseconde (ms) = 0,1 seconde
  
  digitalWrite(LEDBlauw, HIGH);        // Laat de rode LED branden
  delay(500);                          // Wacht 500 milliseconde (ms) = 0,5 seconde

  digitalWrite(LEDBlauw, LOW);         // Doe de rode LED weer uit
  delay(100);                         // Wacht 100 milliseconde (ms) = 0,1 seconde
  

  digitalWrite(LEDGroen, HIGH);        // Laat de rode LED branden
  delay(500);                          // Wacht 500 milliseconde (ms) = 0,5 seconde

  digitalWrite(LEDGroen, LOW);         // Doe de rode LED weer uit
  delay(100);                         // Wacht 100 milliseconde (ms) = 0,1 seconde
  
  digitalWrite(LEDBlauw, HIGH);        // Laat de rode LED branden
  delay(100);                         // Wacht 100 milliseconde (ms) = 0,1 seconde  
  
  digitalWrite(LEDRood, HIGH);        // Laat de rode LED branden
  delay(100);                         // Wacht 100 milliseconde (ms) = 0,1 seconde
  digitalWrite(LEDGroen, HIGH);        // Laat de rode LED branden
  delay(1000);                         // Wacht 100 milliseconde (ms) = 0,1 seconde
  
  while (digitalRead(KnopKlein)==1) {
  }

  digitalWrite(LEDBlauw, LOW);        // Laat de rode LED branden
  delay(100);                         // Wacht 100 milliseconde (ms) = 0,1 seconde  
  
  digitalWrite(LEDRood, LOW);        // Laat de rode LED branden
  delay(100);                         // Wacht 100 milliseconde (ms) = 0,1 seconde
  digitalWrite(LEDGroen, LOW);        // Laat de rode LED branden
  delay(500);                         // Wacht 100 milliseconde (ms) = 0,1 seconde


  analogWrite(LEDBlauw, 255);
  delay(500);
  analogWrite(LEDRood, 255);
  delay(500);
  analogWrite(LEDGroen, 255);
  delay(500);  



  digitalWrite(LEDGroenRechts, HIGH);  // Laat de linker LED branden
  delay(500);                        // Wacht 1000 milliseconde (ms) = 1 seconde

  digitalWrite(LEDGroenRechts, LOW);   // Doe de linker LED weer uit
  delay(200);
  
  VierCijfers.setBrightness(15);                    // Zet de helderheid op 15. 8 = zwak, 
                                                    // 15 = fel
  VierCijfers.showNumberDec (1234, false, 4, 0);    // Laat het getal 1234 zien op 4 plekken 
                                                    // met het eerste cijfer 
                                                    // helemaal links (0)
  delay(1000);
  VierCijfers.showNumberDec (56, false, 2, 0);      // Laat het getal 56 zien met 2 cijfers,
                                                    // eerste cijfer helemaal links
  delay(1000);
  VierCijfers.showNumberDec (78, false, 2, 2);      // Laat het getal 78 zien met 2 cijfers, 
                                                    // start vanaf het derde cijfer (plek 2, 
                                                    // want het eerste cijfer is plek 0)
  delay(1000);
  const uint8_t TweeCijfersLeeg[] = {0, 0};         // declareer een rij van 2 cijfers en 
                                                    // maak ze allemaal 0
  VierCijfers.setSegments(TweeCijfersLeeg,2,0);     // Wis de linker 2 cijfers
  VierCijfers.setSegments(TweeCijfersLeeg,2,2);     // Wis de rechter 2 cijfers
  StatusKnopKleinNu = digitalRead(KnopKlein);

  if (StatusKnopKleinNu == LOW) {
    digitalWrite(LEDNano,HIGH);
  } else {
    digitalWrite(LEDNano,LOW);
  }
   int StatusKnopLinksNu;
  int StatusKnopLinksLaatst;  
  int PuntenLinks;
  int PuntenRechts;
  int StatusKnopRechtsNu;
  int StatusKnopRechtsLaatst;
  int LEDDrieKleurWaardeRood=255;
  int LEDDrieKleurWaardeGroen=255;
  int LEDDrieKleurWaardeBlauw=255;
  int LEDBeginWaarde;
  int PotMeterStandBegin;
  unsigned long StartTijd;            // De tijd (in milli seconde vanaf de
                                      // de start van de Arduino kan heel
                                      // groot worden. Dat past niet in een
                                      // int. Daar is de maximum waarde 32767. 
                                      // Daarom nemen we een long. 
                                      // En het getal zal nooit negatief worden,
                                      // daarom nemen we unsigned (zonder +/- teken,
                                      // dus alleen maar positieve getallen.
  unsigned long SpeelTijd = 15;       // de speeltijd is 15 seconde
  // ==== Hier begint het spel =============================================================
  while (true) {                                    // Herhaal dit eindeloos
    if (digitalRead(KnopKlein) == LOW) {            // Als het kleine knopje ingedrukt wordt 
                                                    // dan gaan we van start
      
      // ==== Stel nu eerst de speeltijd in                                                    
      VierCijfers.setSegments(TweeCijfersLeeg,2,0);     // Wis de linker 2 cijfers
      VierCijfers.setSegments(TweeCijfersLeeg,2,2);     // Wis de rechter 2 cijfers
      
      int i;
      int PotMeterStand;
      for (i=1; i<1000; i++) {                          // doe het 1000 keer om de spelers
                                                        // een beetje tijd te geven
        PotMeterStand = analogRead(PotMeter);           // lees de stand van de potmeter
      
        SpeelTijd = map(PotMeterStand,0,1024,5,60);     // vertaal het naar een brukkbare
                                                        // waarde voor de speeltijd
        VierCijfers.setSegments(TweeCijfersLeeg,2,0);     // Wis de linker 2 cijfers
        VierCijfers.setSegments(TweeCijfersLeeg,2,2);     // Wis de rechter 2 cijfers
        VierCijfers.showNumberDec(SpeelTijd, false,2, 1);   // laat de speeltijd zien

        PotMeterStandBegin = analogRead(PotMeter);           // lees de stand van de potmeter  
        LEDBeginWaarde = LEDDrieKleurWaardeRood;    
        while (digitalRead(KnopKlein) == LOW) {  
          PotMeterStand = analogRead(PotMeter);           // lees de stand van de potmeter
          LEDDrieKleurWaardeRood = LEDBeginWaarde + max(-LEDBeginWaarde, min(255 - LEDBeginWaarde, map(PotMeterStand-PotMeterStandBegin,-1024, 1024, 255, -255)));
          analogWrite(LEDRood, LEDDrieKleurWaardeRood);
          VierCijfers.showNumberDec(LEDDrieKleurWaardeRood, false,4, 0);   // laat de speeltijd zien
        }
        
        PotMeterStandBegin = analogRead(PotMeter);           // lees de stand van de potmeter  
        LEDBeginWaarde = LEDDrieKleurWaardeGroen;    
        while (digitalRead(KnopRechts) == LOW) {  
          PotMeterStand = analogRead(PotMeter);           // lees de stand van de potmeter
          LEDDrieKleurWaardeGroen = LEDBeginWaarde + max(-LEDBeginWaarde, min(255 - LEDBeginWaarde, map(PotMeterStand-PotMeterStandBegin,-1024, 1024, 255, -255)));
          analogWrite(LEDGroen, LEDDrieKleurWaardeGroen);
          VierCijfers.showNumberDec(LEDDrieKleurWaardeGroen, false,4, 0);   // laat de speeltijd zien
        }
        
        PotMeterStandBegin = analogRead(PotMeter);           // lees de stand van de potmeter  
        LEDBeginWaarde = LEDDrieKleurWaardeBlauw;    
        while (digitalRead(KnopLinks) == LOW) {  
          PotMeterStand = analogRead(PotMeter);           // lees de stand van de potmeter
          LEDDrieKleurWaardeBlauw = LEDBeginWaarde + max(-LEDBeginWaarde, min(255 - LEDBeginWaarde, map(PotMeterStand-PotMeterStandBegin,-1024, 1024, 255, -255)));
          analogWrite(LEDBlauw, LEDDrieKleurWaardeBlauw);
          VierCijfers.showNumberDec(LEDDrieKleurWaardeBlauw, false,4, 0);   // laat de speeltijd zien
        }
        
        
      }  // ==== PLAATS 3 ==== Op deze plek komt straks het instellen van de speeltijd ====                                              
     

      // ==== Voorbereidingen voor het spel ========
    
      StartTijd = millis();                         // Onthoud hoe laat het nu is
      PuntenLinks = 0;                              // Zet de punten van de linker speler op 
      PuntenRechts = 0;                                              // nul
      VierCijfers.showNumberDec(PuntenLinks, false, 2, 0);
      VierCijfers.showNumberDec(PuntenRechts, false, 2, 2);
                                                    // Vertoon het aantal punten van de linker
                                                    // speler in de twee linker cijfers     
      StatusKnopLinksNu = digitalRead(KnopLinks);   // Lees de status van de linker knop
      StatusKnopLinksLaatst = StatusKnopLinksNu;    // En dat is dan ook de beginwaarde
      
      StatusKnopRechtsNu = digitalRead(KnopRechts);
      StatusKnopRechtsLaatst = StatusKnopRechtsNu;
      while ((millis() < StartTijd + SpeelTijd * 1000) && (PuntenLinks < 99) && (PuntenRechts < 99) )  {
                                                    // Als de huidige tijd (millis()) kleiner
                                                    // is dan de starttijd plus de speeltijd
                                                    // (die we met 1000 vermenigvuldigen om 
                                                    // ook milliseconde te krijgen), dan 
                                                    // kunnen we doorgaan: de speeltijd is
                                                    // nog niet om. 
                                                    // Maar als de speler al 99 punten heeft 
                                                    // dan moeten we toch stoppen, want
                                                    // meer dan 99 punten kunnen we niet
                                                    // laten zien.
        StatusKnopLinksNu = digitalRead(KnopLinks);
        if (StatusKnopLinksNu == LOW && StatusKnopLinksLaatst == HIGH) {
                                                    // Als de knop nu LOW is en hij was HIGH
                                                    // in de vorige keer dat we door de lus
                                                    // kwamen, dan is de knop nu net ingedrukt
          PuntenLinks = PuntenLinks + 1;            // De linker speler krijgt er een punt bij
          VierCijfers.showNumberDec(PuntenLinks, false, 2, 0);
                                                    // Vertoon het aantal punten van de linker
                                                    // speler in de twee linker cijfers 
        }
        StatusKnopRechtsNu = digitalRead(KnopRechts);
        if (StatusKnopRechtsNu == LOW && StatusKnopRechtsLaatst == HIGH) {
                                                    // Als de knop nu LOW is en hij was HIGH
                                                    // in de vorige keer dat we door de lus
                                                    // kwamen, dan is de knop nu net ingedrukt
          PuntenRechts = PuntenRechts + 1;            // De linker speler krijgt er een punt bij
          VierCijfers.showNumberDec(PuntenRechts, false, 2, 2);
                                                    // Vertoon het aantal punten van de linker
                                                    // speler in de twee linker cijfers 
        }
        StatusKnopLinksLaatst = StatusKnopLinksNu;  // Onthoud de waarde voor de volgende keer  
                                                    // dat we door de lus komen// ==== PLAATS 1 ==== Hier komen straks de opdrachten die kijken naar de knoppen. 
        StatusKnopRechtsLaatst = StatusKnopRechtsNu;
      }
      // ==== PLAATS 2 ==== Hier komen straks de opdrachten om de winnaar te laten zien.
      // Deze ronde is afgelopen. Laat nu de punten van de winnaar, of van beide bij gelijk
      // spel knipperen. Dat doen we door eerst de cijfers van de winnaar (of beiden) weg te
      // halen en dan beide weer te laten zien. 
      while (digitalRead(KnopKlein) == HIGH) {              // Als de kleine knop wordt
                                                            // ingedrukt dan stoppen we met
                                                            // te laten zien wie heeft
                                                            // gewonnen.

        if (PuntenLinks >= PuntenRechts) {                  // Als Links heeft gewonnen of als
                                                            // het gelijk is ...
          VierCijfers.setSegments(TweeCijfersLeeg,2,0);     // Wis de linker 2 cijfers
        }

        if (PuntenRechts >= PuntenLinks) {
          VierCijfers.setSegments(TweeCijfersLeeg,2,2);     // Wis de rechter 2 cijfers
        }  

        delay (100);
        VierCijfers.showNumberDec(PuntenLinks, false, 2, 0);
        VierCijfers.showNumberDec(PuntenRechts, false, 2, 2);
        delay (100);        
      }
    }
  }
  
}

