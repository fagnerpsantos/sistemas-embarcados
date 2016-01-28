#include "RCSwitch.h"
#include <Wire.h>

//#define MIDDLEWARE


//Instancias do emissor e receptor
RCSwitch emissor = RCSwitch();
RCSwitch receptor = RCSwitch();



#define RFID_LIMITE_INFER 1
#define RFID_LIMITE_SUPER 5
#define RFID 2

#define DESLOCAMENTO_RFID 26
#define DESLOCAMENTO_UMI 18
#define DESCOLAMENTO_LUMI 10

#define PINO_TEMPERATURA 0
#define PINO_BATIMENTOS 1

#ifdef MIDDLEWARE
struct InfoRF {
 int id;
 int luminosidade;
 int temperatura;
 int umidade;
 } infoRF;
 #else
 long infoRF;
 #endif

void setup(){
  Serial.begin(9600);
  
  //Configuracao do emissor/receptor RF 
  emissor.enableTransmit(4);
  receptor.enableReceive(0);
     
}

//certo

long lerSensoresRF(){
  
  long luminosidade = analogRead(PINO_BATIMENTOS);
  long temperatura = analogRead(PINO_TEMPERATURA);
  long umidade = analogRead(A2);
  
  luminosidade = map(luminosidade, 0, 1023, 0, 200);
  temperatura = map(temperatura, 0, 1023, 0, 50);
  umidade = map(umidade, 1023, 0, 0, 100);
  
  long rf = RFID;
  long info = rf << DESLOCAMENTO_RFID;
  info = info | (umidade << DESLOCAMENTO_UMI);
  info = info | (luminosidade << DESCOLAMENTO_LUMI);
  info = info | temperatura;
  
  return info; 
}

boolean RFIDValido(long rf){
  boolean valido = false;
  #ifdef MIDDLEWARE  
  infoRF.id = rf >> DESLOCAMENTO_RFID;
  if((infoRF.id >= RFID_LIMITE_INFER) && (infoRF.id <= RFID_LIMITE_SUPER)){
    valido = true;
  }
  #else
   int id = rf >> DESLOCAMENTO_RFID;
  if((id >= RFID_LIMITE_INFER) && (id <= RFID_LIMITE_SUPER)){
    valido = true;
  }
  #endif
  return valido;

  
}


void emitir(long info) {
 emissor.send(info, 32); 
}

long receber()  {
  long info = -1;
  if(receptor.available()){
   info = receptor.getReceivedValue(); 
   receptor.resetAvailable();
 
  } 
  return info;
}

// ---- Extracao dos valores -------
int extrairUmidade(long info){
  int umidade = (info & 66846720) >> DESLOCAMENTO_UMI;
  
  return umidade;
}

int extrairLuminosidade(long info){
  int luminosidade = (info & 261120) >> DESCOLAMENTO_LUMI;
  
  return luminosidade;
  
}

int extrairTemperatura(long info){
  int temperatura = (info & 1023);
  
  return temperatura;
}

int extrairId(long info){
  int id = (info) >> DESLOCAMENTO_RFID;
  
  return id;
}

// ------------ Envio para USB
void enviarParaUSB(){
 
   Serial.write('I');
   Serial.write((uint8_t*) &infoRF, sizeof(infoRF));
   Serial.write('F');
 
}

//------ LOOP ---------
void loop(){  
  //EMISSAO DE DADOS
  long info = lerSensoresRF();
  emitir(info);
  delay(500); 

  //RECEPCAO DE DADOS
  info = receber();
    if(info != -1){
    if(RFIDValido(info)){
      #ifdef MIDDLEWARE
/*      infoRF.umidade = extrairUmidade(info);
      infoRF.luminosidade = extrairLuminosidade(info);
      infoRF.temperatura = extrairTemperatura(info);
      */
      #else
      infoRF = info;
      #endif
      
      enviarParaUSB();
    }
  } 
  
}
