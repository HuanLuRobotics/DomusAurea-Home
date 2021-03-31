/**
 * Author: Juan Luis Gozalo (juanluis.gozalo@huanLuRobotics.com)
 * Date: 22/Mar/2021
 * Version 1.0.0
 * 
 * Description: Different musics play for a buzzer
 * All the notes are defined in a matrix with the 9 octaves.
 * 
 * Material:
 * a Elegoo Buzzer (connected to pin 5V, GND and PIN 3)
 *  
**/
#ifndef DEBUG_MODE
// #define DEBUG_MODE
#endif

// Notes are { DO,  DOS, RE,  RES, MI,  FA,  FAS, SOL, SOLS, LA,  LAS,  SI   }
// Notes are { c,   cS,  d,   dS,  e,   f,   fS,  g,   gS,   a,   aS,   b    }
// index to    [0], [1], [2], [3], [4], [5], [6], [7], [8],  [9], [10], [11]
const byte index_c = 0;
const byte index_cS = 1;
const byte index_d = 2;
const byte index_dS = 3;
const byte index_e = 4;
const byte index_f = 5;
const byte index_fS = 6;
const byte index_g = 7;
const byte index_gS = 8;
const byte index_a = 9;
const byte index_aS = 10;
const byte index_b = 11;

// Musical frequencies (9 octaves). 
// Each note is a long (four bytes), so this section is commented unless you need mandatory the real frequencies
// const long notas[10][12]={
//  {16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96, 27.50, 29.14, 30.87},
//  {32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74},
//  {65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47},
//  {130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 246.94},
//  {261.63, 277.18, 293.67, 311.13, 329.63, 349.23, 369.99, 392.00, 415.31, 440.00, 466.16, 493.88},
//  {523.25, 554.37, 587.33, 622.25, 659.26, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77},
//  {1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53},
//  {2093.01, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07},
//  {4186.01, 4434.92, 4698.64, 4978.03, 5274.04, 5587.65, 5919.91, 6271.93, 6644.88, 7040.00, 7458.62, 7902.13},
//  {8372.02, 8869.84, 9397.27, 9956.06, 10548.08, 11175.30, 11839.82, 12543.86, 13289.75, 14080.00, 14917.24, 15804.26}
// };

// Musical frequencies (9 octaves). (ROUNDED)
// To save space all notes are rounded to min or max to be fitted in an "int" (two bytes)
const int notas[10][12]={
  {16, 17, 18, 19, 20, 22, 23, 24, 26, 27, 29, 31},
  {33, 35, 37, 39, 41, 44, 46, 49, 52, 55, 58, 62},
  {65, 69, 73, 78, 82, 87, 92, 98, 104, 110, 116, 123},
  {131, 139, 147, 155, 165, 175, 185, 196, 208, 220, 233, 247},
  {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494},
  {523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988},
  {1046, 1109, 1175, 1244, 1318, 1397, 1480, 1568, 1661, 1760, 1865, 1975},
  {2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951},
  {4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040, 7459, 7902},
  {8372, 8870, 9397, 9956, 10548, 11175, 11840, 12544, 13290, 14080, 14917, 15804}
};

// Duración Notas musicales
const int semibreve = 4000; // redonda
const int dotted_minim = 3000; // blanca con puntillo
const int minim = 2000; // blanca
const int dotted_crotchet = 1500; // negra con puntillo
const int crotchet = 1000; // negra
const int dotted_quaver = 750; // corchea con puntillo
const int quaver = 500; // corchea
const int semiquaver = 250; // semicorchea
const int fuse = 125; // fusa
const int semifuse = 62; // semifusa
const int semibreve_rest = 4000; // silencio de redonda
const int minim_rest = 2090; // silencio de blanca
const int crotchet_rest = 1000; // silencio de negra
const int quaver_rest = 500; // silencio de corchea
const int sixteenth_note_rest = 250; // silencio de semicorchea
const int fuse_rest = 125; 
const int semifuse_rest = 62;

// Melody 1: Star Wars Imperial March
int melody1[] = {  notas[4][index_a], notas[4][index_a], notas[4][index_a], notas[4][index_f], notas[5][index_c], notas[4][index_a], 
                   notas[4][index_f], notas[5][index_c], notas[4][index_a], notas[5][index_c], notas[5][index_e], notas[5][index_e], 
                   notas[5][index_f], notas[5][index_c], notas[5][index_g], notas[5][index_f], notas[5][index_c], notas[4][index_a]};
// Melody 2: Star Wars Theme
int melody2[] = {  notas[4][index_f], notas[4][index_f], notas[4][index_f], notas[4][index_aS], notas[5][index_f], notas[5][index_dS], 
                   notas[5][index_d], notas[5][index_c], notas[5][index_aS], notas[5][index_f], notas[5][index_dS], notas[5][index_d], 
                   notas[5][index_c], notas[5][index_aS], notas[5][index_f], notas[5][index_dS], notas[5][index_d], notas[5][index_dS], notas[5][index_c]};

const int buzzerPin = 3;
byte counter=0;
 
void setup()
{
  //Setup pin modes
  pinMode(buzzerPin, OUTPUT);
}
 
void loop()
{
   StarWars_ImperialMarch();
}

void loop_test()
{
  if (counter == 0) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 12; j++) {
        beep(notas[i][j],crotchet);
        delay(250);
      }
    }
    counter = 1;
  }
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
  delay(250);
  //Stop tone on buzzerPin
  noTone(buzzerPin);
  delay(100);
}

void StarWars_ImperialMarch() {

  //Play first section
  firstSection();
 
  //Play second section
  secondSection();
 
  beep(notas[4][index_f], quaver);  
  beep(notas[4][index_gS], crotchet);  
  beep(notas[4][index_f], quaver);  
  beep(notas[4][index_a], semiquaver);
  beep(notas[5][index_c], crotchet);
  beep(notas[4][index_a], quaver);  
  beep(notas[5][index_c], semiquaver);
  beep(notas[5][index_e], minim);
 
  delay(500);
 
  //Repeat second section
  secondSection();
 

  beep(notas[4][index_f], semiquaver);  
  beep(notas[4][index_gS], crotchet);  
  beep(notas[4][index_f], quaver);  
  beep(notas[5][index_c], semiquaver);
  beep(notas[4][index_a], crotchet);  
  beep(notas[4][index_f], quaver);  
  beep(notas[5][index_c], semiquaver);
  beep(notas[4][index_a], minim);  
 
  delay(650);
}
 
void firstSection()
{
  beep(notas[4][index_a], crotchet);
  beep(notas[4][index_a], crotchet);    
  beep(notas[4][index_a], crotchet);
  beep(notas[4][index_f], dotted_quaver);
  beep(notas[5][index_c], semiquaver);

  beep(notas[4][index_a], crotchet);
  beep(notas[4][index_f], dotted_quaver);
  beep(notas[5][index_c], semiquaver);
  beep(notas[4][index_a], minim);
 
  beep(notas[5][index_e], crotchet);
  beep(notas[5][index_e], crotchet);
  beep(notas[5][index_e], crotchet);  
  beep(notas[5][index_f], dotted_quaver);
  beep(notas[5][index_c], semiquaver);

  beep(notas[4][index_gS], crotchet);
  beep(notas[4][index_f], dotted_quaver);
  beep(notas[5][index_c], semiquaver);
  beep(notas[4][index_a], minim);
 
}
 
void secondSection()
{
  beep(notas[5][index_a], crotchet);
  beep(notas[4][index_a], quaver);
  beep(notas[4][index_a], semiquaver);
  beep(notas[5][index_a], crotchet);
  beep(notas[5][index_gS], dotted_quaver);
  beep(notas[5][index_g], semiquaver);
  beep(notas[5][index_fS], semiquaver);
  beep(notas[5][index_f], semiquaver);    
  beep(notas[5][index_fS], quaver);
 
  beep(notas[4][index_aS], quaver);
  beep(notas[5][index_dS], crotchet);
  beep(notas[5][index_d], dotted_quaver);  
  beep(notas[5][index_cS], quaver);  
  beep(notas[5][index_c], semiquaver);  
  beep(notas[4][index_b], semiquaver);  
  beep(notas[5][index_c], quaver);  
 
}
