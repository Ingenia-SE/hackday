
#include <Arduino.h>
#include <string.h>
//Proyecto  Traductor de codigo Morse

int led = 14; //Definicion del pin 14
int led2 = 15; //Definicion del pin 15 
int retardo =200; // Variable como retardo
int start = 1;
int j = 0;
char ch[200]={0};
char aux;
void secuencia( char *secuencia);
void secuenciaMorse(char PuntoRaya);

char* letras [] = {" .- ", "  -... ", "  -.-. ", "  -.. ", " . ", " ..-. ", " --. ", " .... ", " .. ",  // de la A a la I
                            " .--- ","  -.- "," .-.. "," -- "," -. "," --- "," .--. "," --.- "," .-. ", // de la J-R

                             " ... "," - "," ..- "," ...- "," .-- "," -..- "," -.-- ","  --.. "}; // de la S-Z 


void setup()
{  
pinMode(led, OUTPUT); // Definimos el pin 14 como salida
pinMode(led2, OUTPUT); // Definimos el pin 15 como salida
Serial.begin(9600); // Se habilita la comunicacion serial a 9600 baudios
}

void loop () {

  for (int i = 0; i<200;i++){
    if (Serial.available()>0){
      aux = Serial.read();
        ch[i] = aux; // Se lee el puerto serie y el dato se guarda en ch
        j = 0;
      }
    else ch[i] = 0;
  }

  for (int i = j; i < 200; i++){
    
    if(Serial.available()>0){
      if (Serial.peek()=='0'){ //0 para detener el mensaje
        while(Serial.read()!='1'){ //1 para continuar el mensaje
          delay(1);
        }
      } 
    }
   // Serial.print(ch[i]);
    if( ch[i] >=  'a'  && ch[i] <= 'z') // Comparaciones
    { 
      secuencia(letras[ch[i] - 'a']); // Manda a llamar la funcion secuencia y le pasa como argumento la direccion del
    // array al que esta apuntando 
    }
    if ( ch[i]>= 'A' && ch[i]<= 'Z')
    {
         secuencia(letras[ch[i] - 'A']);
    }
    
    else if( ch[i] == ' ')  //si hay un espacio hacer un retardo mayor
    {
     delay( retardo * 2);
    }
  }
}



void secuencia( char *secuencia){ // Toma el contenido de la direccion que se le paso 

  int i = 0;
  while (secuencia[i] != NULL){ // del contenido hace un recorrido hasta encontrar un NULL
    secuenciaMorse(secuencia [i]); // Manda a llamar la funcion secuenciaMorse y le pasa como argumento la //posicion del contenido de una letra.
    i++;
    }
  delay (retardo * 3);
}

void secuenciaMorse(char PuntoRaya) // Recibe el contenido de la posicion actual de la secuencia
{
    // Enciende el led del pin 13
  if(PuntoRaya == '.') // Si el contenido es un "." hace un retardo en led
  {
     digitalWrite(led, HIGH);
     delay(retardo);
     digitalWrite(led, LOW);
   }
  
  else if(PuntoRaya == '-')  // Si es una una raya hace un retardo en led2
  {
     digitalWrite(led2, HIGH);
     delay(retardo);
     digitalWrite(led2, LOW);
  }
  digitalWrite(led, LOW); //Apaga el led
  digitalWrite(led2, LOW); //Apaga el led
  delay(retardo); // Hace un retardo para empezar de nuevo.
}
