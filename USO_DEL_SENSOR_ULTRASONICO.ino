// Definimos los pines del sensor ultrasónico
const int pin_Trigger = 2;  // Pin digital D2 del Arduino conectado al pin Trigger del sensor
const int pin_Echo = 3;  // Pin digital D3 del Arduino conectado al pin Echo del sensor

// Variables para almacenar los resultados de la medición
int tiempo_de_rebote;  // Variable para almacenar el tiempo que tarda el eco en regresar
int distancia_medida;  // Variable para almacenar la distancia calculada

void setup() {
  // Iniciamos la comunicación serial a 9600 baudios para visualizar los resultados en el monitor serie
  Serial.begin(9600);  
  
  // Configuramos el pin Trigger como salida, este pin enviará los pulsos ultrasónicos
  pinMode(pin_Trigger, OUTPUT);
  
  // Configuramos el pin Echo como entrada, este pin recibirá el eco del pulso enviado
  pinMode(pin_Echo, INPUT);  
}

void loop() {
  // Asegurarnos de que el pin Trigger esté en estado bajo (LOW) antes de enviar el pulso
  digitalWrite(pin_Trigger, LOW);
  delayMicroseconds(2);  // Esperar 2 microsegundos para asegurar que esté en bajo
  
  // Enviar un pulso ultrasónico de 10 microsegundos al pin Trigger
  digitalWrite(pin_Trigger, HIGH);
  delayMicroseconds(10);  // Esperar 10 microsegundos (duración del pulso)
  digitalWrite(pin_Trigger, LOW);
  
  // Medir el tiempo que tarda el eco en regresar al pin Echo
  // `pulseIn` devuelve el tiempo en microsegundos que el pin Echo permanece en alto (HIGH)
  tiempo_de_rebote = pulseIn(pin_Echo, HIGH);

  // Calcular la distancia en centímetros:
  // La velocidad del sonido es de 0.034 cm/us (centímetros por microsegundo)
  // Dividimos por 2 ya que el pulso recorre la distancia de ida y vuelta
  distancia_medida = tiempo_de_rebote * 0.034 / 2;

  // Mostrar la distancia calculada en el monitor serie
  Serial.print("Distancia medida aproximadamente es de: ");
  Serial.print(distancia_medida);  // Imprimir el valor numérico de la distancia
  Serial.println(" cm");  // Imprimir la unidad (centímetros) junto al valor
  
  // Pausa de 500 milisegundos antes de realizar una nueva medición
  delay(500);  
}
