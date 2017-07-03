/*****************************************************
 * Code pour la réalisation d'un anémomètre grace a  *
 * Arduino et un capteur Hall fait grace au hardware *
 * hacking d'un Fan d'ordinateur                     *
 *****************************************************/                       
const int  brocheSignal = 13; //Broche digitale où est branché le capteur à affet Hall
unsigned long periode;        //Variable qui vas stocker le temps qui separe deux passage

void setup() {
  pinMode(brocheSignal, INPUT); //initialisation de la variable "brocheSignal" en tant qu'entrée de signal
  Serial.begin(9600);           //initialisation de la communication par voie serie
}  
  void loop() {
  periode = pulseIn(brocheSignal, HIGH); //Enregistrement de temps entre deux passage(pérode)
  Serial.print("Periode:");              //Affichage du temps de passage sur la voie serie
  Serial.println(periode);
  Serial.print("Vitesse:");              //Affichage de la vitesse en mètre par seconde sur la voie serie
  Serial.print(2 * 3.14 * R * pow(10, 6) / periode); //Remplacer "R" le rayon de votre anémomètre par sa valeur en metre(m)
  Serial.println("m/s");
}
