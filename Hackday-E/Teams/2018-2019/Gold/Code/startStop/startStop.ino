/* Gold Team Code for Ingenia SE Hackday E
 *  25/02/2019
 */

#define DOT 14   //led1 pin
#define LINE 15  //led2 pin

void dot(){
  digitalWrite(DOT, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for 500ms
  digitalWrite(DOT, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
}

void line(){
  digitalWrite(LINE, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for 500ms
  digitalWrite(LINE, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
}

void MorseStop(){
  digitalWrite(DOT, LOW);    // turn the LED off by making the voltage LOW         
  digitalWrite(LINE, LOW);    // turn the LED off by making the voltage LOW
 }

//Function to emit team color name in Morse
void gold(){
  line();
  line();
  dot();
  delay(1000);
  line();
  line();
  line();
  delay(1000);
   dot(); 
  line();
   dot();
   dot();
  delay(1000);
  line();
  dot();
  dot() ;
}

//Numbers coded in Morse
void n0(){
  line();
  line();
  line();
  line();
  line();
}

void n9(){
  line();
  line();
  line();
  line();
  dot();
}

void n8(){
  line();
  line();
  line();
  dot();
  dot();
}

void n7(){
  line();
  line();
  dot();
  dot();
  dot();
}

void n6(){
  line();
  dot();
  dot();
  dot();
  dot();
}

void n5(){
  dot();
  dot();
  dot();
  dot();
  dot();
}

void n4(){
  dot();
  dot();
  dot();
  dot();
  line();
}


void n3(){
  dot();
  dot();
  dot();
  line();
  line();
}

void n2(){
  dot();
  dot();
  line();
  line();
  line();
}

void n1(){
  dot();
  line();
  line();
  line();
  line();
}

//Alphabet coded in Morse
void z(){
  line();
  line();
  dot();
  dot();
}

void y(){
  line();
  dot();
  line();
  line();
}

void x(){
  line();
  dot();
  dot();
  line();
}

void w(){
  dot();
  line();
  line();
}

void v(){
  dot();
  dot();
  dot();
  line();
}

void u(){
  dot();
  dot();
  line();
}

void t(){
  line();
}

void s(){
  dot();
  dot();
  dot();
}

void r(){
  dot();
  line();
  dot();
}

void q(){
  line();
  line();
  dot();
  line();
}


void p(){
  dot();
  line();
  line();
  dot();
}

void o(){
  line();
  line();
  line();
}

void n(){
  line();
  dot();
}

void m(){
  line();
  line();
}

void l(){
  dot();
  line();
  dot();
  dot();
}

void k(){
  line();
  dot();
  line();
}

void j(){
  dot();
  line();
  line();
  line();
}

void i(){
  dot();
  dot();
}

void h(){
    dot();
    dot();
    dot();
    dot();
}

void g(){
  line();
  line();
  dot();
}

void f(){
  dot();
  dot();
  line();
  dot();
}

void e(){
  dot();
}

void d(){
  line();
  dot();
  dot();
}

void c(){
  line();
  dot();
  line();
  dot();
}

void b(){
  line();
  dot();
  dot();
  dot();
}

void a(){
  dot();
  line();
}

String inData; // Allocate some space for the string
char inChar; // Where to store the character read
int reading ; // Flag to know if we are reading a word from serial
int startStop; // Indicates state of program (running or pause)
int pos; // Variable to read the string

void setup() {
  // initialize digital pins 14 and 15 (leds) as an output.
  pinMode(DOT, OUTPUT);
  pinMode(LINE, OUTPUT);
  Serial.begin(9600);
  reading = 0;
  startStop = 0;
  pos = 0;
}

// the loop function runs over and over again forever
void loop() {

  while(Serial.available() > 0) // Don't read unless you know there is data
  {
    inChar = Serial.read(); // Read a character
    if (inChar == '*'){
      startStop = ~startStop;
    }
    else{
    if(reading == 0){
      inData = "";
    }
      reading = 1;   // Reading
      inData.concat(inChar); // Store it
    }
  }
  reading = 0;

  //Show morse code (leds)
  if(startStop != 1){
  Serial.print('\n');
  for(pos; pos < sizeof(inData); pos ++){
                switch(inData[pos]){
                  case '0': n0();
                  break;
                  case '1': n1();
                  break;
                  case '2': n2();
                  break;
                  case '3': n3();
                  break;
                  case '4': n4();
                  break;
                  case '5': n5();
                  break;
                  case '6': n6();
                  break;
                  case '7': n7();
                  break;
                  case '8': n8();
                  break;
                  case '9': n9();
                  break;
                  case 'a': a();
                  break;
                  case 'b': b();
                  break;
                  case 'c': c();
                  break;
                  case 'd': d();
                  break;
                  case 'e': e();
                  break;
                  case 'f': f();
                  break;
                  case 'g': g();
                  break;
                  case 'h': h();
                  break;
                  case 'i': i();
                  break;
                  case 'j': j();
                  break;   
                  case 'k': k();
                  break;
                  case 'l': l();
                  break;
                  case 'm': m();
                  break;
                  case 'n': n();
                  break;
                  case 'o': o();
                  break;
                  case 'p': p();
                  break;
                  case 'q': q();
                  break;
                  case 'r': r();
                  break;
                  case 's': s();
                  break;
                  case 't': t();
                  break;
                  case 'v': v();
                  break;
                  case 'w': w();
                  break;
                  case 'x': x();
                  break;
                  case 'y': y();
                  break;
                  case 'z': z();
                  break;                      
                }
                //Write the message on screen
                Serial.print(inData[pos]);
                delay(1000);
        }
        pos = 0; 
  }
}

