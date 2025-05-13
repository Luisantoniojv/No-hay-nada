// Define el pin del LED
int Led = 13;

// Define el pin del interruptor (botón)
int buttonpin = 3;

// Variable para almacenar el estado del botón
int val;

void setup() {
  // Define el LED como salida
  pinMode(Led, OUTPUT);

  // Define el interruptor como entrada
  pinMode(buttonpin, INPUT);

  // Inicia la comunicación serial (opcional si quieres monitorear el estado)
  Serial.begin(9600);
}

void loop() {
  // Lee el valor del pin digital donde está conectado el botón
  val = digitalRead(buttonpin);

  // Si el botón está presionado (valor alto), enciende el LED
  if (val == HIGH) {
    digitalWrite(Led, HIGH);
    Serial.println("Botón presionado - LED encendido");
  } else {
    // Si el botón no está presionado, apaga el LED
    digitalWrite(Led, LOW);
    Serial.println("Botón liberado - LED apagado");
  }
}
