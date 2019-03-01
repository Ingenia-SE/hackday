#define UNIT_LENGTH    250

String palabra = "";   // for incoming serial string data
char letra;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

   pinMode(LED2, OUTPUT);
   pinMode(LED1, OUTPUT);
   Serial.println("Programa iniciado");
  
}


//Build a struct with the morse code mapping
static const struct {const char letter, *code;} MorseMap[] =
{
  { 'A', ".-" },
  { 'B', "-..." },
  { 'C', "-.-." },
  { 'D', "-.." },
  { 'E', "." },
  { 'F', "..-." },
  { 'G', "--." },
  { 'H', "...." },
  { 'I', ".." },
  { 'J', ".---" },
  { 'K', ".-.-" },
  { 'L', ".-.." },
  { 'M', "--" },
  { 'N', "-." },
  { 'O', "---" },
  { 'P', ".--." },
  { 'Q', "--.-" },
  { 'R', ".-." },
  { 'S', "..." },
  { 'T', "-" },
  { 'U', "..-" },
  { 'V', "...-" },
  { 'W', ".--" },
  { 'X', "-..-" },
  { 'Y', "-.--" },
  { 'Z', "--.." },
  { ' ', "     " }, //Gap between word, seven units 
    
  { '1', ".----" },
  { '2', "..---" },
  { '3', "...--" },
  { '4', "....-" },
  { '5', "....." },
  { '6', "-...." },
  { '7', "--..." },
  { '8', "---.." },
  { '9', "----." },
  { '0', "-----" },
    
  { '.', "·–·–·–" },
  { ',', "--..--" },
  { '?', "..--.." },
  { '!', "-.-.--" },
  { ':', "---..." },
  { ';', "-.-.-." },
  { '(', "-.--." },
  { ')', "-.--.-" },
  { '"', ".-..-." },
  { '@', ".--.-." },
  { '&', ".-..." },
};




String encode(String string)
{
  size_t i, j;  
  String morseWord = "";
  
  for( i = 0; string[i]; ++i )
  {
    for( j = 0; j < sizeof MorseMap / sizeof *MorseMap; ++j )
    {
      if( toupper(string[i]) == MorseMap[j].letter )
      {
        morseWord += MorseMap[j].code;
        break;
      }
    }
    morseWord += " "; //Add tailing space to seperate the chars
  }

  return morseWord;  
}

String decode(String morse)
{
  String msg = "";
  
  int lastPos = 0;
  int pos = morse.indexOf(' ');
  while( lastPos <= morse.lastIndexOf(' ') )
  {    
    for( int i = 0; i < sizeof MorseMap / sizeof *MorseMap; ++i )
    {
      if( morse.substring(lastPos, pos) == MorseMap[i].code )
      {
        msg += MorseMap[i].letter;
      }
    }

    lastPos = pos+1;
    pos = morse.indexOf(' ', lastPos);
    
    // Handle white-spaces between words (7 spaces)
    while( morse[lastPos] == ' ' && morse[pos+1] == ' ' )
    {
      pos ++;
    }
  }

  return msg;
}
int leido=0;;
void loop()
{ 
  //Serial.flush();
  Serial.println("Introduce tu tweet aquí (140 caracteres) en MAYUSCULAS. Puedes poner espacios, comas, puntos y @. Al acabar pulsa enter. Disfruta del espectáculo");

   // send data only when you receive data:

  //while (leido==0){
    if(Serial.available()) {
        palabra="";
        letra = Serial.read();
        palabra.concat(letra);
        //leido=1;
    }
  //}
  //leido=0;

  //Serial.flush();
  
  String morseWord = encode(palabra);
  Serial.println("Mensaje traducido. Atento a los leds!");
 
    
  for(int i=0; i<=morseWord.length(); i++)
  {
    switch( morseWord[i] )
    {
      case '.': //dit
        digitalWrite( LED1, HIGH );
        delay( UNIT_LENGTH );
        digitalWrite( LED1, LOW );
        delay( UNIT_LENGTH );
          
        break;

      case '-': //dah
        digitalWrite( LED2, HIGH );
        delay( UNIT_LENGTH*3 );
        digitalWrite( LED2, LOW );
        delay( UNIT_LENGTH );
          
        break;

      case ' ': //gap
        delay( UNIT_LENGTH );
     }
  }

 // Serial.println("La aplicación ha terminado. Gracias <3");
 // palabra="";
 // Serial.flush();
  
}
