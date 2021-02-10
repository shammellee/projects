#include <stdlib.h>
#include <unistd.h>

#include "state_machine.h"

STATE_MACHINE machine;

int main(void)
{
  state_machine_init(&machine);

  for(;;)
  {
    machine.p_state(&machine);
    sleep(1);
  }


  return EXIT_SUCCESS;
}

