/*
  ПРОСТОЙ пешеходный светофор с кнопкой
  Без сложной логики - нажал кнопку, светофор сработал
*/

// Пины светофоров
int carRed = 10;     // 🔴 Машины: красный
int carYellow = 11;  // 🟡 Машины: желтый
int carGreen = 12;   // 🟢 Машины: зеленый
int pedRed = 9;      // 🔴 Пешеходы: красный
int pedGreen = 8;    // 🟢 Пешеходы: зеленый
int button = 2;      // Кнопка

void setup() {
  // Настраиваем все как выходы (кроме кнопки)
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT_PULLUP);  // Кнопка с подтяжкой
  
  // Начальное состояние
  digitalWrite(carGreen, HIGH);  // Машинам зеленый
  digitalWrite(pedRed, HIGH);    // Пешеходам красный
}

void loop() {
  // Просто проверяем кнопку
  if (digitalRead(button) == LOW) {  // Если нажата
    delay(50);  // Ждем немного (защита от дребезга)
    
    // Проверяем еще раз (точно ли нажата)
    if (digitalRead(button) == LOW) {
      // Запускаем пешеходный режим
      pedestrianCrossing();
    }
  }
}

// Функция пешеходного перехода
void pedestrianCrossing() {
  // 1. Машинам: зеленый → желтый
  digitalWrite(carGreen, LOW);
  digitalWrite(carYellow, HIGH);
  delay(2000);  // 2 секунды
  
  // 2. Машинам: желтый → красный
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  delay(2000);  // 2 секунды
  
  // 3. Пешеходам: красный → зеленый
  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);
  delay(7000);  // 7 секунд идти
  
  // 4. Пешеходам: мигающий зеленый
  for (int i = 0; i < 4; i++) {
    digitalWrite(pedGreen, LOW);
    delay(500);
    digitalWrite(pedGreen, HIGH);
    delay(500);
  }
  
  // 5. Пешеходам: зеленый → красный
  digitalWrite(pedGreen, LOW);
  digitalWrite(pedRed, HIGH);
  delay(2000);  // 2 секунды
  
  // 6. Машинам: красный → зеленый
  digitalWrite(carRed, LOW);
  digitalWrite(carGreen, HIGH);
}
