void setup() {
  pinMode(13, OUTPUT); // Светодиод на пине 13
  pinMode(LED_BUILTIN, OUTPUT); // Добавляем светодиод
}

void loop() {
  digitalWrite(13, HIGH); // Включить
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Ждать 1 секунду
  digitalWrite(13, LOW); // Выключить
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // 1000 миллисекунд это 1 секунда 
}

[Посмотреть готовый результат в симуляторе wowki](https://wokwi.com/projects/453758956373015553)
