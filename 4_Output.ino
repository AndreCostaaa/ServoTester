#include "Fonction.h"

void ServoMotor()
{
  //Ici le traitement de la variable a été faite et on utilise plus bMode mais si eMode
  //bMode c'est une variable byte que contient des chiffres
  //eMode on a traduit ce chiffre en mots pour que ça soit plus propre
  //Completement inecessaire mais peut nous aider à débugger 
  
  switch (eMode)
  { 

    //Si on est en mode Neutre bServoPos sera = SERVO_STOP (voir fonction TreatementMode case 1)
    //En mode auto le traitement de la variable bServoPos a été fait avant (voir fonction TreatementMode case 3)
    //Vu que la variable utilisé est la même j'ai regroupé les deux cases
    case AUTO: 
    case NEUTRAL: servo.write(bServoPos);

    
      break;

    //Variable iPot vaudra entre 0 et 180 et va dependre de la position du potentiometre (voir fonction UserInput et TreatementPot)
    case MANUAL: servo.write(iPot);
      break;
  }
}
void Leds()
{
  //variables boLX ont été changés en fonction du mode choisi (voir fonction TreatementMode)
  digitalWrite(D1, boL1);
  digitalWrite(D2, boL2);
  digitalWrite(D3, boL3);
}
