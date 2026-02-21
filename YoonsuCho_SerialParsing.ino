// Yoonsu Cho, Project 3: Serial Data Parsing 
const int ledpin = 8;
String Line = "";
bool led = false;

void setup() {
  
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);

  Serial.begin(9600);
  Serial.println("System Ready");
  Serial.println("Commands:");
  Serial.println("  LED:ON        (Turn LED ON)");
  Serial.println("  LED:OFF       (Turn LED OFF)");
  Serial.println("  STATUS:GET    (Show current LED state)");
  Serial.println("  BLINK:<ms>    (Blink LED for given milliseconds)");

}

void loop() {
  while(Serial.available()>0 )
  {
   char c = Serial.read();
    if (c == '\n') {
      processCommand(Line);
      Line = "";
    }
    else{
      Line += c;
    }
    if (Line.length() > 100){
      Line = "";
      Serial.println("ERROR");
    }
  }

}
void processCommand(String command){
  command.trim();
  if (command.length() == 0){
    Serial.println("Empty Command");
    return;
  }

  int Indexo = command.indexOf(':');
  if (Indexo == -1) {
    Serial.println ("Use KEY:VALUE");
    return;
  }

  String key = command.substring(0, Indexo);
  String value = command.substring(Indexo+1);
  key.trim();
  value.trim();

  if (key =="LED"){
    if (value == "ON"){
      digitalWrite(ledpin, HIGH);
      led = true;
      Serial.println("O : LED ON");
      }
    else if (value == "OFF") {
    digitalWrite(ledpin, LOW);
    led = false;
    Serial.println("X : LED OFF");
  }
    else{
      Serial.println("LED must be ON or OFF");
    }
  }


  else if (key == "STATUS"){
    if (value == "GET"){
      Serial.print(led ? "O: LED - " : "X: LED - ");
      Serial.println(led ? "ON" : "OFF");
    }
    else {
      Serial.println("Status must be GET");
    }
  }

  else if (key == "BLINK"){
    int ms = value.toInt();
    if (ms <=0){
      Serial.println("BLINK needs POSITIVE NUMBER!");
      return;
    }
   digitalWrite(ledpin, HIGH);
    delay(ms);
    digitalWrite(ledpin, LOW);
    delay(ms);

    Serial.print("O: Blinked ");
    Serial.print(ms);
    Serial.println(" ms");
}
 
else {
  Serial.println("ERROR! UNKNOWN COMMAND!");
}

}