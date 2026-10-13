const int IN1 = 6;
const int IN2 = 5;
const int IN3 = 9;
const int IN4 = 10;

const int ENA = 3;
const int ENB = 11;

const int sensorEsq = 2; 
const int sensorDir = 4; 

const int velocidadeFrente = 90;
const int velocidadeImpulso = 255;

const int PRETO = HIGH;
const int BRANCO = LOW;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(sensorEsq, INPUT);
  pinMode(sensorDir, INPUT);
}

void loop() {
  int leituraEsq = digitalRead(sensorEsq);
  int leituraDir = digitalRead(sensorDir);

  if (leituraEsq == BRANCO && leituraDir == BRANCO) {
    andarFrente();
  }
  else if (leituraEsq == PRETO && leituraDir == BRANCO) {
    virarEsquerda();
    delay(30);
  }
  else if (leituraEsq == BRANCO && leituraDir == PRETO) {
    virarDireita();
    delay(30);
  }
  else if (leituraEsq == PRETO && leituraDir == PRETO) {
    pararTotalmente();
  }
}

void andarFrente() {
  analogWrite(ENA, velocidadeFrente);
  analogWrite(ENB, velocidadeFrente);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void virarEsquerda() {
  analogWrite(ENA, velocidadeImpulso);
  analogWrite(ENB, velocidadeImpulso);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void virarDireita() {
  analogWrite(ENA, velocidadeImpulso);
  analogWrite(ENB, velocidadeImpulso);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void pararTotalmente() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
