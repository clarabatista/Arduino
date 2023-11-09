#define ex1

#ifdef ex1
/* Monte mais 1 led e modifique o programa para que os 2 leds sejam controlados pelo
potenci�metro.*/

// Daremos um nome ao pino que est� conectado o LED
int ledPin1 = 11;
int ledPin2 = 10;
int pwmPin1 = A0;
unsigned int valorLido;
unsigned int pwm;

//Fun��o "setup" roda uma vez quando a placa e ligada ou resetada
void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
Serial.begin(9600);
}

// Fun��o que se repete infinitamente quando a placa � ligada
void loop() {
valorLido = analogRead(pwmPin1); // valor entre 0 e 1023
//mostra o valor lido na porta anal�gica

Serial.println(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255); // Mudan�a de escala
//Escreve no led um sinal PWM proporcional ao valor Lido
analogWrite(ledPin1,pwm);
analogWrite(ledPin2,pwm);
}
#endif


//--------------------------------------------------------------


#ifdef ex2
/* Modifique o programa para que os leds funcionem invertidos. Com a varia��o do
potenci�metro 1 led vai acendendo e outro led vai apagando.*/

// Daremos um nome ao pino que est� conectado o LED
int ledPin1 = 11;
int ledPin2 = 10;
int pwmPin1 = A0;
unsigned int valorLido;
unsigned int pwm;

//Fun��o "setup" roda uma vez quando a placa e ligada ou resetada
void setup() {
	pinMode(ledPin1, OUTPUT);
	pinMode(ledPin2, OUTPUT);
	Serial.begin(9600);
}

// Fun��o que se repete infinitamente quando a placa � ligada
void loop() {
	valorLido = analogRead(pwmPin1); // valor entre 0 e 1023

  	//mostra o valor lido na porta anal�gica
	Serial.println(valorLido);

	pwm = map(valorLido, 0, 1023, 0, 255); // Mudan�a de escala

	//Escreve no led um sinal PWM proporcional ao valor Lido
	analogWrite(ledPin1,255-pwm);
	analogWrite(ledPin2,pwm);
}
#endif


//--------------------------------------------------------------


#ifdef ex3
/* Monte mais 1 led. Conforme o potenci�metro vai variando, os leds v�o acendendo
progressivamente.*/

int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int pwmPin1 = A0;
unsigned int valorLido;
unsigned int pwm;

//Fun��o "setup" roda uma vez quando a placa e ligada ou resetada
void setup() {
	pinMode(ledPin1, OUTPUT);
	pinMode(ledPin2, OUTPUT);
	pinMode(ledPin3, OUTPUT);
	Serial.begin(9600);
}

// Fun��o que se repete infinitamente quando a placa � ligada
void loop() {
	valorLido = analogRead(pwmPin1); // valor entre 0 e 1023
	//mostra o valor lido na porta anal�gica

	Serial.println(valorLido);
	pwm = map(valorLido, 0, 1023, 0, 255); // Mudan�a de escala
	//Escreve no led um sinal PWM proporcional ao valor Lido


  if(pwm>80){
    analogWrite(ledPin1,pwm);
  } else {
    analogWrite(ledPin1,pwm=0);
    }

   if(pwm>150){
     analogWrite(ledPin2,pwm);
   } else {
     analogWrite(ledPin2,pwm=0);
     }

  if(pwm>200){
    analogWrite(ledPin3,pwm);
  } else {
     analogWrite(ledPin3,pwm=0);
    }
}
#endif


//--------------------------------------------------------------


#ifdef ex4
/* Monte o buzzer e quando o �ltimo led acender apite o buzzer junto.*/

int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int pwmPin1 = A0;
unsigned int valorLido;
unsigned int pwm;
int buzzerPin=13;

//Fun��o "setup" roda uma vez quando a placa e ligada ou resetada
void setup() {
	pinMode(ledPin1, OUTPUT);
	pinMode(ledPin2, OUTPUT);
	pinMode(ledPin3, OUTPUT);
	pinMode(buzzerPin,OUTPUT);
	Serial.begin(9600);
}

// Fun��o que se repete infinitamente quando a placa � ligada
void loop() {
	valorLido = analogRead(pwmPin1); // valor entre 0 e 1023
	//mostra o valor lido na porta anal�gica

	Serial.println(valorLido);
	pwm = map(valorLido, 0, 1023, 0, 255); // Mudan�a de escala
	//Escreve no led um sinal PWM proporcional ao valor Lido


    if(pwm>80){
      analogWrite(ledPin1,pwm);
    } else {
      analogWrite(ledPin1,pwm=0);
      }

    if(pwm>150){
      analogWrite(ledPin2,pwm);
    } else {
      analogWrite(ledPin2,pwm=0);
      }

    if(pwm>200){
      analogWrite(ledPin3,pwm);
      tone(buzzerPin,500);
    } else {
     analogWrite(ledPin3,pwm=0);
     noTone(buzzerPin);
     }
}
#endif


//--------------------------------------------------------------


#ifdef ex5
/* Transforme a leitura do potenci�metro em uma fun��o.*/

int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int buzzerPin=13;

//Fun��o "setup" roda uma vez quando a placa e ligada ou resetada
void setup() {
	pinMode(ledPin1, OUTPUT);
	pinMode(ledPin2, OUTPUT);
	pinMode(ledPin3, OUTPUT);
	pinMode(buzzerPin,OUTPUT);
	Serial.begin(9600);
}

unsigned int potenciometro(){
	int pwmPin1 = A0;
	unsigned int valorLido,pwm;

	valorLido = analogRead(pwmPin1); // valor entre 0 e 1023

  	//mostra o valor lido na porta anal�gica
  	Serial.println(valorLido);

  	pwm = map(valorLido, 0, 1023, 0, 255); // Mudan�a de escala
	return pwm;
}

// Fun��o que se repete infinitamente quando a placa � ligada
void loop() {
int pwm = potenciometro();

    if(pwm>80){
      analogWrite(ledPin1,pwm);
    } else {
      analogWrite(ledPin1,pwm=0);
      }

    if(pwm>150){
      analogWrite(ledPin2,pwm);
    } else {
      analogWrite(ledPin2,pwm=0);
      }

    if(pwm>200){
      analogWrite(ledPin3,pwm);
      tone(buzzerPin,500);
    } else {
     analogWrite(ledPin3,pwm=0);
     noTone(buzzerPin);
     }
}

#endif


//--------------------------------------------------------------


#ifdef ex6
/* Transforme a mudan�a de escala (c�lculo) em uma fun��o.*/

int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int buzzerPin=13;

//Fun��o "setup" roda uma vez quando a placa e ligada ou resetada
void setup() {
	pinMode(ledPin1, OUTPUT);
	pinMode(ledPin2, OUTPUT);
	pinMode(ledPin3, OUTPUT);
	pinMode(buzzerPin,OUTPUT);
	Serial.begin(9600);
}

unsigned int potenciometro() {
  int pwmPin1 = A0;
  unsigned int valorLido;

  valorLido = analogRead(pwmPin1); // valor entre 0 e 1023

  // mostra o valor lido na porta anal�gica
  Serial.println(valorLido);
  return valorLido;
}

unsigned int escala(unsigned int valorLido) {
  	unsigned int pwm;
  	pwm = map(valorLido, 0, 1023, 0, 255); // Mudan�a de escala

  	return pwm;
}

// Fun��o que se repete infinitamente quando a placa � ligada
void loop() {
  unsigned int valorLido = potenciometro();
  unsigned int pwm = escala(valorLido);

    if(pwm>80){
      analogWrite(ledPin1,pwm);
    } else {
      analogWrite(ledPin1,pwm=0);
      }

    if(pwm>150){
      analogWrite(ledPin2,pwm);
    } else {
      analogWrite(ledPin2,pwm=0);
      }

    if(pwm>200){
      analogWrite(ledPin3,pwm);
      tone(buzzerPin,500);
    } else {
     analogWrite(ledPin3,pwm=0);
     noTone(buzzerPin);
     }
}
#endif


//--------------------------------------------------------------


#ifdef ex7
/* Transforme o controle de cada dos led em uma fun��o.*/

int buzzerPin=13;

// Fun��o "setup" roda uma vez quando a placa � ligada ou resetada
void setup() {
  int ledPin1, ledPin2, ledPin3;
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

unsigned int potenciometro() {
  int pwmPin1 = A0;
  unsigned int valorLido;

  valorLido = analogRead(pwmPin1); // valor entre 0 e 1023
  // mostra o valor lido na porta anal�gica
  Serial.println(valorLido);
  return valorLido;
}

unsigned int escala(unsigned int valorLido) {
  unsigned int pwm;
  pwm = map(valorLido, 0, 1023, 0, 255); // Mudan�a de escala
  // Escreve no led um sinal PWM proporcional ao valor lido
  return pwm;
}

void led1 (unsigned int pwm){
  int ledPin1 = 11;

  if(pwm > 80) {
    analogWrite(ledPin1, pwm);
    tone(buzzerPin, 500);
  } else {
    analogWrite(ledPin1, 0);
    noTone(buzzerPin);
    }
}

void led2 (unsigned int pwm){
  int ledPin2 = 10;

  if (pwm > 150) {
     analogWrite(ledPin2, pwm);
  } else {
    analogWrite(ledPin2, 0);
    }
}

void led3 (unsigned int pwm){
  int ledPin3 = 9;

  if (pwm > 200) {
    analogWrite(ledPin3, pwm);
    } else {
     analogWrite(ledPin3, 0);
     }
}

// Fun��o que se repete infinitamente quando a placa � ligada
void loop() {
  unsigned int valorLido = potenciometro();
  unsigned int pwm = escala(valorLido);
  led1(pwm);
  led2(pwm);
  led3(pwm);
}
#endif


//--------------------------------------------------------------


#ifdef ex8
/* Transforme o controle do buzzer em uma fun��o.*/

// Fun��o "setup" roda uma vez quando a placa � ligada ou resetada
void setup() {
  int ledPin1, ledPin2, ledPin3, buzzerPin;
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

unsigned int potenciometro() {
  int pwmPin1 = A0;
  unsigned int valorLido;

  valorLido = analogRead(pwmPin1); // valor entre 0 e 1023
  // mostra o valor lido na porta anal�gica
  Serial.println(valorLido);
  return valorLido;
}

unsigned int escala(unsigned int valorLido) {
  unsigned int pwm;
  pwm = map(valorLido, 0, 1023, 0, 255); // Mudan�a de escala
  // Escreve no led um sinal PWM proporcional ao valor lido
  return pwm;
}

void led1 (unsigned int pwm){
  int ledPin1 = 11;

  if(pwm > 80) {
    analogWrite(ledPin1, pwm);
  } else {
    analogWrite(ledPin1, 0);
    }
}

void led2 (unsigned int pwm){
  int ledPin2 = 10;

  if (pwm > 150) {
     analogWrite(ledPin2, pwm);
  } else {
    analogWrite(ledPin2, 0);
    }
}

void led3 (unsigned int pwm){
  int ledPin3 = 9;
    if (pwm > 200) {
    analogWrite(ledPin3, pwm);
    } else {
     analogWrite(ledPin3, 0);
     }
}

void chamaled(){
 int pwm= potenciometro();
 led1(pwm);
  led2(pwm);
  led3(pwm);

}

void buzzer(unsigned int pwm){
   int buzzerPin = 13;

   if(pwm>200){
     tone(buzzerPin, 500);
   } else {
      noTone(buzzerPin);
    }
}

// Fun��o que se repete infinitamente quando a placa � ligada
void loop() {
  unsigned int valorLido = potenciometro();
  unsigned int pwm = escala(valorLido);
 chamaled();
  buzzer(pwm);
}

#endif


//--------------------------------------------------------------


#ifdef ex9
/* Transforme o controle do buzzer em uma fun��o.*/

// Fun��o "setup" roda uma vez quando a placa � ligada ou resetada
void setup() {
  int ledPin1, ledPin2, ledPin3, buzzerPin;
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

unsigned int potenciometro() {
  int pwmPin1 = A0;
  unsigned int valorLido;

  valorLido = analogRead(pwmPin1); // valor entre 0 e 1023
  // mostra o valor lido na porta anal�gica
  Serial.println(valorLido);
  return valorLido;
}

unsigned int escala(unsigned int valorLido) {
  unsigned int pwm;
  pwm = map(valorLido, 0, 1023, 0, 255); // Mudan�a de escala
  // Escreve no led um sinal PWM proporcional ao valor lido
  return pwm;
}

void led1 (unsigned int pwm){
  int ledPin1 = 11;

  if(pwm > 80) {
    analogWrite(ledPin1, pwm);
  } else {
    analogWrite(ledPin1, 0);
    }
}

void led2 (unsigned int pwm){
  int ledPin2 = 10;

  if (pwm > 150) {
     analogWrite(ledPin2, pwm);
  } else {
    analogWrite(ledPin2, 0);
    }
}

void led3 (unsigned int pwm){
  int ledPin3 = 9;
    if (pwm > 200) {
    analogWrite(ledPin3, pwm);
    } else {
     analogWrite(ledPin3, 0);
     }
}

void buzzer(unsigned int pwm){
   int buzzerPin = 13;

   if(pwm>200){
     tone(buzzerPin, 500);
   } else {
      noTone(buzzerPin);
    }
}

// Fun��o que se repete infinitamente quando a placa � ligada
void loop() {
  unsigned int valorLido = potenciometro();
  unsigned int pwm = escala(valorLido);
  led1(pwm);
  led2(pwm);
  led3(pwm);
  buzzer(pwm);
}

#endif
