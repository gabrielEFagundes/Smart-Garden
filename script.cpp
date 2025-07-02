#define umidadeAnalogica A0
#define LedVermelho 2
#define LedAzul 3
#define Buzzer 4
#define LedAmarelo 5
#define Foto A1
int valorumidade;
int luz;
void setup() {
  Serial.begin(9600);
  pinMode(umidadeAnalogica, INPUT);
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedAzul, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Foto, INPUT);
}
void loop() {
  valorumidade = analogRead(umidadeAnalogica);
  valorumidade = map(valorumidade, 1023, 315, 0, 100);
  Serial.print("Umidade encontrada: "); 
  Serial.print(valorumidade);
  Serial.println(" % " );
  
  if (valorumidade >= 65) {
    Serial.println("Status: Solo umido, bomba DESLIGADA");
    digitalWrite(LedVermelho, HIGH);
    digitalWrite(LedAzul, LOW);
    digitalWrite(Buzzer, LOW);
  }
  else {
    Serial.println("Status: Solo seco, bomba LIGADA");
    digitalWrite(LedVermelho, LOW);
    digitalWrite(LedAzul, HIGH);
    tone(Buzzer, 349, 400/2);
  }
  
  luz = analogRead(Foto);
  Serial.print("Luz ambiente: ");
  Serial.print(luz);
  Serial.println();
  
  if(luz < 800){
    digitalWrite(LedAmarelo, HIGH);
  }else{
    digitalWrite(LedAmarelo, LOW);
  }
  
  delay(500);
}