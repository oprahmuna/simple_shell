#include "shell.h"

/**
 * handle_segmentation_fault - Signal handler for segmentation faults.
 * @signo: Signal number (unused).
 */
void handle_segmentation_fault(int signo __attribute__((unused)))
{
	/* Handle a segmentation fault gracefully by saving the program's state and exiting. */
	exit(1);
}

