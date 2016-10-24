//lit la taille du rail sur 4 octets
long lireTailleRail()
{
  long retTaille = EEPROM.read(0);
  retTaille = retTaille * 256 + EEPROM.read(1);
  retTaille = retTaille * 256 + EEPROM.read(2);
  retTaille = retTaille * 256 + EEPROM.read(3);
  
  return retTaille;
}

//ecrit la taille du rail en memoire sur 4 octets
void ecrireTailleRail(long taille)
{
  EEPROM.write(3, taille % 256);
  taille = taille / 256L;
  EEPROM.write(2, taille % 256);
  taille = taille / 256L;
  EEPROM.write(1, taille % 256);
  taille = taille / 256L;
  EEPROM.write(0, taille % 256);
}
