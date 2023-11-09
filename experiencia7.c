#define ex1

#ifdef ex1
/* Acrescente um buzzer a montagem. Modifique o programa para o led
acender e o buzzer apitar. */

//Sensor de temperatura usando o LM35
int LM35 = A0; // Define o pino que lê a saída do LM35
float temperatura; // Variável que armazena a temperatura medida
int ledPin = 13; //Led no pino 13
int buzzerPin=4;//	valor da porta do buzzer

//Função que é executada uma vez quando ligar ou resetar o Arduino
void setup() {
	pinMode(ledPin,OUTPUT);//define a pino 13 como saída
	pinMode(buzzerPin,OUTPUT);
	Serial.begin(9600); // inicializa a comunicação serial
}


//Função que é executada continuamente
void loop() {
	temperatura = (float(analogRead(LM35))*5.0/(1023))/0.01;
	Serial.print("Temperatura: ");
	Serial.println(temperatura);

	if (temperatura >= 27){ //se o valor lido for maior que 27, liga o led e o buzzer
		digitalWrite(ledPin,HIGH);
        tone(buzzerPin,1000);//liga o buzzer
    } else {// senão, apaga o led e desliga o som
 		digitalWrite(ledPin,LOW);
  		noTone(buzzerPin);// desliga o buzzer
    }
delay(3000);
}
#endif


//----------------------------------------------------------------------------------


#ifdef ex2

/* Acrescente mais 2 leds a montagem. Conforme a temperatura aumenta os
leds vão acendendo progressivamente. O buzzer deve apitar quando o último led
acender. */

// Sensor de temperatura usando o LM35
int LM35 = A0; // Define o pino que lê a saída do LM35
float temperatura; // Variável que armazena a temperatura medida
int ledPin1 = 13; // Led no pino 13
int ledPin2 = 12; // Led no pino 12
int ledPin3 = 11; // Led no pino 11
int buzzerPin = 4; // Valor da porta do buzzer

// Função que é executada uma vez quando ligar ou resetar o Arduino
void setup() {
  pinMode(ledPin1, OUTPUT); // Define o pino 13 como saída
  pinMode(ledPin2, OUTPUT); // Define o pino 12 como saída
  pinMode(ledPin3, OUTPUT); // Define o pino 11 como saída
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Inicializa a comunicação serial
}

// Função que é executada continuamente
void loop() {
	temperatura = (float(analogRead(LM35)) * 5.0 / 1023) / 0.01;
 	Serial.print("Temperatura: ");
    Serial.println(temperatura);

	if (temperatura>70){
		digitalWrite(ledPin1, HIGH); // Liga o LED 1
		tone(buzzerPin, 1000);
    } else {
        digitalWrite(ledPin1, LOW); // Desliga o LED 1
        noTone(buzzerPin);
      }

	if (temperatura>50){
       digitalWrite(ledPin2, HIGH); // Liga o LED 2
    } else {
       digitalWrite(ledPin2, LOW); // Desliga o LED 2
      }

	if(temperatura>20){
    	digitalWrite(ledPin3, HIGH); // Liga o LED 3
    } else {
        digitalWrite(ledPin3, LOW); // Desliga o LED 3
      }
}

#endif


//--------------------------------------------------------------------------------


#ifdef ex3
/* Transforme a leitura do sensor de temperatura em uma função que retorna o valor
lido. */

int ledPin1 = 13; // Led no pino 13
int ledPin2 = 12; // Led no pino 12
int ledPin3 = 11; // Led no pino 11
int buzzerPin = 4; // Valor da porta do buzzer

// Função do sensor de temperatura
float temp(){
	// Sensor de temperatura usando o LM35
	int LM35 = A0; // Define o pino que lê a saída do LM35
    float temperatura; // Variável que armazena a temperatura medida
    temperatura = (float(analogRead(LM35)) * 5.0 / 1023) / 0.01;
  	Serial.print("Temperatura: ");
  	Serial.println(temperatura);
	return temperatura;
}

// Função que é executada uma vez quando ligar ou resetar o Arduino
void setup() {
    pinMode(ledPin1, OUTPUT); // Define o pino 13 como saída
  	pinMode(ledPin2, OUTPUT); // Define o pino 12 como saída
  	pinMode(buzzerPin, OUTPUT);
  	Serial.begin(9600); // Inicializa a comunicação serial
}

// Função que é executada continuamente
void loop() {
	float temperatura = temp();

	if (temperatura>70){
		digitalWrite(ledPin1, HIGH);
		tone(buzzerPin, 1000);
	} else {
  		digitalWrite(ledPin1, LOW);
    	noTone(buzzerPin);
   	 }

	if (temperatura>50){
   	 	digitalWrite(ledPin2, HIGH);
	} else {
   		digitalWrite(ledPin2, LOW);
 	 }

	if(temperatura>20){
   		digitalWrite(ledPin3, HIGH);
	} else {
   		digitalWrite(ledPin3, LOW);
 	 }
}
#endif


//------------------------------------------------------------------------------


#ifdef ex4
/* Transforme o controle de cada um dos led
em uma função que recebe o valor lido. */

int buzzerPin=4;//	valor da porta do buzzer

// Função do sensor de temperatura
float temp(){
	// Sensor de temperatura usando o LM35
	int LM35 = A0; // Define o pino que lê a saída do LM35
    float temperatura; // Variável que armazena a temperatura medida
    temperatura = (float(analogRead(LM35)) * 5.0 / 1023) / 0.01;
  	Serial.print("Temperatura: ");
  	Serial.println(temperatura);
	return temperatura;
}

void led1(float temperatura){
	int ledPin1 = 13;	// Led no pino 13

  	if(temperatura>70){
		digitalWrite(ledPin1, HIGH); // Liga o LED 1
      	tone(buzzerPin, 1000); // Liga o buzzer com frequência de 1000Hz
	} else {
    	digitalWrite(ledPin1, LOW); // desliga o LED 1
        noTone(buzzerPin); // Desliga o buzzer
     }
}

void led2(float temperatura){
	int ledPin2 = 12; // Led no pino 12

  	if (temperatura >= 50) {
    	digitalWrite(ledPin2, HIGH); // liga o LED 2
  	} else {
  		digitalWrite(ledPin2, LOW); // Desliga o LED 2
     }
}

void led3(float temperatura){
	int ledPin3 = 11; // Led no pino 11

  	if (temperatura >= 20) {
    	digitalWrite(ledPin3, HIGH); // Liga o LED 3}
    } else {
      	digitalWrite(ledPin3, LOW); // Liga o LED 3}
     }
}

// Função que é executada uma vez quando ligar ou resetar o Arduino
void setup() {
  int ledPin1,ledPin2,ledPin3;
  pinMode(ledPin1, OUTPUT); // Define o pino 13 como saída
  pinMode(ledPin2, OUTPUT); // Define o pino 12 como saída
  pinMode(ledPin3, OUTPUT); // Define o pino 11 como saída
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Inicializa a comunicação serial
}

// Função que é executada continuamente
void loop() {
	float temperatura = temp();

  	led1(temperatura);
 	led2(temperatura);
 	led3(temperatura);
}
#endif


//--------------------------------------------------------------------------


#ifdef ex5

/* Transforme o controle do buzzer em uma função que recebe o valor lido. */

// Função do sensor de temperatura
float temp(){
	// Sensor de temperatura usando o LM35
	int LM35 = A0; // Define o pino que lê a saída do LM35
    float temperatura; // Variável que armazena a temperatura medida
    temperatura = (float(analogRead(LM35)) * 5.0 / 1023) / 0.01;
  	Serial.print("Temperatura: ");
  	Serial.println(temperatura);
	return temperatura;
}

void led1(float temperatura){
	int ledPin1=13;	// Led no pino 13

  	if(temperatura>70){
		digitalWrite(ledPin1, HIGH); // Liga o LED 1
	} else {
    	digitalWrite(ledPin1, LOW); // desliga o LED 1
     }
}

void led2(float temperatura){
	int ledPin2 = 12; // Led no pino 12

  	if (temperatura >= 50) {
    	digitalWrite(ledPin2, HIGH); // liga o LED 2
  	} else {
  		digitalWrite(ledPin2, LOW); // Desliga o LED 2
     }
}

void led3(float temperatura){
	int ledPin3 = 11; // Led no pino 11

  	if (temperatura >= 20) {
    	digitalWrite(ledPin3, HIGH); // Liga o LED 3}
    } else {
      	digitalWrite(ledPin3, LOW); // Liga o LED 3}
     }
}

void buzzer(int temperatura){
	int buzzerPin = 4; // Valor da porta do buzzer

  	if (temperatura >= 50) {
   		tone(buzzerPin, 1000);
    } else {
       	noTone(buzzerPin); // Desliga o buzzer
     }
}


// Função que é executada uma vez quando ligar ou resetar o Arduino
void setup() {
  int ledPin1,ledPin2,ledPin3,buzzerPin;
  pinMode(ledPin1, OUTPUT); // Define o pino 13 como saída
  pinMode(ledPin2, OUTPUT); // Define o pino 12 como saída
  pinMode(ledPin3, OUTPUT); // Define o pino 11 como saída
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Inicializa a comunicação serial
}

// Função que é executada continuamente
void loop() {
	float temperatura = temp();

	led1(temperatura);
 	led2(temperatura);
 	led3(temperatura);
 	buzzer(temperatura);
}
#endif
