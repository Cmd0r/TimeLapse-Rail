//fonction a appeler lors du setup. Allege le main
void initialisation()
{
  //init des pins moteur
  pinMode(PIIN1, OUTPUT);
  pinMode(PIIN2, OUTPUT);
  pinMode(PIIN3, OUTPUT);
  pinMode(PIIN4, OUTPUT);
  digitalWrite(PIIN1, LOW);
  digitalWrite(PIIN2, LOW);
  digitalWrite(PIIN3, LOW);
  digitalWrite(PIIN4, LOW);
  
  //init des fin de course
  pinMode(STOP_DEBUT, INPUT);
  pinMode(STOP_FIN, INPUT);
}
