#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int i=0;
int j=0;
int aux=1;
int bandera=0;
int comienzo=0;
char interrupcion='m';
char texto[256];
char code[256];
char letra;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);
  Serial.begin(9600);
  strcpy(texto,"");
}

 //  FUNCIONES
void punto(){
  digitalWrite(LED2, HIGH);
  //Serial.println("punto");
  //Serial.println(texto);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500);
}

void raya(){
  digitalWrite(LED1, HIGH);
  //Serial.println("raya");
  //Serial.println(texto);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
}


// the loop function runs over and over again forever
void loop() {

  if(comienzo==0){
    //Serial.println("Escribe:");
    comienzo=1;
  }
  
  while(Serial.available()>0){
    letra=char(Serial.read());
    delay(50);
    strcat(texto,letra);
    delay(500);
    bandera=1;
  }
  
  if(bandera ==1){
    strcpy(code,"");
    for(j=0;j<strlen(texto);j++){
      letra=texto[j];
      switch(letra){
        case 'A':strcpy(code, ".-"); break;
        case 'B':strcpy(code, "-...");break;
        case 'C':strcpy(code, "-.-.");break;
        case 'D':strcpy(code, "-..");break;
        case 'E':strcpy(code, ".");break;
        case 'F':strcpy(code, "..-.");break;
        case 'G':strcpy(code, "--.");break;
        case 'H':strcpy(code, "....");break;
        case 'I':strcpy(code, "..");break;
        case 'J':strcpy(code, "-.-.");break;
        case 'K':strcpy(code, "-.-");break;
        case 'L':strcpy(code, ".-..");break;
        case 'M': strcpy(code, "--"); break;
        case 'N': strcpy(code, "-."); break;
        case 'O': strcpy(code, "---"); break;
        case 'P': strcpy(code, ".--."); break;
        case 'Q': strcpy(code, "--.-"); break;
        case 'R': strcpy(code, ".-."); break;
        case 'S': strcpy(code, "..."); break;
        case 'T': strcpy(code, "-"); break;
        case 'U': strcpy(code, "..-"); break;
        case 'V': strcpy(code, "...-"); break;
        case 'W': strcpy(code, ".--"); break;
        case 'X': strcpy(code, "-..-"); break;
        case 'Y': strcpy(code, "-.--"); break;
        case 'Z': strcpy(code, "--.."); break;
      } //Switch
      
      for(i=0;i<strlen(code);i++){
        interrupcion=Serial.read();
        if (interrupcion == 'p'){
          aux=0;
          Serial.println("PARADA");
        }
        if(interrupcion == 'h'){
          Serial.print(texto);
        }
        while(aux==0){
          interrupcion=Serial.read();
          if(interrupcion=='p') aux=1;
          if(interrupcion == 'h'){
           Serial.println(texto);
          }
        }
        if(code[i]=='.') punto();
        if(code[i]=='-') raya();
      }
      comienzo=0;
    }
    strcpy(texto,"");
    
    } //if bandera
  //strcpy(texto,"");
}
