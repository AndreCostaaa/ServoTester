#include "Fonction.h"

void TreatementSwitch() //Traiter la saisie du switch
{
  //Si on presse sur le switch
  if (bS1 == FLANC_ACTIF)
  {
    bMode++;

    //Bloquer le mode entre 1 et 3
    if (bMode == 4)
    {
      bMode = 1;
    }
  }
}
void TreatementPot()
{
  //lecture du potentiometre sera entre 0 et 1023.
  //Sur le servo on doit donner une valeur entre 0 et 180
  //Fonction map me donne la valeur nécessaire à donner au servo
  iPot = map(iPot, 0, 1023, 0, 180);
}

void TreatementMode()
{
  //Traitement de la variable bMode. Ici on utilisera plus les numeros mais des mots (plus propre)
  switch (bMode)
  {
    case 1:

      //bMode = 1 sera le mode Neutre
      eMode = NEUTRAL;

      //On arrêtera le servo (dans la gestion des sorties, ici on change juste la variable qu'on donnera au servo)
      bServoPos = SERVO_STOP;

      
      //On allumera la led equivalente au Mode Neutre et on eteignera celle du mode ancien
      boL1 = true;
      boL3 = false;
      break;
    case 2:

      //bMode = 2 sera le mode Manuel
      eMode = MANUAL;

      //Cette ligne de code sert juste a des qu'on change de mode Auto, le servo avance/recule depuis la position ou il était et pas depuis une position prédefinie
      //Elle n'est pas necessaire mais ça devient plus propre a mon avis
      bServoPos = iPot;

      //On allumera la led equivalente au Mode Neutre et on eteignera celle du mode ancien
      boL1 = false;
      boL2 = true;
      break;

    case 3:

      //bMode = 3 sera le mode Automatique
      eMode = AUTO;

      //On allumera la led equivalente au Mode Neutre et on eteignera celle du mode ancien
      boL2 = false;
      boL3 = true;

      //Pour ne pas bloquer le programme, on augmentera à chaque fois la variable qu'on donnera au servo
      //Des qu'on arrive a 180, au lieu de revenir directement a 0, on va juste descendre à 179, 178, etc...
      //Des qu'on arrive a 0, on reaugmentera cette variable
      //Ce traitement est fait à partir de une variable boolean (boServoUp)
      
      //Mise à jour de la variable boolean qui controle si on doit augmenter on diminuer dès qu'on arrive à la limite du servo
      if (bServoPos == 180)
      {
        boServoUp = false;
      }
      if (bServoPos == 0)
      {
        boServoUp = true;
      }
      
      //Si on doit augmenter la variable (On était à 0 et on doit revenir a 180)
      if (boServoUp)
      {
        bServoPos++;
      }
     
      //Si on ne doit pas augmenter, on doit la diminuer (On était à 180 et on doit revenir à 0)
      else
      {
        bServoPos--;
      }
      break;
  }
}
