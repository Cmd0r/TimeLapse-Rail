#include <EEPROM.h>

#define DEBUG


//4 pins du moteur
#define PIIN1 2
#define PIIN2 3
#define PIIN3 4
#define PIIN4 5

//pins fin course
#define STOP_DEBUT 14
#define STOP_FIN 15

//delai entre deux etapes de rotations
static int delai = 10;

//sequence pour faire tourner le moteur de 1 à 4
static int sequenceActuelle;

static int tailleRail = 0;

static int positionActuelle;


void setup()
{
  //initialisation des pins
  initialisation();
  
  //init de la sequence
  sequenceActuelle = 1;
  
  //lecture en EEPROM de la taille du rail
  tailleRail = lireTailleRail();
  
  //liaison serie de debug
  #if defined (DEBUG)
    Serial.begin(115200);
  #endif
}

void loop()
{
  Serial.println(lireTailleRail());
  ecrireTailleRail(123456789);
  Serial.println(lireTailleRail());
  delay(2000);
}
