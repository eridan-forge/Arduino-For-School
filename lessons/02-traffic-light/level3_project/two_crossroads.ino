int red = 2;
int yellow = 3;
int green = 4;
int red1 = 5;
int yellow1 = 6;
int green1 = 7;

void setup() {
  // Настраиваем пины
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);  
  pinMode(green1, OUTPUT);   
}

void loop() {
  // === ФАЗА 1: Светофор 1 красный, Светофор 2 зеленый ===
  // (Машины едут по горизонтали)
  digitalWrite(red, HIGH);    // Светофор 1: 🔴
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  
  digitalWrite(red1, LOW);    // Светофор 2: 🟢
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, HIGH);
  delay(5000);  // 5 секунд едут
  
  // === ФАЗА 2: Светофор 2 желтый ===
  digitalWrite(red1, LOW);    // Светофор 2: 🟡
  digitalWrite(yellow1, HIGH);
  digitalWrite(green1, LOW);
  delay(2000);  // 2 секунды внимание
  
  // === ФАЗА 3: Пауза безопасности (оба красные) ===
  digitalWrite(red, HIGH);    // Светофор 1: 🔴
  digitalWrite(red1, HIGH);   // Светофор 2: 🔴
  digitalWrite(yellow1, LOW);
  delay(1000);  // 1 секунда пауза
  
  // === ФАЗА 4: Светофор 1 зеленый, Светофор 2 красный ===
  // (Машины едут по вертикали)
  digitalWrite(red, LOW);     // Светофор 1: 🟢
  digitalWrite(green, HIGH);
  
  digitalWrite(red1, HIGH);   // Светофор 2: 🔴
  digitalWrite(green1, LOW);
  delay(5000);  // 5 секунд едут
  
  // === ФАЗА 5: Светофор 1 желтый ===
  digitalWrite(green, LOW);   // Светофор 1: 🟡
  digitalWrite(yellow, HIGH);
  delay(2000);  // 2 секунды внимание
  
  // === ФАЗА 6: Пауза безопасности (оба красные) ===
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);    // Светофор 1: 🔴
  digitalWrite(red1, HIGH);   // Светофор 2: 🔴
  delay(1000);  // 1 секунда пауза
  
  // Начинаем цикл заново
}
