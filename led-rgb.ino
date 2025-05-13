// Selecciona el pin para el LED rojo
int redpin = 11;

// Selecciona el pin para el LED verde
int greenpin = 10;

// Selecciona el pin para el LED azul
int bluepin = 9;

// Define una variable entera para el valor PWM
int val;

void setup() {
  // Configura los pines del LED RGB como salidas
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);

  // Inicia la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Fundido hacia abajo
  for (val = 255; val > 0; val--) {
    analogWrite(redpin, val);        // Rojo disminuye
    analogWrite(greenpin, 255 - val); // Verde aumenta
    analogWrite(bluepin, 128 - val);  // Azul disminuye
    delay(50);
  }

  // Fundido hacia arriba
  for (val = 0; val < 255; val++) {
    analogWrite(redpin, val);         // Rojo aumenta
    analogWrite(greenpin, 255 - val); // Verde disminuye
    analogWrite(bluepin, 128 - val);  // Azul disminuye más
    delay(50);
  }

  // Muestra el último valor (será 254)
  Serial.println(val, DEC);
}
