// Define el pin del LED
int Led = 13;

// Define el pin del botón (cuidado: no debe ser el mismo que el LED)
int buttonpin = 7;  // Cambiado para evitar conflicto con el LED

// Variable para almacenar el valor leído del botón
int val;

void setup() {
  // Configura el LED como salida
  pinMode(Led, OUTPUT);

  // Configura el botón como entrada
  pinMode(buttonpin, INPUT);

  // Inicia la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Lee el estado del botón
  val = digitalRead(buttonpin);

  // Si se presiona el botón, enciende el LED
  if (val == HIGH) {
    digitalWrite(Led, HIGH);
    Serial.println("HIGH!");
  } else {
    digitalWrite(Led, LOW);
    Serial.println("LOW!");
  }
}
