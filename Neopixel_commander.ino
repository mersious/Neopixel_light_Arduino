#define sw0 6
#define sw1 7

String input;

void setup() {
  pinMode(sw0, OUTPUT);
  pinMode(sw1, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0)
  {
    input = Serial.readString();
    Serial.print("I received: ");
    if(input == "show_error" )
    {
      Serial.println("show_error command");
      digitalWrite(sw0, HIGH);
      digitalWrite(sw1, LOW);
    }
    else if(input == "show_ok")
    {
      Serial.println("show_ok command");
      digitalWrite(sw0, LOW);
      digitalWrite(sw1, HIGH);
    }
    else if(input == "show_white")
    {
      Serial.println("show_white command");
      digitalWrite(sw0, LOW);
      digitalWrite(sw1, LOW);
    }
  }
}
