const int greenLED = 2;
const int redLED = 3;
const int yellowLED = 4;

void setup() {
  // Configurar los pines de los LEDs como salida
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  
  // Iniciar la comunicación serial
  Serial.begin(9600);
  Serial.println("Control de luces iniciado.");
  Serial.println("Presiona 1-8 para controlar las luces, 9 para modo intermitente.");
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    
    switch (input) {
      case '1':
        controlLED(greenLED, HIGH);
        break;
      case '2':
        controlLED(greenLED, LOW);
        break;
      case '3':
        controlLED(redLED, HIGH);
        break;
      case '4':
        controlLED(redLED, LOW);
        break;
      case '5':
        controlLED(yellowLED, HIGH);
        break;
      case '6':
        controlLED(yellowLED, LOW);
        break;
      case '7':
        controlAllLEDs(HIGH);
        break;
      case '8':
        controlAllLEDs(LOW);
        break;
      case '9':
        blinkAllLEDs();
        break;
      default:
        Serial.println("Comando no válido. Presiona 1-8 para controlar las luces, 9 para modo intermitente.");
        break;
    }
  }
}

void controlLED(int ledPin, int state) {
  digitalWrite(ledPin, state);
  Serial.print("Luz ");
  Serial.print(ledPin == greenLED ? "verde" : ledPin == redLED ? "roja" : "amarilla");
  Serial.println(state == HIGH ? " encendida." : " apagada.");
}

void controlAllLEDs(int state) {
  digitalWrite(greenLED, state);
  digitalWrite(redLED, state);
  digitalWrite(yellowLED, state);
  Serial.println(state == HIGH ? "Todas las luces encendidas." : "Todas las luces apagadas.");
}

void blinkAllLEDs() {
  for (int i = 0; i < 5; i++) {  // 5 ciclos de intermitencia
    controlAllLEDs(HIGH);
    delay(500);
    controlAllLEDs(LOW);
    delay(500);
  }
  Serial.println("Modo intermitente completado.");
}