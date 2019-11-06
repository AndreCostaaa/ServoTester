#include "Fonction.h"

void UserInput() //Lire le switch et le potentiomètre
{
  bS1 = Antirebond(S1, bS1);
  iPot = analogRead(pot);
}
