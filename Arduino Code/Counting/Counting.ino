
#define LED_OUTPUT 4
#define LED_INPUT 3

int counter = 0;

void setup() {
  pinMode(LED_OUTPUT, OUTPUT);
  pinMode(LED_INPUT, INPUT_PULLUP);

}

void loop() {
  if (digitalRead(LED_INPUT) == LOW) {
    counter++;
    displayNumber(counter);
    while (digitalRead(LED_INPUT) == LOW) {
      delay(1);
    }
  }

}

void displayNumber(int counter) {
  for (int i = 0; i < counter; i++) {
    digitalWrite(LED_OUTPUT, HIGH);
    delay(250);
    digitalWrite(LED_OUTPUT, LOW);
    delay(250);
  }
}
