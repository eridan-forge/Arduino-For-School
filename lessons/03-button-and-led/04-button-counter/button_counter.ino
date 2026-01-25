/*
  Урок 3.4: Счётчик нажатий
  Считает сколько раз нажали кнопку
*/

#define BUTTON_PIN 2
#define LED_PIN 13

int pressCount = 0;      // Счётчик нажатий
bool lastButton = HIGH;  // Предыдущее состояние кнопки

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("=== СЧЁТЧИК НАЖАТИЙ ===");
  Serial.println("Нажимайте кнопку...");
}

void loop() {
  int currentButton = digitalRead(BUTTON_PIN);
  
  // Если кнопка нажата (переход с HIGH на LOW)
  if (currentButton == LOW && lastButton == HIGH) {
    delay(50);  // Задержка против дребезга
    
    // Проверяем ещё раз (точно ли нажата)
    if (digitalRead(BUTTON_PIN) == LOW) {
      pressCount++;  // Увеличиваем счётчик
      
      Serial.print("Нажатий: ");
      Serial.println(pressCount);
      
      // Мигаем светодиодом для обратной связи
      digitalWrite(LED_PIN, HIGH);
      delay(200);
      digitalWrite(LED_PIN, LOW);
    }
  }
  
  lastButton = currentButton;  // Сохраняем состояние
}
