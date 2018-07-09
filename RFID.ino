//RFID - Controle de Acesso leitor RFID
//Autor : Gabriel Borralho
 
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
#define SS_PIN 10
#define RST_PIN 9
#define SOM_LIBERADO  880
#define SOM_NEGADO  220
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Cria uma instância MFRC522.
 
LiquidCrystal lcd(6, 7, 5, 4, 3, 2);  
char st[20];
int speakerPin=8;
 
void setup(){
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
  //Define o número de colunas e linhas do LCD:  
  lcd.begin(16, 2);  
  mensageminicial();
  pinMode(speakerPin,OUTPUT);
}
 
void loop() {
  // Procura por novos cartões
  if ( ! mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  // Seleciona um para o cartão
  if ( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }
  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++){
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i]<0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();

/**************      CADASTRO DAS TAGS          **************/
   if (conteudo.substring(1) == "F0 18 CA 80"){ //UID 1 - Chaveiro
    Serial.println("Ola GABRIEL !");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ola GABRIEL !");
    lcd.setCursor(0,1);
    lcd.print("Acesso liberado!");
    tone(speakerPin, SOM_LIBERADO);
    //digitalWrite(RELE, HIGH) -> AQUI VOCE PODE ACIONAR UM RELÉ 
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, SOM_LIBERADO);
    delay(250);
    noTone(speakerPin);
    delay(3000);
    mensageminicial();
  }
/***********************************************************************/ 
  if (conteudo.substring(1) == "C0 44 98 7C"){ //UID 2 - CARTAO EM BRANCO
    Serial.println("CARTAO EM BRANCO");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("CARTAO EM BRANCO");
    lcd.setCursor(0,1);
    lcd.print("Acesso Negado !");
    tone(speakerPin, SOM_NEGADO);
    delay(500);
    noTone(speakerPin);
    delay(3000);
    mensageminicial();
  }
/***********************************************************************/ 
void mensageminicial()
{
  lcd.clear();
  lcd.print(" Aproxime o seu");  
  lcd.setCursor(0,1);
  lcd.print("cartao do leitor");  
}
/***** FIM PROGRAMA ****************************************************/ 
