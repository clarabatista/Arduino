#define ex1

#ifdef ex1
/* Acrescente um buzzer a montagem. Modifique o programa para o led
acender e o buzzer apitar.*/

//Sensor de luz
int ledPin = 13; //Led no pino 13
int ldrPin = 0; //LDR no pino analogico A0
int ldrValor = 0; //Valor lido do LDR
int buzzerPin=4;// valor da porta do buzzer

void setup() {
	pinMode(buzzerPin, OUTPUT);
	pinMode(ledPin,OUTPUT); //define a porta 13 como saída
	Serial.begin(9600); //Inicia a comunicação serial
}

void loop() {
//ler o valor do LDR
ldrValor = analogRead(ldrPin); //O valor lido sera’ entre 0 e 1023
//imprime o valor lido do LDR no monitor serial
Serial.println(ldrValor);
//se o valor lido for maior que 500, liga o led

if (ldrValor>= 500) {
	tone(buzzerPin,1000);//liga o buzzer
	digitalWrite(ledPin,HIGH);
} else {
	noTone(buzzerPin);// desliga o buzzer
	digitalWrite(ledPin,LOW);
  	delay(100);
	}
}
#endif ex1


//-------------------------------------------------


#ifdef ex2
/* Acrescente mais 2 leds a montagem. Conforme a luminosidade diminui os
leds vão acendendo progressivamente. O buzzer deve apitar quando o último led
acender.*/

//Sensor de luz
int ledPin1 = 13; //Led verde no pino 13
int ledPin2 = 12;//Led azul no pino 12
int ledPin3 = 11;//Led vermelha no pino 11
int ldrPin = 0; //LDR no pino analogico A0
int ldrValor = 0; //Valor lido do LDR
int buzzerPin=4;// valor da porta do buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  Serial.begin(9600); //Inicia a comunicação serial
}

void loop() {
//ler o valor do LDR
ldrValor = analogRead(ldrPin); //O valor lido sera’ entre 0 e 1023
//imprime o valor lido do LDR no monitor serial
Serial.println(ldrValor);

if (ldrValor >= 800) {
	digitalWrite(ledPin1, HIGH);
	tone(buzzerPin,1000);
  } else {
      digitalWrite(ledPin1, LOW);
      noTone(buzzerPin);
    }

if (ldrValor >= 678) {
  	digitalWrite(ledPin2, HIGH);
  } else {
      digitalWrite(ledPin2, LOW);
      noTone(buzzerPin);
    }

if (ldrValor >= 346) {
	digitalWrite(ledPin3, HIGH);
  } else {
       digitalWrite(ledPin3, LOW);
       noTone(buzzerPin);
    }
}
#endif


//-----------------------------------------------------------------


#ifdef ex3
/* Transforme a leitura do sensor de luminosidade em uma função
que retorna o valor lido. */

//Sensor de luz
int ledPin1 = 13; //Led verde no pino 13
int ledPin2 = 12;//Led azul no pino 12
int ledPin3 = 11;//Led vermelha no pino 11
int ldrPin = 0; //LDR no pino analogico A0
int ldrValor = 0; //Valor lido do LDR
int buzzerPin=4;// valor da porta do buzzer

int sensor(){
	int ldrPin = 0; //LDR no pino analogico A0
	int ldrValor = 0; //Valor lido do LDR
  	//ler o valor do LDR
	ldrValor = analogRead(ldrPin); //O valor lido sera’ entre 0 e 1023
	//imprime o valor lido do LDR no monitor serial
	Serial.println(ldrValor);
  	return ldrValor;
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  Serial.begin(9600); //Inicia a comunicação serial
}

void loop() {
 int ldrValor=sensor();

if (ldrValor >= 800) {
	digitalWrite(ledPin1, HIGH);
	tone(buzzerPin,1000);
  } else {
      digitalWrite(ledPin1, LOW);
      noTone(buzzerPin);
    }

if (ldrValor >= 678) {
  	digitalWrite(ledPin2, HIGH);
  } else {
      digitalWrite(ledPin2, LOW);
      noTone(buzzerPin);
    }

if (ldrValor >= 346) {
	digitalWrite(ledPin3, HIGH);
  } else {
       digitalWrite(ledPin3, LOW);
       noTone(buzzerPin);
    }

}
#endif ex3


//--------------------------------------------


#ifdef ex4
/* Transforme o controle de cada um dos
led em uma função que recebe o valor lido. */

int buzzerPin=4;// valor da porta do buzzer

int sensor(){
	int ldrPin = 0; //LDR no pino analogico A0
	int ldrValor = 0; //Valor lido do LDR
  	//ler o valor do LDR
	ldrValor = analogRead(ldrPin); //O valor lido sera’ entre 0 e 1023
	//imprime o valor lido do LDR no monitor serial
	Serial.println(ldrValor);
  	return ldrValor;
}

int led1 (int ldrValor) {
	int ledPin1 = 13; //Led verde no pino 13

  if (ldrValor >= 750){
    noTone(buzzerPin);
    digitalWrite(ledPin1, HIGH);
  } else {
      noTone(buzzerPin);
      digitalWrite(ledPin1, LOW);
    }
}

int led2 (int ldrValor) {
    int ledPin2 = 12;//Led azul no pino 12

    if (ldrValor >= 600) {
      digitalWrite(ledPin2, HIGH);
    } else {
        digitalWrite(ledPin2, LOW);
      }
}

int led3 (int ldrValor){
    int ledPin3 = 11;//Led vermelha no pino 11

if (ldrValor >= 500) {
     digitalWrite(ledPin3, HIGH);
    } else {
        digitalWrite(ledPin3, LOW);
      }
}

void setup() {
int buzzerPin,ledPinazul,ledPinverde,ledPinvermelho;
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPinvermelho,OUTPUT); //define a porta 13 como saída
  pinMode(ledPinazul,OUTPUT);
  pinMode(ledPinverde,OUTPUT);
Serial.begin(9600); //Inicia a comunicação serial
}

void loop() {
    int luz = sensor();
    led1(luz);
    led2(luz);
    led3(luz);
}
#endif ex4


//--------------------------------------------


#ifdef ex5
/* Transforme o controle do buzzer
em uma função que recebe o valor lido.*/

int sensor(){
	int ldrPin = A0; //LDR no pino analogico A0
	int ldrValor = 0; //Valor lido do LDR
  	//ler o valor do LDR
	ldrValor = analogRead(ldrPin); //O valor lido sera’ entre 0 e 1023
	//imprime o valor lido do LDR no monitor serial
	Serial.println(ldrValor);
  	return ldrValor;
}

int led1 (int ldrValor) {
	int ledPin1 = 13; //Led verde no pino 13

  if (ldrValor >= 750){
    digitalWrite(ledPin1, HIGH);
  } else {
      digitalWrite(ledPin1, LOW);
    }
}

int led2 (int ldrValor) {
    int ledPin2 = 12;//Led azul no pino 12

    if (ldrValor >= 600) {
      digitalWrite(ledPin2, HIGH);
    } else {
        digitalWrite(ledPin2, LOW);
      }
}

int led3 (int ldrValor){
    int ledPin3 = 11;//Led vermelha no pino 11

if (ldrValor >= 500) {
     digitalWrite(ledPin3, HIGH);
    } else {
        digitalWrite(ledPin3, LOW);
      }
}

int som(int ldrValor){
	int buzzerPin=4; // valor da porta do buzzer

if(ldrValor >= 750){
  tone(buzzerPin,1000);
  } else {
      noTone(buzzerPin);
	 }
}

void setup() {
int buzzerPin,ledPinvermelho,ledPinazul,ledPinverde;
	pinMode(buzzerPin, OUTPUT);
 	pinMode(ledPinvermelho,OUTPUT); //define a porta 13 como saída
  	pinMode(ledPinazul,OUTPUT);
  	pinMode(ledPinverde,OUTPUT);
	Serial.begin(9600); //Inicia a comunicação serial
}

void loop() {
    int luz=sensor();
    led1(luz);
    led2(luz);
    led3(luz);
    som(luz);
}
#endif ex5
