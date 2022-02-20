/*
Bottone (NO) con debounce (tempo di attesa) Accende un led alla pressione di un bottone Resistenza da 10 kΩ
*/
const int BOTTONE = 2;      // dichiara il pin del Bottone
const int LED = 13;         // dichiara il pin del Led
const int Debounce = 50;    // dichiara il tempo di attesa in millisecondi (debounce)
int Stato = 0;              // dichiara lo stato del Bottone
int ultimoStatoBottone = LOW;   // dichiara l'ultimo stato del Bottone
int StatoLed = LOW;         // dichiara lo stato del Led
void setup() {
 pinMode(LED, OUTPUT);      // inizializza il pin digitale LED come output
 pinMode(BOTTONE, INPUT);   // inizializza il pin digitale BOTTONE come input
 Serial.begin (9600);       // inizializza la porta seriale
}
void loop() {
  Stato = digitalRead(BOTTONE);   // legge il valore del bottone
  if  (Stato != ultimoStatoBottone && Stato == HIGH) { // se lo stato del bottone attuale è diverso dall'ultimo stato del bottone e lo stato è alto
StatoLed = !StatoLed;       // 
  if (StatoLed == HIGH){          // se il bottone è schiacciato  
  digitalWrite (LED, HIGH);       // accende il led 
  Serial.println ("on");          // comunica sul monitor seriale lo stato del bottone “on”
  }
  else {              // altrimenti
  digitalWrite (LED, LOW);        // spegne il led
  Serial.println ("off");         // comunica sul monitor seriale lo stato del bottone “off”
  }
}
ultimoStatoBottone = Stato;
delay (Debounce);
}
