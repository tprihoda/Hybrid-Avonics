//Abstract avionics firmware template 
//r0
//4/9/2020
//R. Smith

#include <stdio.h>
#include <stdlib.h>

//State machine struct
typedef struct FSM {
	uint16_t cur_state = 0; //current state variable
	uint16_t next_state = 0; //next state variable
	uint32_t timers[5]; //an array of timers for non-blocking arrays
};

//declaration of state machines
FSM control_fsm;
FSM safety_fsm;
FSM logger_fsm;
FSM comm_fsm;

//enumerations of the various states for the state machines
enum control_states{C_IDLE, FILL, STANDBY, LAUNCH, RECOVER};
enum safety_states{NOMINAL, CAUUTION, WARNING, PROTECT};
enum logger_states{LOG_RUN, LOG_STOP};
enum comm_states{X_IDLE, UMBIL_COM, XBEE_COM};

//definitions of state machines
void control_fsm_run() {
	switch(control_fsm.cur_state) {
		case IDLE:

			do_stuff();

			if(start_fill_condition && safety_fsm.cur_state == NOMINAL) {
				control_fsm.next_state = FILL;
			} else {	
				control_fsm.next_state = IDLE;
			}

			break;

		case FILL:

			do_stuff();

			if(fill_complete_condition) {
				control_fsm.next_state = STANDBY;
			} else {
				control_fsm.next_state = FILL;
			}

			break;

		case STANDBY:

			do_stuff();

			if(ign_received) {	
				control_fsm.next_state = LAUNCH;
			} else {
				control_fsm.next_state = STANDBY;
			}

			break;

		case LAUNCH:
			
			do_stuff();

			if(apogee_detected) {
				control_fsm.next_state = RECOVER;
			} else {
				control_fsm.next_state = LAUNCH;
			}
			
			break;
		//.....same structure for recover
	}
	control_fsm.cur_state = control_fsm.next_state;
}

void safety_fsm_run() {
	switch(safety_fsm.cur_state) {


	}
}

void logger_fsm_run() {
	switch(logger_fsm.cur_state) {
		

	}
}

void comm_fsm_run() {
	switch(comm_fsm.cur_state) {


	}
}


int main() {
	for(;;) {
		safety_fsm_run();
		control_fsm_run();
		logger_fsm_run();
		comm_fsm_run();	
		//delay(n);
	}
	return 0;
}
