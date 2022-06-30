//Mateusz Gajda WCY20IY2S1
//Winda porusza się między trzema następującymi kondygnacjami: 1, 2, 3.
//Stan początkowy – winda ustawia się na 3 kondygnacji
//Opis Stanow:
//M1 – Winda znajduje się na 3 kondygnacji
//M2 – Winda znajduje się na 2 kondygnacji
//M3 – Winda znajduje się na 1 kondygnacji
//M4 – Winda jedzie z 1 na 2 kondygnacje 
//M5 – Winda jedzie z 1 na 3 kondygnacje
//M6 – Winda jedzie z 3 na 2 kondygnacje
//M7 – Winda jedzie z 3 na 1 kondygnacje
//M8 – Winda jedzie z 2 na 3 kondygnacje
//M9 – Winda jedzie z 2 na 1 kondygnacje


int PinI2 = A1; //nazwa pinu dla "Przycisk żądanie 1-go poziomu"
int PinI3 = A2; //nazwa pinu dla "Przycisk żądanie 2-go poziomu"
int PinI4 = A3; //nazwa pinu dla "Przycisk żądanie 3-go poziomu"
int PinI6 = A5; //nazwa pinu dla "Sensor obecności kabiny na 1-ym poziomie"
int PinI7 = 12; //nazwa pinu dla "Sensor obecności kabiny na 2-im poziomie"
int PinI8 = 13; //nazwa pinu dla "Sensor obecności kabiny na 3-im poziomie"
int OutputQ1Pin = 5; //nazwa pinu dla Forward/Reverse Signal (bit kierunku)
int OutputQ2Pin = 4; //nazwa pinu dla Start/Stop Signal (bit stopu)

bool Q1 = 0;
bool Q2 = 0;

bool I2 = 0;
bool I3 = 0;
bool I4 = 0;
bool I6 = 0;
bool I7 = 0;
bool I8 = 0;

bool M1 = 0;
bool M2 = 0;
bool M3 = 0;
bool M4 = 0;
bool M5 = 0;
bool M6 = 0;
bool M7 = 0;
bool M8 = 0;
bool M9 = 0;

bool M1p = 0;
bool M2p = 0;
bool M3p = 0;
bool M4p = 0;
bool M5p = 0;
bool M6p = 0;
bool M7p = 0;
bool M8p = 0;
bool M9p = 0;

void setup() {
 pinMode(PinI2, INPUT);
 pinMode(PinI3, INPUT);
 pinMode(PinI4, INPUT);
 pinMode(PinI6, INPUT);
 pinMode(PinI7, INPUT);
 pinMode(PinI8, INPUT);
 pinMode(OutputQ1Pin, OUTPUT);
 pinMode(OutputQ2Pin, OUTPUT);
 Serial.begin(9600);
 Serial.println("Koniec Setup");
}
void loop() {
  
 I2 = digitalRead(PinI2);
 I3 = digitalRead(PinI3);
 I4 = digitalRead(PinI4);
 I6 = digitalRead(PinI6);
 I7 = digitalRead(PinI7);
 I8 = digitalRead(PinI8);

 M1p = (M1 && I2 == LOW && I3 == LOW)||(M5 && I8 == HIGH)||(M8 && I8 == HIGH);
 M2p = (M2 && I2 == LOW && I4 == LOW)||(M4 && I7 == HIGH)||(M6 && I7 == HIGH);
 M3p = (M3 && I3 == LOW && I4 == LOW)||(M7 && I6 == HIGH)||(M9 && I6 == HIGH);
 M4p = (M3 && I3 == HIGH)||(M4 && I7 == LOW);
 M5p = (M3 && I4 == HIGH)||(M5 && I8 == LOW);
 M6p = (M1 && I3 == HIGH)||(M6 && I7 == LOW);
 M7p = (M1 && I2 == HIGH)||(M7 && I6 == LOW);
 M8p = (M2 && I4 == HIGH)||(M8 && I8 == LOW)||(!M1 && !M2 && !M3 && !M4 && !M5 && !M6 && !M7 && !M8 && !M9);
 M9p = (M2 && I2 == HIGH)||(M9 && I6 == LOW);
 
 M1 = M1p;
 M2 = M2p;
 M3 = M3p;
 M4 = M4p;
 M5 = M5p;
 M6 = M6p;
 M7 = M7p;
 M8 = M8p;
 M9 = M9p;
 
 Q1 = (M6 || M7 || M9);
 Q2 = (M1 || M2 || M3);
 
 digitalWrite(OutputQ1Pin, Q1);
 digitalWrite(OutputQ2Pin, Q2);
 delay(100);
}
