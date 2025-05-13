// Arduino code to read temperature from a thermistor
// using the Steinhart-Hart equation 
#include <math.h>

byte NTCPin = A0;

#define SERIESRESISTOR 10000
#define NOMINAL_RESISTANCE 10000
#define NOMINAL_TEMPERATURE 25
#define BCOEFFICIENT 3950

void setup() {
  Serial.begin(9600);
}

void loop() {
  float ADCvalue;
  float Resistance;
  
  // Leer valor del ADC
  ADCvalue = analogRead(NTCPin);
  Serial.print("Analog Value = ");
  Serial.println(ADCvalue);

  // Convertir valor a resistencia
  Resistance = (1023.0 / ADCvalue) - 1.0;
  Resistance = SERIESRESISTOR / Resistance;

  Serial.print("Resistance = ");
  Serial.print(Resistance);
  Serial.println(" Ohm");

  // Calcular temperatura usando la ecuación de Steinhart-Hart
  float steinhart;
  steinhart = Resistance / NOMINAL_RESISTANCE;        // (R/Ro)
  steinhart = log(steinhart);                         // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                          // 1/B * ln(R/Ro)
  steinhart += 1.0 / (NOMINAL_TEMPERATURE + 273.15);  // + (1/To)
  steinhart = 1.0 / steinhart;                        // Invertir
  steinhart -= 273.15;                                // Convertir a °C

  Serial.print("Temperature = ");
  Serial.print(steinhart);
  Serial.println(" °C");

  delay(1000);
}

