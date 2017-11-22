/*
 * Header file for: diode_4
 * Generated with : PLECS 3.7.2
 * Generated on   : Fri Feb 17 23:52:28 2017
 */
#ifndef PLECS_HEADER_diode_4_h_
#define PLECS_HEADER_diode_4_h_


/* Model checksum */
extern const char * const diode_4_checksum;

/* Model error status */
extern const char * diode_4_errorStatus;


/* Model sample time */
extern const double diode_4_sampleTime;


/*
 * Model states
 *  - Physical state variables:
 *     0: diode_4/L1
 *     1: diode_4/C1
 *  - Switch state variables:
 *     2: diode_4/D1
 *     3: diode_4/D2
 *     4: diode_4/D3
 *     5: diode_4/D4
 */
typedef double diode_4_ModelStates[6];
extern diode_4_ModelStates diode_4_X;


/* Entry point functions */
void diode_4_initialize(double time);
void diode_4_step(void);
void diode_4_terminate(void);

#endif /* PLECS_HEADER_diode_4_h_ */
