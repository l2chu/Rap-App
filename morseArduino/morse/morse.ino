/*
 * This file takes ascii codes and converts them to 
 * morse codes and plays them on the Arduino.
 * Authors: Willow, Lillian, Michelle, Karen
 */
byte output;//output signal from pin 3
byte input;//input character from processor, also wpm

int wpm; //words per minute, determines length of dots, dashes
int dot;
int dash;//3 times as long as a dit
int freq;

/*
 * Play a dit
 * Param: output - the pin the dit is output to
 *        freq - the frequency of the tone
 *        dot - the duration of the dit
 */
void dit(){
  tone(output, freq);
  delay(dot);
  noTone(output);
  delay(dot);
}

/*
 * Play a dah
 * Param: output - the pin the dah is output to
 *        freq - the frequency of the tone
 *        dash - the duration of the dah
 */
void dah(){
  tone(output, freq);
  delay(dash);
  noTone(output);
  delay(dot);
}

/*
 * Silence between letters
 * International morse code decided it be the duration of 3 dot-lengths
 *  Since every dit/dah is already given a delay of 1 dot-length,
 *  letterDelay need only be 2 dot-lengths
 */
void letterDelay(){
  delay(2*dot);
}

/*
 * Silence between words
 * International morse code decided it be the duration of 7 dot-lengths
 * Since every letter already has a delay of 3 dot-lengths, the wordDelay 
 * need only be 4 dot-lengths.
 */
void wordDelay(){
  delay(4*dot);
}




/*
 * Functions placed into an array
 * The following functions detail the morse code pattern for a character. 
 * With the exception of punctuation, the functions are named for their 
 * character by the NATO phonetic alphabet.
 */
class patterns{
  public:

 
//A .-
void alfa() {
  freq = 1047;
  dit();
  dah();
}

//B -...
void bravo() {
  freq = 988;
  dah();
  dit();
  dit();
  dit();
}

//C -.-.
void charlie() {
  freq = 932;
  dah();
  dit();
  dah();
  dit();
}

//D -..
void delta() {
  freq = 880;
  dah();
  dit();
  dit();
}

//E .
void echo() {
  freq = 831;
  dit();
}

//F ..-.
void foxtrot() {
  freq = 784;
  dit();
  dit();
  dah();
  dit();
}

//G --.
void golf() {
  freq = 740;
  dah();
  dah();
  dit();
}

//H ....
void hotel() {
  freq = 698;
  dit();
  dit();
  dit();
  dit();
}

//I ..
void india() {
  freq = 659;
  dit();
  dit();
}

//J .---
void juliett() {
  freq = 622;
  dit();
  dah();
  dah();
  dah();
}

//K -.-
void kilo() {
  freq = 587;
  dah();
  dit();
  dah();
}

//L .-..
void lima() {
  freq = 523;
  dit();
  dah();
  dit();
  dit();
}

//M --
void mike() {
  freq = 494;
  dah();
  dah();
}

//N -.
void november() {
  freq = 466;
  dah();
  dit();
}

//O ---
void oscar() {
  freq = 440;
  dah();
  dah();
  dah();
}

//P .--.
void papa() {
  freq = 415;
  dit();
  dah();
  dah();
  dit();
}

//Q --.-
void quebec() {
  freq = 370;
  dah();
  dah();
  dit();
  dah();
}

//R .-.
void romeo() {
  freq = 349;
  dit();
  dah();
  dit();
}

//S ...
void sierra() {
  freq = 330;
  dit();
  dit();
  dit();
}

//T -
void tango() {
  freq = 311;
  dah();
}

//U ..-
void uniform() {
  freq = 294;
  dit();
  dit();
  dah();
}

//V ...-
void victor() {
  freq = 277;
  dit();
  dit();
  dit();
  dah();
}

//W .--
void whiskey() {
  freq = 262;
  dit();
  dah();
  dah();
}

//X -..-
void xray() {
  freq = 247;
  dah();
  dit();
  dit();
  dah();
}

//Y -.--
void yankee() {
  freq = 233;
  dah();
  dit();
  dah();
  dah();
}

//Z --..
void zulu() {
  freq = 220;
  dah();
  dah();
  dit();
  dit();
}

//1 .----
void one() {
  freq = 554;
  dit();
  dah();
  dah();
  dah();
  dah(); 
}

//2 ..---
void two() {
  freq = 554;
  dit();
  dit();
  dah();
  dah();
  dah(); 
}

//3 ...--
void three() {
  freq = 554;
  dit();
  dit();
  dit();
  dah();
  dah();
}

//4 ....-
void four() {
  freq = 554;
  dit();
  dit();
  dit();
  dit();
  dah();
}

//5 .....
void five() {
  freq = 554;
  dit();
  dit();
  dit();
  dit();
  dah();
}

//6 -....
void six() {
  freq = 392;
  dah();
  dit();
  dit();
  dit();
  dit();
}

//7 --...
void seven() {
  freq = 392;
  dah();
  dah();
  dit();
  dit();
  dit();
}

//8 ---..
void eight() {
  freq = 392;
  dah();
  dah();
  dah();
  dit();
  dit();
}

//9 ----.
void nine() {
  freq = 392;
  dah();
  dah();
  dah();
  dah();
  dit();  
}

//0 -----
void zero() {
  freq = 392;
  dah();
  dah();
  dah();
  dah();
  dah(); 
}

typedef void (patterns::*GeneralFunction)();

GeneralFunction patternArray [36] = {
  &patterns::zero,
  &patterns::one,
  &patterns::two,
  &patterns::three,
  &patterns::four,
  &patterns::five,
  &patterns::six,
  &patterns::seven,
  &patterns::eight,
  &patterns::nine,
  &patterns::alfa,
  &patterns::bravo,
  &patterns::charlie,
  &patterns::delta,
  &patterns::echo,
  &patterns::foxtrot,
  &patterns::golf,
  &patterns::hotel,
  &patterns::india,
  &patterns::juliett,
  &patterns::kilo,
  &patterns::lima,
  &patterns::mike,
  &patterns::november,
  &patterns::oscar,
  &patterns::papa,
  &patterns::quebec,
  &patterns::romeo,
  &patterns::sierra,
  &patterns::tango,
  &patterns::uniform,
  &patterns::victor,
  &patterns::whiskey,
  &patterns::xray,
  &patterns::yankee,
  &patterns::zulu,
  
};

};

void setup() {
  Serial.begin(9600);
  output = 3;//output to speaker from pin 3
  //determine WPM if indicated by text file, use default otherwise

    wpm = 15;

   
  //given WPM, determine length of dots and dashes
  dot = 1200/wpm;//based on standard 50 dot formula for wpm
  dash = dot*3;

}

void loop() {
  byte input;
  if(Serial.available() ){
    //initiate patterns variable
    patterns var;
    // getting index from serial
    input = Serial.read();
    //create a general function using pointers to the patternArray functions

    //if there is a space, then a word has ended
    if(input == 69){
      wordDelay();
    }else{
      patterns::GeneralFunction func = var.patterns::patternArray[input];
      //call the function using pointer references
      (var.*func)();
      letterDelay();
    }
    
    //run function for character from array
    
  }

  
  
}


