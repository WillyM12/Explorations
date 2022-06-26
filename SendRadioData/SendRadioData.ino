#include <VirtualWire.h>

const char *message = "ConnectIO : capteurs, actionneurs"; // la chaîne de caractères à transmettre

void setup()
{
  vw_setup(5000);	 //la vitesse de transmission de données en bits pas sec.
}

void loop()
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); //attendre que le message soit transmis
  delay(1000); //attendre 1000 millisecondes avant la retransmission suivante
}