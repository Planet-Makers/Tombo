const int buttonPinFHR = 9;    // Ficheiro
const int buttonPinSTR = 10;   // Start
const int buttonPinSTP = 11;   // Stop
const int relePin = 12;      //Rele

int buttonPushCounter = 0;
int buttonStateFHR = 0;
int buttonStateSTR = 0;
int buttonStateSTP = 0;
int lastButtonState = 1;
int relePinState = 1;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPinFHR, INPUT_PULLUP);
  pinMode(buttonPinSTR, INPUT_PULLUP);
  pinMode(buttonPinSTP, INPUT_PULLUP);
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, HIGH);
}

void loop() {
  // verifica se o ficheiro está ativo
  buttonStateFHR = digitalRead(buttonPinFHR);
  buttonStateSTR = digitalRead(buttonPinSTR);
  buttonStateSTP = digitalRead(buttonPinSTP);
  if (buttonStateFHR == HIGH) {
    if (buttonStateSTP == LOW) {
      if (buttonStateSTR != lastButtonState) {
        //buttonStateSTR = digitalRead(buttonPinSTR);
        //permite executar a ação somente quando soltar o botão
        lastButtonState = digitalRead(buttonPinSTR);
        delay(50);
          if (buttonStateSTR = lastButtonState) {
            digitalWrite(relePin, LOW);
            delay(800);
            lastButtonState = 1;
            buttonStateSTR = digitalRead(buttonPinSTR);
            //digitalWrite(relePin, HIGH);
            //buttonStateSTR = digitalRead(buttonPinSTR);
            //buttonStateSTP = digitalRead(buttonPinSTP);
            //if (buttonStateSTR != buttonStateSTP) {
            //  digitalWrite(relePin, HIGH);
            //}
          //}else{
          //  Serial.println(lastButtonState);
          }
      } else {
        //Serial.println("buttonStateSTR != lastButtonState");
        digitalWrite(relePin, HIGH);
      }
      digitalWrite(relePin, HIGH);
    }else {
      Serial.println("botão stop aberto");
      digitalWrite(relePin, HIGH);
    }
  } else {
    Serial.print("Ficheiro: Inativo");
    Serial.println(buttonStateFHR);
  }
}  
