//Mateusz Gajda
//Stan wyjścia w chwili początkowej - lampka zgaszona
//Kodowanie stanów:
//00
//11
//10
//01
int ButtonPin =12;//Przycisk
int RelayPin=5;//Control of Relay
bool Q1 = 0;
bool M1 = 0;
bool M2 = 0;
bool M1p = 0;
bool M2p = 0;
int I1 = 1;

void setup() {
  pinMode(ButtonPin, INPUT);
  pinMode(RelayPin, OUTPUT);
  Serial.begin(9600);
  }

void loop() {

  Serial.println();
  I1 = digitalRead(ButtonPin);
  Serial.print(I1);
  Serial.println();
  
  M1p = (I1 == LOW && M1) || (I1 == HIGH && !M1 && !M2) || (M1 && M2);
  M2p = (I1 == HIGH); 

  M1 = M1p;
  M2 = M2p;

  Serial.print(M1);
  Serial.print(M2);
  Serial.println();

  Q1 = M1;
  digitalWrite(RelayPin,Q1);
  Serial.print(Q1);
  Serial.println();
  delay(100);

}
