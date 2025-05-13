// Arduino code to read IR (inflarojo) recptor
// using the IRremote library
#include <IRremote.h>

/* Pin de recepción de señal infrarroja */
#define RECV_PIN 11

/* Pin del LED */
#define LED 13

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  pinMode(LED, OUTPUT);         // Inicializa el LED como salida
  Serial.begin(9600);           // Inicializa el monitor serial
  irrecv.enableIRIn();          // Inicia el receptor IR
}

void loop() {
  if (irrecv.decode(&results)) {
    int state = LOW;

    // Cambia el valor recibido por el código de tu control IR
    if (results.value == 0xFF30CF) {  // Ejemplo: botón "1"
      state = HIGH;
    }

    digitalWrite(LED, state);        // Enciende o apaga el LED
    Serial.println(results.value, HEX); // Muestra el código en hexadecimal

    irrecv.resume();                 // Espera la próxima señal
  }
}
