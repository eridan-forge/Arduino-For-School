/*
  Урок 3.1: Простейшая кнопка (без защиты от дребезга)
  Показывает проблему множественных срабатываний
*/

#define BUTTON_PIN 2   // Кнопка на D2
#define LED_PIN 13     // Светодиод на D13 (встроенный)

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Кнопка с подтягивающим резистором
  pinMode(LED_PIN, OUTPUT);           // Светодиод как выход
  
  Serial.begin(9600);
  Serial.println("Базовая кнопка (проблема дребезга)");
}

void loop() {
  // ПРОСТАЯ проверка кнопки (есть проблема!)
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Переключаем светодиод
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    
    Serial.println("Кнопка нажата!");
    
    // Маленькая задержка, но не решает проблему полностью
    delay(100);
  }
}
