//retourne la taille en step (200 par tour)
long sizeOfRail()
{
  long retTaille = 0L;
  //raz du chariot
  zero();
  
  while(1 != digitalRead(STOP_FIN))
  {
    tourneseq(1, sequenceActuelle, delai);
    sequenceActuelle++;
    retTaille = retTaille + 1L;
    if(sequenceActuelle>=5)
    {
      sequenceActuelle = 1;
    }
  }
  positionActuelle = retTaille;
  return retTaille;
}

//mise a jour de la taille du rail
void MAJTailleRail()
{
  ecrireTailleRail(sizeOfRail());
  tailleRail = lireTailleRail();
}

