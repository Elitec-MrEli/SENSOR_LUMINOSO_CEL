#define PINO_SENSOR_LUZ A0 // A0 - LEITURA DE LUMINOZIDADE DO SENSOR
#define     SENSOR_M   5  // D1 - LEITURA DO CONTATO MAGNETICO
const int  rl1 = 12;      // D6 - ACIONEMENTO DO RELE

boolean liga_debug = true;
int estado_SENSOR_M = 3;


void setup(){
  pinMode(PINO_SENSOR_LUZ, INPUT); // DEFINE A PORTA DO SENSOR COMO ENTRADA
  pinMode(SENSOR_M, INPUT_PULLUP); // DEFINE A PORTA SENSOR_M COMO ENTRADA E ATIVA RESISTOR DE PULLUP
  pinMode(rl1,OUTPUT);             // DEFINE A PORTA DO RELE COMO SAIDA
  digitalWrite(rl1, HIGH);         // DEFINE A PORTA COMO SAIDA E INICIA COM RELE DESLIGADO

  if (liga_debug == true){
    Serial.begin(9600); // INICIALIZA A SERIAL PARA DEBUG
  }
}
void loop()
{
 //leia_sensor_m();
 delay(250);
 leia_luminozidade();
 
}
void leia_luminozidade(){
  float leitura_luz = analogRead(PINO_SENSOR_LUZ); //Read light level
  if ((leitura_luz >= 11.00)&&(leitura_luz <= 18.00)){
    digitalWrite(rl1, LOW);
    Serial.println("Tocando..."+String(leitura_luz));
    delay(1500);
    Serial.println("Desligando..."+String(leitura_luz));
    digitalWrite(rl1, HIGH);
    delay(3000);
  }else{
    digitalWrite(rl1, HIGH);
  }
  Serial.println(leitura_luz); 
}
void leia_sensor_m(){
  estado_SENSOR_M = digitalRead(SENSOR_M);
  if (estado_SENSOR_M == 1) {
     Serial.println("tampa aberta");
     //digitalWrite(rl1, LOW);
  } else {
     Serial.println("tampa fechada");
     //digitalWrite(rl1, HIGH);
  }
}
