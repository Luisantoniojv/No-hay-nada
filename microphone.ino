// Define los pines usados
const int sensorAnalogPin = A0;     // Pin analógico del sensor
const int sensorDigitalPin = 7;     // Pin digital del sensor
const int Led13 = 13;               // Pin del LED integrado

// Variables para almacenar los valores leídos
int analogValue;
int digitalValue;

void setup() {
  Serial.begin(9600);               // Inicia la comunicación serial

  // Configura los pines
  pinMode(sensorDigitalPin, INPUT); // Pin digital del sensor como entrada
  pinMode(Led13, OUTPUT);           // Pin del LED como salida
}

void loop() {
  // Lee el valor analógico del sensor
  analogValue = analogRead(sensorAnalogPin);

  // Lee el valor digital del sensor
  digitalValue = digitalRead(sensorDigitalPin);

  // Envía el valor analógico al monitor serial (útil para graficador serial)
  Serial.println(analogValue);

  // Enciende el LED si se detecta señal digital alta
  if (digitalValue == HIGH) {
    digitalWrite(Led13, HIGH);
  } else {
    digitalWrite(Led13, LOW);
  }

  // Pausa para evitar saturar el monitor serial
  delay(50);
}