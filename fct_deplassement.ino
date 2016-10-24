void tourne_plus(int nbseq, int delaims)
{
  for(int i =0; i<nbseq; i++) //50 pour un tour
  {
    if(0 == digitalRead(STOP_FIN))
    {
      digitalWrite(PIIN1, HIGH);
      digitalWrite(PIIN2, LOW);
      digitalWrite(PIIN3, LOW);
      digitalWrite(PIIN4, HIGH);
      delay(delaims);
      digitalWrite(PIIN1, HIGH);
      digitalWrite(PIIN2, LOW);
      digitalWrite(PIIN3, HIGH);
      digitalWrite(PIIN4, LOW);
      delay(delaims);
      digitalWrite(PIIN1, LOW);
      digitalWrite(PIIN2, HIGH);
      digitalWrite(PIIN3, HIGH);
      digitalWrite(PIIN4, LOW);
      delay(delaims);
      digitalWrite(PIIN1, LOW);
      digitalWrite(PIIN2, HIGH);
      digitalWrite(PIIN3, LOW);
      digitalWrite(PIIN4, HIGH);
      delay(delaims);
    }
    positionActuelle+=4;
  }
}

void tourne_moins(int nbseq, int delaims)
{
  for(int i =0; i<nbseq; i++) //50 pour un tour
  {
    if(0 == digitalRead(STOP_DEBUT))
    {
      digitalWrite(PIIN1, LOW);
      digitalWrite(PIIN2, HIGH);
      digitalWrite(PIIN3, LOW);
      digitalWrite(PIIN4, HIGH);
      delay(delaims);
      digitalWrite(PIIN1, LOW);
      digitalWrite(PIIN2, HIGH);
      digitalWrite(PIIN3, HIGH);
      digitalWrite(PIIN4, LOW);
      delay(delaims);
      digitalWrite(PIIN1, HIGH);
      digitalWrite(PIIN2, LOW);
      digitalWrite(PIIN3, HIGH);
      digitalWrite(PIIN4, LOW);
      delay(delaims);
      digitalWrite(PIIN1, HIGH);
      digitalWrite(PIIN2, LOW);
      digitalWrite(PIIN3, LOW);
      digitalWrite(PIIN4, HIGH);
      delay(delaims);
    }
    positionActuelle-=4;
  }
}

//ramene le chariot a zero
void zero(void)
{
  while(1 != digitalRead(STOP_DEBUT))
  {
    /*#if defined (DEBUG)
      Serial.println(sequenceActuelle);
    #endif*/
    
    tourneseq(0, sequenceActuelle, delai);
    sequenceActuelle++;
    if(sequenceActuelle>=5)
    {
      sequenceActuelle = 1;
    }
  }
  
  positionActuelle = 0;
}

//sens : 0 moins 1 plus / seq : de 1 à 4
void tourneseq(int sens, int seq, int delaims)
{
  switch(sens)
  {
    case 0: //sens moins
      if(0 == digitalRead(STOP_DEBUT))
      {
        switch(seq)
        {
          case 1:
            digitalWrite(PIIN1, LOW);
            digitalWrite(PIIN2, HIGH);
            digitalWrite(PIIN3, LOW);
            digitalWrite(PIIN4, HIGH);
            delay(delaims);
          break;
          case 2:
            digitalWrite(PIIN1, LOW);
            digitalWrite(PIIN2, HIGH);
            digitalWrite(PIIN3, HIGH);
            digitalWrite(PIIN4, LOW);
            delay(delaims);
          break;
          case 3:
            digitalWrite(PIIN1, HIGH);
            digitalWrite(PIIN2, LOW);
            digitalWrite(PIIN3, HIGH);
            digitalWrite(PIIN4, LOW);
            delay(delaims);
          break;
          case 4:
            digitalWrite(PIIN1, HIGH);
            digitalWrite(PIIN2, LOW);
            digitalWrite(PIIN3, LOW);
            digitalWrite(PIIN4, HIGH);
            delay(delaims);
          break;
        }
      }
      positionActuelle--;
    break;
    case 1: //sens plus
      if(0 == digitalRead(STOP_FIN))
      {
        switch(seq)
        {
          case 1:
            digitalWrite(PIIN1, HIGH);
            digitalWrite(PIIN2, LOW);
            digitalWrite(PIIN3, LOW);
            digitalWrite(PIIN4, HIGH);
            delay(delaims);
          break;
          case 2:
            digitalWrite(PIIN1, HIGH);
            digitalWrite(PIIN2, LOW);
            digitalWrite(PIIN3, HIGH);
            digitalWrite(PIIN4, LOW);
            delay(delaims);
          break;
          case 3:
            digitalWrite(PIIN1, LOW);
            digitalWrite(PIIN2, HIGH);
            digitalWrite(PIIN3, HIGH);
            digitalWrite(PIIN4, LOW);
            delay(delaims);
          break;
          case 4:
            digitalWrite(PIIN1, LOW);
            digitalWrite(PIIN2, HIGH);
            digitalWrite(PIIN3, LOW);
            digitalWrite(PIIN4, HIGH);
            delay(delaims);
          break;
        }
      }
      positionActuelle++;
    break;
  }
}
