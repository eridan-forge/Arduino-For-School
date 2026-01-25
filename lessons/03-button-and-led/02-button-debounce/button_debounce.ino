/*
  Урок 3.2: Кнопка с защитой от дребезга
  Решает проблему ложных срабатываний кнопки
*/

// Определяем пины
#define BUTTON_PIN 2   // Кнопка подключена к D2
#define LED_PIN 13     // Светодиод на D13 (встроенный)

// Переменные состояния
bool ledState = false;     // Текущее состояние светодиода
bool buttonPressed = false; // Флаг: была ли обработана кнопка?

void setup() {
  // Настраиваем кнопку с внутренним подтягивающим резистором
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Настраиваем светодиод как выход
  pinMode(LED_PIN, OUTPUT);
  
  // Начинаем Serial для отладки
  Serial.begin(9600);
  Serial.println("Простая кнопка с антидребезгом");
}

void loop() {
  // Если кнопка нажата И мы еще не обработали это нажатие
  if (digitalRead(BUTTON_PIN) == LOW && !buttonPressed) {
    buttonPressed = true;  // Помечаем, что обработали нажатие
    
    // Меняем состояние светодиода (ВКЛ/ВЫКЛ)
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    
    // Выводим состояние в Serial Monitor
    Serial.print("Светодиод: ");
    Serial.println(ledState ? "ВКЛ" : "ВЫКЛ");
    
    delay(300);  // Задержка против дребезга
  }
  
  // Если кнопка отпущена - сбрасываем флаг
  if (digitalRead(BUTTON_PIN) == HIGH) {
    buttonPressed = false;
  }
}
