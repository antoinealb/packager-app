#include <stdio.h>
#include <state-machine/state_machine.h>

void state1(state_machine_t *machine);
void state2(state_machine_t *machine);

int main(void)
{
    state_machine_t *machine;
    machine = state_machine_create();
    state_machine_set_current_state(machine, state1);

    while (state_machine_state_is_valid(machine)) {
        state_machine_run(machine);
    }

    state_machine_delete(machine);

    return 0;
}

void state1(state_machine_t *machine)
{
    /* If we read '/' change state to state2, otherwise stay in state1. */
    if (getchar() == '/') {
        state_machine_set_current_state(machine, state2);
    }
}

void state2(state_machine_t *machine)
{
    if (getchar() == '/') {
        state_machine_exit(machine);
    } else {
        state_machine_set_current_state(machine, state1);
    }
}
