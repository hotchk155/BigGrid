#define P_SCAN_IN_LAT    19  
#define P_SCAN_IN_CLK   18
#define P_SCAN_IN_DAT   17


void setup() {
  pinMode(P_SCAN_IN_LAT, OUTPUT);
  pinMode(P_SCAN_IN_CLK, OUTPUT);
  pinMode(P_SCAN_IN_DAT, INPUT_PULLUP);
  
  digitalWrite(P_SCAN_IN_LAT, HIGH);
}

byte readIn() 
{
  digitalWrite(P_SCAN_IN_CLK, LOW);
  digitalWrite(P_SCAN_IN_LAT, LOW);
  delayMicroseconds(100);
  digitalWrite(P_SCAN_IN_LAT, HIGH);
  
  byte result = 0;
  for(int i=0; i<8; ++i) {
    digitalWrite(P_SCAN_IN_CLK, HIGH);
    delayMicroseconds(100);
    if(digitalRead(P_SCAN_IN_DAT)) {
      result |= 1;
      result <<= 1;
    }
    digitalWrite(P_SCAN_IN_CLK, LOW);    
  }
  return result;  
}

void loop() {
  Serial.println(result);
  delay(100);
}
