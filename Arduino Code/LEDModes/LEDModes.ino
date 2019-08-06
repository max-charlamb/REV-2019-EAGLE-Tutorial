
#define LED_OUTPUT 4
#define LED_INPUT 3

int mode = 0;
int maxModes = 4;

void setup() {
  pinMode(LED_OUTPUT, OUTPUT);
  pinMode(LED_INPUT, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(LED_INPUT) == LOW) {
    mode++;
    mode = mode % maxModes;
    while (digitalRead(LED_INPUT) == LOW) {
      delay(1);
    }
  }

  switch (mode) {
    case 0:
      digitalWrite(LED_OUTPUT, HIGH);
      delay(250);
      digitalWrite(LED_OUTPUT, LOW);
      delay(250);
      break;
    case 1:
      for (int i = 0; i < 256; i++) {
        analogWrite(LED_OUTPUT, i);
        delay(1);
      }
      break;
    case 2:
      analogWrite(LED_OUTPUT, 0);
      break;
    case 3:
      analogWrite(LED_OUTPUT, 255);
      break;
    default:
      break;
  }

}
