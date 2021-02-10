#ifndef STATE_MACHINE__H
#define STATE_MACHINE__H
#include <stdio.h>
#include <string.h>

typedef enum
{
  IDLE
  ,RUNNING
  ,STOPPED
} MACHINE_STATE;

typedef struct state_machine
{
  unsigned int state_change_count;

  void (* p_state)(struct state_machine *);
} STATE_MACHINE;

static void idle(STATE_MACHINE *);
static void running(STATE_MACHINE *);
static void stopped(STATE_MACHINE *);
void state_machine_set_state(MACHINE_STATE, STATE_MACHINE *);


static void idle(STATE_MACHINE * machine)
{
  printf("IDLE\n");
  state_machine_set_state(RUNNING, machine);
}

static void running(STATE_MACHINE * machine)
{
  printf("RUNNING\n");
  state_machine_set_state(IDLE, machine);
}

static void stopped(STATE_MACHINE * machine)
{
  printf("STOPPED\n");
  state_machine_set_state(STOPPED, machine);
}

void state_machine_init(STATE_MACHINE * machine)
{
  state_machine_set_state(IDLE, machine);
}

static void state_machine_state_changed(STATE_MACHINE * machine)
{
  printf("State change #%d: ", ++(machine->state_change_count));
}

void state_machine_set_state(MACHINE_STATE state, STATE_MACHINE * machine)
{
  switch(state)
  {
    case IDLE:
    machine->p_state = (void(*)(STATE_MACHINE *)) idle;
    state_machine_state_changed(machine);
    break;
    case RUNNING:
    machine->p_state = (void(*)(STATE_MACHINE *)) running;
    state_machine_state_changed(machine);
    break;
    case STOPPED:
    machine->p_state = (void(*)(STATE_MACHINE *)) stopped;
    state_machine_state_changed(machine);
    default:
    break;
  }
}
#endif // STATE_MACHINE__H

