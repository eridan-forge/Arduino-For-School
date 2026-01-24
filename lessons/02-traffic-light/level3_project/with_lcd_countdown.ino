// Пины светофора
int red = 8;
int yellow = 9; 
int green = 10;

// Пины LCD (стандартные для Wokwi)
int lcd_RS = 12;
int lcd_E = 11;
int lcd_D4 = 5;
int lcd_D5 = 4;
int lcd_D6 = 3;
int lcd_D7 = 2;

// Переменные для времени
int secondsLeft = 0;

void setup() {
  // Настройка пинов светофора
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
  // Настройка пинов LCD
  pinMode(lcd_RS, OUTPUT);
  pinMode(lcd_E, OUTPUT);
  pinMode(lcd_D4, OUTPUT);
  pinMode(lcd_D5, OUTPUT);
  pinMode(lcd_D6, OUTPUT);
  pinMode(lcd_D7, OUTPUT);
  
  // Инициализация LCD (без библиотеки)
  delay(100); // Ждем стабилизации
  
  // Последовательность инициализации LCD
  digitalWrite(lcd_RS, LOW);
  digitalWrite(lcd_E, LOW);
  
  // Функция установки 4-битного режима
  lcdCommand(0x33); // Инициализация
  lcdCommand(0x32); // Инициализация
  lcdCommand(0x28); // 4-бит, 2 строки, 5x7 шрифт
  lcdCommand(0x0C); // Включить дисплей, курсор выкл
  lcdCommand(0x06); // Направление текста слева направо
  lcdCommand(0x01); // Очистить дисплей
  
  delay(10);
  
  // Приветственное сообщение
  lcdPrint("Traffic Light");
  delay(2000);
  lcdClear();
}

void loop() {
  // ===== ФАЗА 1: КРАСНЫЙ (5 секунд) =====
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  
  lcdClear();
  lcdSetCursor(0, 0);
  lcdPrint("STOP");
  
  // Обратный отсчёт
  for (secondsLeft = 5; secondsLeft > 0; secondsLeft--) {
    lcdSetCursor(0, 1);
    lcdPrint("       "); // Очищаем
    lcdSetCursor(0, 1);
    lcdPrint("Time: ");
    lcdPrint(String(secondsLeft));
    lcdPrint("s");
    delay(1000);
  }
  
  // ===== ФАЗА 2: ЗЕЛЁНЫЙ (5 секунд) =====
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  
  lcdClear();
  lcdSetCursor(0, 0);
  lcdPrint("GO");
  
  // Обратный отсчёт
  for (secondsLeft = 5; secondsLeft > 0; secondsLeft--) {
    lcdSetCursor(0, 1);
    lcdPrint("       ");
    lcdSetCursor(0, 1);
    lcdPrint("Time: ");
    lcdPrint(String(secondsLeft));
    lcdPrint("s");
    delay(1000);
  }
  
  // ===== ФАЗА 3: ЖЁЛТЫЙ (2 секунды) =====
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  
  lcdClear();
  lcdSetCursor(0, 0);
  lcdPrint("ATTENTION");
  
  // Обратный отсчёт
  for (secondsLeft = 2; secondsLeft > 0; secondsLeft--) {
    lcdSetCursor(0, 1);
    lcdPrint("       ");
    lcdSetCursor(0, 1);
    lcdPrint("Time: ");
    lcdPrint(String(secondsLeft));
    lcdPrint("s");
    delay(1000);
  }
  
  digitalWrite(yellow, LOW);
}

// ===== ФУНКЦИИ ДЛЯ LCD (БЕЗ БИБЛИОТЕКИ) =====

// Отправка команды на LCD
void lcdCommand(byte command) {
  digitalWrite(lcd_RS, LOW); // Режим команды
  lcdWrite(command);         // Отправляем команду
}

// Отправка данных на LCD
void lcdData(byte data) {
  digitalWrite(lcd_RS, HIGH); // Режим данных
  lcdWrite(data);             // Отправляем данные
}

// Основная функция записи в LCD
void lcdWrite(byte value) {
  // Сначала старшие 4 бита
  digitalWrite(lcd_D4, (value >> 4) & 1);
  digitalWrite(lcd_D5, (value >> 5) & 1);
  digitalWrite(lcd_D6, (value >> 6) & 1);
  digitalWrite(lcd_D7, (value >> 7) & 1);
  
  // Импульс Enable
  digitalWrite(lcd_E, HIGH);
  delayMicroseconds(1);
  digitalWrite(lcd_E, LOW);
  delayMicroseconds(1);
  
  // Потом младшие 4 бита
  digitalWrite(lcd_D4, (value >> 0) & 1);
  digitalWrite(lcd_D5, (value >> 1) & 1);
  digitalWrite(lcd_D6, (value >> 2) & 1);
  digitalWrite(lcd_D7, (value >> 3) & 1);
  
  // Импульс Enable
  digitalWrite(lcd_E, HIGH);
  delayMicroseconds(1);
  digitalWrite(lcd_E, LOW);
  delayMicroseconds(50);
}

// Печать строки
void lcdPrint(String text) {
  for (int i = 0; i < text.length(); i++) {
    lcdData(text[i]);
  }
}

// Очистка экрана
void lcdClear() {
  lcdCommand(0x01);
  delay(2);
}

// Установка позиции курсора
void lcdSetCursor(int col, int row) {
  int row_offsets[] = {0x00, 0x40};
  lcdCommand(0x80 | (col + row_offsets[row]));
}
