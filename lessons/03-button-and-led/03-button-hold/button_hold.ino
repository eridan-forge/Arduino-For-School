/*
  Урок 3.3: Кнопка с удержанием
  Светодиод горит только пока держите кнопку
*/

#define BUTTON_PIN 2
#define LED_PIN 13

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Удерживай кнопку");
  Serial.println("Держите кнопку - светодиод горит");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) { // ПОСЛЕ if вседа ()
    digitalWrite(LED_PIN, HIGH); // Включаем при нажатии светодиоид
  } else {
    digitalWrite(LED_PIN, LOW); // Включаем при отпускании
  }

  delay(50); // Небольшая задержка

}
