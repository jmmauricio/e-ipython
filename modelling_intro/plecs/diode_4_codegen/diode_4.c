/*
 * Implementation file for: diode_4
 * Generated with         : PLECS 3.7.2
 * Generated on           : Fri Feb 17 23:52:28 2017
 */
#include "diode_4.h"
#ifndef PLECS_HEADER_diode_4_h_
#error The wrong header file "diode_4.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_diode_4_h_ */
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#define PLECSRunTimeError(msg) diode_4_errorStatus = msg
static uint32_t diode_4_D_uint32_t[1];
static char diode_4_first;
static double * diode_4_xEl;
static double diode_4_tmpXEl[2];
static double diode_4_prevXEl[2];
static double diode_4_uEl[1];
static double diode_4_prevUEl[1];
static double diode_4_yEl[2];
static double diode_4_sEl[8];
static double diode_4_sTolEl[8];
static char diode_4_withDiracs;
static uint32_t diode_4_topoIdxEl;
static const uint32_t AEl_0_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_0_colIdx[] = {
   0,1
};
static const double AEl_0_data[] = {
   1,0.9900497512437811
};
static const uint32_t BEl_0_rowPtr[] = {
   0,0,0
};
static const uint32_t BEl_0_colIdx[] = {
   0
};
static const double BEl_0_data[] = {
   0
};
static const uint32_t CEl_0_rowPtr[] = {
   0,1,1
};
static const uint32_t CEl_0_colIdx[] = {
   1
};
static const double CEl_0_data[] = {
   1
};
static const uint32_t DEl_0_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_0_colIdx[] = {
   0
};
static const double DEl_0_data[] = {
   0
};
static const uint32_t EEl_0_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t EEl_0_colIdx[] = {
   1,1,1,1
};
static const double EEl_0_data[] = {
   0.5,0.5,0.5,0.5
};
static const uint32_t FEl_0_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t FEl_0_colIdx[] = {
   0,0,0,0
};
static const double FEl_0_data[] = {
   0.5,-0.5,-0.5,0.5
};
static const uint32_t GEl_0_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t GEl_0_colIdx[] = {
   0,0,0,0
};
static const double GEl_0_data[] = {
   -0.0005,0.0005,0.0005,-0.0005
};
static const uint32_t HEl_0_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_0_colIdx[] = {
   0
};
static const double HEl_0_data[] = {
   0
};
static const uint32_t IEl_0_rowPtr[] = {
   0,0,1
};
static const uint32_t IEl_0_colIdx[] = {
   1
};
static const double IEl_0_data[] = {
   1
};
static const uint32_t KEl_0_rowPtr[] = {
   0,0,1
};
static const uint32_t KEl_0_colIdx[] = {
   1
};
static const double KEl_0_data[] = {
   1
};
static const uint32_t JEl_0_rowPtr[] = {
   0,0
};
static const uint32_t JEl_0_colIdx[] = {
   0
};
static const double JEl_0_data[] = {
   0
};
static const uint32_t AEl_1_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_1_colIdx[] = {
   0,1
};
static const double AEl_1_data[] = {
   1,0.9900497512437811
};
static const uint32_t BEl_1_rowPtr[] = {
   0,0,0
};
static const uint32_t BEl_1_colIdx[] = {
   0
};
static const double BEl_1_data[] = {
   0
};
static const uint32_t CEl_1_rowPtr[] = {
   0,1,1
};
static const uint32_t CEl_1_colIdx[] = {
   1
};
static const double CEl_1_data[] = {
   1
};
static const uint32_t DEl_1_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_1_colIdx[] = {
   0
};
static const double DEl_1_data[] = {
   0
};
static const uint32_t EEl_1_rowPtr[] = {
   0,0,1,1,2
};
static const uint32_t EEl_1_colIdx[] = {
   1,1
};
static const double EEl_1_data[] = {
   1,1
};
static const uint32_t FEl_1_rowPtr[] = {
   0,0,0,1,2
};
static const uint32_t FEl_1_colIdx[] = {
   0,0
};
static const double FEl_1_data[] = {
   -1,1
};
static const uint32_t GEl_1_rowPtr[] = {
   0,0,0,1,2
};
static const uint32_t GEl_1_colIdx[] = {
   0,0
};
static const double GEl_1_data[] = {
   0.001,-0.001
};
static const uint32_t HEl_1_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_1_colIdx[] = {
   0
};
static const double HEl_1_data[] = {
   0
};
static const uint32_t IEl_1_rowPtr[] = {
   0,0,1
};
static const uint32_t IEl_1_colIdx[] = {
   1
};
static const double IEl_1_data[] = {
   1
};
static const uint32_t KEl_1_rowPtr[] = {
   0,0,1
};
static const uint32_t KEl_1_colIdx[] = {
   1
};
static const double KEl_1_data[] = {
   1
};
static const uint32_t JEl_1_rowPtr[] = {
   0,0
};
static const uint32_t JEl_1_colIdx[] = {
   0
};
static const double JEl_1_data[] = {
   0
};
static const uint32_t AEl_2_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_2_colIdx[] = {
   0,1
};
static const double AEl_2_data[] = {
   1,0.9900497512437811
};
static const uint32_t BEl_2_rowPtr[] = {
   0,0,0
};
static const uint32_t BEl_2_colIdx[] = {
   0
};
static const double BEl_2_data[] = {
   0
};
static const uint32_t CEl_2_rowPtr[] = {
   0,1,1
};
static const uint32_t CEl_2_colIdx[] = {
   1
};
static const double CEl_2_data[] = {
   1
};
static const uint32_t DEl_2_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_2_colIdx[] = {
   0
};
static const double DEl_2_data[] = {
   0
};
static const uint32_t EEl_2_rowPtr[] = {
   0,1,1,2,2
};
static const uint32_t EEl_2_colIdx[] = {
   1,1
};
static const double EEl_2_data[] = {
   1,1
};
static const uint32_t FEl_2_rowPtr[] = {
   0,0,0,1,2
};
static const uint32_t FEl_2_colIdx[] = {
   0,0
};
static const double FEl_2_data[] = {
   -1,1
};
static const uint32_t GEl_2_rowPtr[] = {
   0,0,0,1,2
};
static const uint32_t GEl_2_colIdx[] = {
   0,0
};
static const double GEl_2_data[] = {
   0.001,-0.001
};
static const uint32_t HEl_2_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_2_colIdx[] = {
   0
};
static const double HEl_2_data[] = {
   0
};
static const uint32_t IEl_2_rowPtr[] = {
   0,0,1
};
static const uint32_t IEl_2_colIdx[] = {
   1
};
static const double IEl_2_data[] = {
   1
};
static const uint32_t KEl_2_rowPtr[] = {
   0,0,1
};
static const uint32_t KEl_2_colIdx[] = {
   1
};
static const double KEl_2_data[] = {
   1
};
static const uint32_t JEl_2_rowPtr[] = {
   0,0
};
static const uint32_t JEl_2_colIdx[] = {
   0
};
static const double JEl_2_data[] = {
   0
};
static const uint32_t AEl_3_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_3_colIdx[] = {
   0,1
};
static const double AEl_3_data[] = {
   1,1
};
static const uint32_t BEl_3_rowPtr[] = {
   0,0,0
};
static const uint32_t BEl_3_colIdx[] = {
   0
};
static const double BEl_3_data[] = {
   0
};
static const uint32_t CEl_3_rowPtr[] = {
   0,0,0
};
static const uint32_t CEl_3_colIdx[] = {
   0
};
static const double CEl_3_data[] = {
   0
};
static const uint32_t DEl_3_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_3_colIdx[] = {
   0
};
static const double DEl_3_data[] = {
   0
};
static const uint32_t EEl_3_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t EEl_3_colIdx[] = {
   0
};
static const double EEl_3_data[] = {
   0
};
static const uint32_t FEl_3_rowPtr[] = {
   0,0,0,1,2
};
static const uint32_t FEl_3_colIdx[] = {
   0,0
};
static const double FEl_3_data[] = {
   -1,1
};
static const uint32_t GEl_3_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t GEl_3_colIdx[] = {
   1,1,0,0
};
static const double GEl_3_data[] = {
   -0.001,-0.001,0.001,-0.001
};
static const uint32_t HEl_3_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_3_colIdx[] = {
   0
};
static const double HEl_3_data[] = {
   0
};
static const uint32_t IEl_3_rowPtr[] = {
   0,0,0
};
static const uint32_t IEl_3_colIdx[] = {
   0
};
static const double IEl_3_data[] = {
   0
};
static const uint32_t KEl_3_rowPtr[] = {
   0,0,0
};
static const uint32_t KEl_3_colIdx[] = {
   0
};
static const double KEl_3_data[] = {
   0
};
static const uint32_t JEl_3_rowPtr[] = {
   0,0
};
static const uint32_t JEl_3_colIdx[] = {
   0
};
static const double JEl_3_data[] = {
   0
};
static const uint32_t AEl_4_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_4_colIdx[] = {
   0,1
};
static const double AEl_4_data[] = {
   1,0.9900497512437811
};
static const uint32_t BEl_4_rowPtr[] = {
   0,0,0
};
static const uint32_t BEl_4_colIdx[] = {
   0
};
static const double BEl_4_data[] = {
   0
};
static const uint32_t CEl_4_rowPtr[] = {
   0,1,1
};
static const uint32_t CEl_4_colIdx[] = {
   1
};
static const double CEl_4_data[] = {
   1
};
static const uint32_t DEl_4_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_4_colIdx[] = {
   0
};
static const double DEl_4_data[] = {
   0
};
static const uint32_t EEl_4_rowPtr[] = {
   0,0,1,1,2
};
static const uint32_t EEl_4_colIdx[] = {
   1,1
};
static const double EEl_4_data[] = {
   1,1
};
static const uint32_t FEl_4_rowPtr[] = {
   0,1,2,2,2
};
static const uint32_t FEl_4_colIdx[] = {
   0,0
};
static const double FEl_4_data[] = {
   1,-1
};
static const uint32_t GEl_4_rowPtr[] = {
   0,1,2,2,2
};
static const uint32_t GEl_4_colIdx[] = {
   0,0
};
static const double GEl_4_data[] = {
   -0.001,0.001
};
static const uint32_t HEl_4_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_4_colIdx[] = {
   0
};
static const double HEl_4_data[] = {
   0
};
static const uint32_t IEl_4_rowPtr[] = {
   0,0,1
};
static const uint32_t IEl_4_colIdx[] = {
   1
};
static const double IEl_4_data[] = {
   1
};
static const uint32_t KEl_4_rowPtr[] = {
   0,0,1
};
static const uint32_t KEl_4_colIdx[] = {
   1
};
static const double KEl_4_data[] = {
   1
};
static const uint32_t JEl_4_rowPtr[] = {
   0,0
};
static const uint32_t JEl_4_colIdx[] = {
   0
};
static const double JEl_4_data[] = {
   0
};
static const uint32_t AEl_5_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_5_colIdx[] = {
   0,1
};
static const double AEl_5_data[] = {
   0.9047619047619047,0.9900497512437811
};
static const uint32_t BEl_5_rowPtr[] = {
   0,1,1
};
static const uint32_t BEl_5_colIdx[] = {
   0
};
static const double BEl_5_data[] = {
   0.4761904761904762
};
static const uint32_t CEl_5_rowPtr[] = {
   0,1,2
};
static const uint32_t CEl_5_colIdx[] = {
   1,0
};
static const double CEl_5_data[] = {
   1,1
};
static const uint32_t DEl_5_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_5_colIdx[] = {
   0
};
static const double DEl_5_data[] = {
   0
};
static const uint32_t EEl_5_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t EEl_5_colIdx[] = {
   0,1,0,1
};
static const double EEl_5_data[] = {
   1,1,-1,1
};
static const uint32_t FEl_5_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t FEl_5_colIdx[] = {
   0
};
static const double FEl_5_data[] = {
   0
};
static const uint32_t GEl_5_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t GEl_5_colIdx[] = {
   0
};
static const double GEl_5_data[] = {
   0
};
static const uint32_t HEl_5_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_5_colIdx[] = {
   0
};
static const double HEl_5_data[] = {
   0
};
static const uint32_t IEl_5_rowPtr[] = {
   0,1,2
};
static const uint32_t IEl_5_colIdx[] = {
   0,1
};
static const double IEl_5_data[] = {
   1,1
};
static const uint32_t KEl_5_rowPtr[] = {
   0,1,2
};
static const uint32_t KEl_5_colIdx[] = {
   0,1
};
static const double KEl_5_data[] = {
   1,1
};
static const uint32_t JEl_5_rowPtr[] = {
   0,0
};
static const uint32_t JEl_5_colIdx[] = {
   0
};
static const double JEl_5_data[] = {
   0
};
static const uint32_t AEl_6_rowPtr[] = {
   0,2,4
};
static const uint32_t AEl_6_colIdx[] = {
   0,1,0,1
};
static const double AEl_6_data[] = {
   0.53993487837579,-0.7661367554108408,0.7661367554108408,0.6088871863627658
};
static const uint32_t BEl_6_rowPtr[] = {
   0,1,2
};
static const uint32_t BEl_6_colIdx[] = {
   0,0
};
static const double BEl_6_data[] = {
   0.3849837195939475,0.1915341888527102
};
static const uint32_t CEl_6_rowPtr[] = {
   0,1,2
};
static const uint32_t CEl_6_colIdx[] = {
   1,0
};
static const double CEl_6_data[] = {
   1,1
};
static const uint32_t DEl_6_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_6_colIdx[] = {
   0
};
static const double DEl_6_data[] = {
   0
};
static const uint32_t EEl_6_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t EEl_6_colIdx[] = {
   1,0,0,1
};
static const double EEl_6_data[] = {
   1,-1,-1,1
};
static const uint32_t FEl_6_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t FEl_6_colIdx[] = {
   0
};
static const double FEl_6_data[] = {
   0
};
static const uint32_t GEl_6_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t GEl_6_colIdx[] = {
   0
};
static const double GEl_6_data[] = {
   0
};
static const uint32_t HEl_6_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_6_colIdx[] = {
   0
};
static const double HEl_6_data[] = {
   0
};
static const uint32_t IEl_6_rowPtr[] = {
   0,1,2
};
static const uint32_t IEl_6_colIdx[] = {
   0,1
};
static const double IEl_6_data[] = {
   1,1
};
static const uint32_t KEl_6_rowPtr[] = {
   0,1,2
};
static const uint32_t KEl_6_colIdx[] = {
   0,1
};
static const double KEl_6_data[] = {
   1,1
};
static const uint32_t JEl_6_rowPtr[] = {
   0,0
};
static const uint32_t JEl_6_colIdx[] = {
   0
};
static const double JEl_6_data[] = {
   0
};
static const uint32_t AEl_7_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_7_colIdx[] = {
   0,1
};
static const double AEl_7_data[] = {
   0.9047619047619047,1
};
static const uint32_t BEl_7_rowPtr[] = {
   0,1,1
};
static const uint32_t BEl_7_colIdx[] = {
   0
};
static const double BEl_7_data[] = {
   0.4761904761904762
};
static const uint32_t CEl_7_rowPtr[] = {
   0,0,1
};
static const uint32_t CEl_7_colIdx[] = {
   0
};
static const double CEl_7_data[] = {
   1
};
static const uint32_t DEl_7_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_7_colIdx[] = {
   0
};
static const double DEl_7_data[] = {
   0
};
static const uint32_t EEl_7_rowPtr[] = {
   0,1,1,2,2
};
static const uint32_t EEl_7_colIdx[] = {
   0,0
};
static const double EEl_7_data[] = {
   1,-1
};
static const uint32_t FEl_7_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t FEl_7_colIdx[] = {
   0
};
static const double FEl_7_data[] = {
   0
};
static const uint32_t GEl_7_rowPtr[] = {
   0,1,2,2,2
};
static const uint32_t GEl_7_colIdx[] = {
   1,1
};
static const double GEl_7_data[] = {
   -0.001,-0.001
};
static const uint32_t HEl_7_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_7_colIdx[] = {
   0
};
static const double HEl_7_data[] = {
   0
};
static const uint32_t IEl_7_rowPtr[] = {
   0,1,1
};
static const uint32_t IEl_7_colIdx[] = {
   0
};
static const double IEl_7_data[] = {
   1
};
static const uint32_t KEl_7_rowPtr[] = {
   0,1,1
};
static const uint32_t KEl_7_colIdx[] = {
   0
};
static const double KEl_7_data[] = {
   1
};
static const uint32_t JEl_7_rowPtr[] = {
   0,0
};
static const uint32_t JEl_7_colIdx[] = {
   0
};
static const double JEl_7_data[] = {
   0
};
static const uint32_t AEl_8_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_8_colIdx[] = {
   0,1
};
static const double AEl_8_data[] = {
   1,0.9900497512437811
};
static const uint32_t BEl_8_rowPtr[] = {
   0,0,0
};
static const uint32_t BEl_8_colIdx[] = {
   0
};
static const double BEl_8_data[] = {
   0
};
static const uint32_t CEl_8_rowPtr[] = {
   0,1,1
};
static const uint32_t CEl_8_colIdx[] = {
   1
};
static const double CEl_8_data[] = {
   1
};
static const uint32_t DEl_8_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_8_colIdx[] = {
   0
};
static const double DEl_8_data[] = {
   0
};
static const uint32_t EEl_8_rowPtr[] = {
   0,1,1,2,2
};
static const uint32_t EEl_8_colIdx[] = {
   1,1
};
static const double EEl_8_data[] = {
   1,1
};
static const uint32_t FEl_8_rowPtr[] = {
   0,1,2,2,2
};
static const uint32_t FEl_8_colIdx[] = {
   0,0
};
static const double FEl_8_data[] = {
   1,-1
};
static const uint32_t GEl_8_rowPtr[] = {
   0,1,2,2,2
};
static const uint32_t GEl_8_colIdx[] = {
   0,0
};
static const double GEl_8_data[] = {
   -0.001,0.001
};
static const uint32_t HEl_8_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_8_colIdx[] = {
   0
};
static const double HEl_8_data[] = {
   0
};
static const uint32_t IEl_8_rowPtr[] = {
   0,0,1
};
static const uint32_t IEl_8_colIdx[] = {
   1
};
static const double IEl_8_data[] = {
   1
};
static const uint32_t KEl_8_rowPtr[] = {
   0,0,1
};
static const uint32_t KEl_8_colIdx[] = {
   1
};
static const double KEl_8_data[] = {
   1
};
static const uint32_t JEl_8_rowPtr[] = {
   0,0
};
static const uint32_t JEl_8_colIdx[] = {
   0
};
static const double JEl_8_data[] = {
   0
};
static const uint32_t AEl_9_rowPtr[] = {
   0,2,4
};
static const uint32_t AEl_9_colIdx[] = {
   0,1,0,1
};
static const double AEl_9_data[] = {
   0.53993487837579,0.7661367554108408,-0.7661367554108408,0.6088871863627658
};
static const uint32_t BEl_9_rowPtr[] = {
   0,1,2
};
static const uint32_t BEl_9_colIdx[] = {
   0,0
};
static const double BEl_9_data[] = {
   0.3849837195939475,-0.1915341888527102
};
static const uint32_t CEl_9_rowPtr[] = {
   0,1,2
};
static const uint32_t CEl_9_colIdx[] = {
   1,0
};
static const double CEl_9_data[] = {
   1,1
};
static const uint32_t DEl_9_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_9_colIdx[] = {
   0
};
static const double DEl_9_data[] = {
   0
};
static const uint32_t EEl_9_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t EEl_9_colIdx[] = {
   0,1,1,0
};
static const double EEl_9_data[] = {
   1,1,1,1
};
static const uint32_t FEl_9_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t FEl_9_colIdx[] = {
   0
};
static const double FEl_9_data[] = {
   0
};
static const uint32_t GEl_9_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t GEl_9_colIdx[] = {
   0
};
static const double GEl_9_data[] = {
   0
};
static const uint32_t HEl_9_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_9_colIdx[] = {
   0
};
static const double HEl_9_data[] = {
   0
};
static const uint32_t IEl_9_rowPtr[] = {
   0,1,2
};
static const uint32_t IEl_9_colIdx[] = {
   0,1
};
static const double IEl_9_data[] = {
   1,1
};
static const uint32_t KEl_9_rowPtr[] = {
   0,1,2
};
static const uint32_t KEl_9_colIdx[] = {
   0,1
};
static const double KEl_9_data[] = {
   1,1
};
static const uint32_t JEl_9_rowPtr[] = {
   0,0
};
static const uint32_t JEl_9_colIdx[] = {
   0
};
static const double JEl_9_data[] = {
   0
};
static const uint32_t AEl_10_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_10_colIdx[] = {
   0,1
};
static const double AEl_10_data[] = {
   0.9047619047619047,0.9900497512437811
};
static const uint32_t BEl_10_rowPtr[] = {
   0,1,1
};
static const uint32_t BEl_10_colIdx[] = {
   0
};
static const double BEl_10_data[] = {
   0.4761904761904762
};
static const uint32_t CEl_10_rowPtr[] = {
   0,1,2
};
static const uint32_t CEl_10_colIdx[] = {
   1,0
};
static const double CEl_10_data[] = {
   1,1
};
static const uint32_t DEl_10_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_10_colIdx[] = {
   0
};
static const double DEl_10_data[] = {
   0
};
static const uint32_t EEl_10_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t EEl_10_colIdx[] = {
   1,0,1,0
};
static const double EEl_10_data[] = {
   1,-1,1,1
};
static const uint32_t FEl_10_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t FEl_10_colIdx[] = {
   0
};
static const double FEl_10_data[] = {
   0
};
static const uint32_t GEl_10_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t GEl_10_colIdx[] = {
   0
};
static const double GEl_10_data[] = {
   0
};
static const uint32_t HEl_10_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_10_colIdx[] = {
   0
};
static const double HEl_10_data[] = {
   0
};
static const uint32_t IEl_10_rowPtr[] = {
   0,1,2
};
static const uint32_t IEl_10_colIdx[] = {
   0,1
};
static const double IEl_10_data[] = {
   1,1
};
static const uint32_t KEl_10_rowPtr[] = {
   0,1,2
};
static const uint32_t KEl_10_colIdx[] = {
   0,1
};
static const double KEl_10_data[] = {
   1,1
};
static const uint32_t JEl_10_rowPtr[] = {
   0,0
};
static const uint32_t JEl_10_colIdx[] = {
   0
};
static const double JEl_10_data[] = {
   0
};
static const uint32_t AEl_11_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_11_colIdx[] = {
   0,1
};
static const double AEl_11_data[] = {
   0.9047619047619047,1
};
static const uint32_t BEl_11_rowPtr[] = {
   0,1,1
};
static const uint32_t BEl_11_colIdx[] = {
   0
};
static const double BEl_11_data[] = {
   0.4761904761904762
};
static const uint32_t CEl_11_rowPtr[] = {
   0,0,1
};
static const uint32_t CEl_11_colIdx[] = {
   0
};
static const double CEl_11_data[] = {
   1
};
static const uint32_t DEl_11_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_11_colIdx[] = {
   0
};
static const double DEl_11_data[] = {
   0
};
static const uint32_t EEl_11_rowPtr[] = {
   0,0,1,1,2
};
static const uint32_t EEl_11_colIdx[] = {
   0,0
};
static const double EEl_11_data[] = {
   -1,1
};
static const uint32_t FEl_11_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t FEl_11_colIdx[] = {
   0
};
static const double FEl_11_data[] = {
   0
};
static const uint32_t GEl_11_rowPtr[] = {
   0,1,2,2,2
};
static const uint32_t GEl_11_colIdx[] = {
   1,1
};
static const double GEl_11_data[] = {
   -0.001,-0.001
};
static const uint32_t HEl_11_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_11_colIdx[] = {
   0
};
static const double HEl_11_data[] = {
   0
};
static const uint32_t IEl_11_rowPtr[] = {
   0,1,1
};
static const uint32_t IEl_11_colIdx[] = {
   0
};
static const double IEl_11_data[] = {
   1
};
static const uint32_t KEl_11_rowPtr[] = {
   0,1,1
};
static const uint32_t KEl_11_colIdx[] = {
   0
};
static const double KEl_11_data[] = {
   1
};
static const uint32_t JEl_11_rowPtr[] = {
   0,0
};
static const uint32_t JEl_11_colIdx[] = {
   0
};
static const double JEl_11_data[] = {
   0
};
static const uint32_t AEl_12_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_12_colIdx[] = {
   0,1
};
static const double AEl_12_data[] = {
   1,1
};
static const uint32_t BEl_12_rowPtr[] = {
   0,0,0
};
static const uint32_t BEl_12_colIdx[] = {
   0
};
static const double BEl_12_data[] = {
   0
};
static const uint32_t CEl_12_rowPtr[] = {
   0,0,0
};
static const uint32_t CEl_12_colIdx[] = {
   0
};
static const double CEl_12_data[] = {
   0
};
static const uint32_t DEl_12_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_12_colIdx[] = {
   0
};
static const double DEl_12_data[] = {
   0
};
static const uint32_t EEl_12_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t EEl_12_colIdx[] = {
   0
};
static const double EEl_12_data[] = {
   0
};
static const uint32_t FEl_12_rowPtr[] = {
   0,1,2,2,2
};
static const uint32_t FEl_12_colIdx[] = {
   0,0
};
static const double FEl_12_data[] = {
   1,-1
};
static const uint32_t GEl_12_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t GEl_12_colIdx[] = {
   0,0,1,1
};
static const double GEl_12_data[] = {
   -0.001,0.001,-0.001,-0.001
};
static const uint32_t HEl_12_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_12_colIdx[] = {
   0
};
static const double HEl_12_data[] = {
   0
};
static const uint32_t IEl_12_rowPtr[] = {
   0,0,0
};
static const uint32_t IEl_12_colIdx[] = {
   0
};
static const double IEl_12_data[] = {
   0
};
static const uint32_t KEl_12_rowPtr[] = {
   0,0,0
};
static const uint32_t KEl_12_colIdx[] = {
   0
};
static const double KEl_12_data[] = {
   0
};
static const uint32_t JEl_12_rowPtr[] = {
   0,0
};
static const uint32_t JEl_12_colIdx[] = {
   0
};
static const double JEl_12_data[] = {
   0
};
static const uint32_t AEl_13_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_13_colIdx[] = {
   0,1
};
static const double AEl_13_data[] = {
   0.9047619047619047,1
};
static const uint32_t BEl_13_rowPtr[] = {
   0,1,1
};
static const uint32_t BEl_13_colIdx[] = {
   0
};
static const double BEl_13_data[] = {
   0.4761904761904762
};
static const uint32_t CEl_13_rowPtr[] = {
   0,0,1
};
static const uint32_t CEl_13_colIdx[] = {
   0
};
static const double CEl_13_data[] = {
   1
};
static const uint32_t DEl_13_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_13_colIdx[] = {
   0
};
static const double DEl_13_data[] = {
   0
};
static const uint32_t EEl_13_rowPtr[] = {
   0,1,1,2,2
};
static const uint32_t EEl_13_colIdx[] = {
   0,0
};
static const double EEl_13_data[] = {
   1,-1
};
static const uint32_t FEl_13_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t FEl_13_colIdx[] = {
   0
};
static const double FEl_13_data[] = {
   0
};
static const uint32_t GEl_13_rowPtr[] = {
   0,0,0,1,2
};
static const uint32_t GEl_13_colIdx[] = {
   1,1
};
static const double GEl_13_data[] = {
   -0.001,-0.001
};
static const uint32_t HEl_13_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_13_colIdx[] = {
   0
};
static const double HEl_13_data[] = {
   0
};
static const uint32_t IEl_13_rowPtr[] = {
   0,1,1
};
static const uint32_t IEl_13_colIdx[] = {
   0
};
static const double IEl_13_data[] = {
   1
};
static const uint32_t KEl_13_rowPtr[] = {
   0,1,1
};
static const uint32_t KEl_13_colIdx[] = {
   0
};
static const double KEl_13_data[] = {
   1
};
static const uint32_t JEl_13_rowPtr[] = {
   0,0
};
static const uint32_t JEl_13_colIdx[] = {
   0
};
static const double JEl_13_data[] = {
   0
};
static const uint32_t AEl_14_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_14_colIdx[] = {
   0,1
};
static const double AEl_14_data[] = {
   0.9047619047619047,1
};
static const uint32_t BEl_14_rowPtr[] = {
   0,1,1
};
static const uint32_t BEl_14_colIdx[] = {
   0
};
static const double BEl_14_data[] = {
   0.4761904761904762
};
static const uint32_t CEl_14_rowPtr[] = {
   0,0,1
};
static const uint32_t CEl_14_colIdx[] = {
   0
};
static const double CEl_14_data[] = {
   1
};
static const uint32_t DEl_14_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_14_colIdx[] = {
   0
};
static const double DEl_14_data[] = {
   0
};
static const uint32_t EEl_14_rowPtr[] = {
   0,0,1,1,2
};
static const uint32_t EEl_14_colIdx[] = {
   0,0
};
static const double EEl_14_data[] = {
   -1,1
};
static const uint32_t FEl_14_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t FEl_14_colIdx[] = {
   0
};
static const double FEl_14_data[] = {
   0
};
static const uint32_t GEl_14_rowPtr[] = {
   0,0,0,1,2
};
static const uint32_t GEl_14_colIdx[] = {
   1,1
};
static const double GEl_14_data[] = {
   -0.001,-0.001
};
static const uint32_t HEl_14_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_14_colIdx[] = {
   0
};
static const double HEl_14_data[] = {
   0
};
static const uint32_t IEl_14_rowPtr[] = {
   0,1,1
};
static const uint32_t IEl_14_colIdx[] = {
   0
};
static const double IEl_14_data[] = {
   1
};
static const uint32_t KEl_14_rowPtr[] = {
   0,1,1
};
static const uint32_t KEl_14_colIdx[] = {
   0
};
static const double KEl_14_data[] = {
   1
};
static const uint32_t JEl_14_rowPtr[] = {
   0,0
};
static const uint32_t JEl_14_colIdx[] = {
   0
};
static const double JEl_14_data[] = {
   0
};
static const uint32_t AEl_15_rowPtr[] = {
   0,1,2
};
static const uint32_t AEl_15_colIdx[] = {
   0,1
};
static const double AEl_15_data[] = {
   0.9047619047619047,1
};
static const uint32_t BEl_15_rowPtr[] = {
   0,1,1
};
static const uint32_t BEl_15_colIdx[] = {
   0
};
static const double BEl_15_data[] = {
   0.4761904761904762
};
static const uint32_t CEl_15_rowPtr[] = {
   0,0,1
};
static const uint32_t CEl_15_colIdx[] = {
   0
};
static const double CEl_15_data[] = {
   1
};
static const uint32_t DEl_15_rowPtr[] = {
   0,0,0
};
static const uint32_t DEl_15_colIdx[] = {
   0
};
static const double DEl_15_data[] = {
   0
};
static const uint32_t EEl_15_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t EEl_15_colIdx[] = {
   0,0,0,0
};
static const double EEl_15_data[] = {
   0.5,-0.5,-0.5,0.5
};
static const uint32_t FEl_15_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t FEl_15_colIdx[] = {
   0
};
static const double FEl_15_data[] = {
   0
};
static const uint32_t GEl_15_rowPtr[] = {
   0,1,2,3,4
};
static const uint32_t GEl_15_colIdx[] = {
   1,1,1,1
};
static const double GEl_15_data[] = {
   -0.0005,-0.0005,-0.0005,-0.0005
};
static const uint32_t HEl_15_rowPtr[] = {
   0,0,0,0,0
};
static const uint32_t HEl_15_colIdx[] = {
   0
};
static const double HEl_15_data[] = {
   0
};
static const uint32_t IEl_15_rowPtr[] = {
   0,1,1
};
static const uint32_t IEl_15_colIdx[] = {
   0
};
static const double IEl_15_data[] = {
   1
};
static const uint32_t KEl_15_rowPtr[] = {
   0,1,1
};
static const uint32_t KEl_15_colIdx[] = {
   0
};
static const double KEl_15_data[] = {
   1
};
static const uint32_t JEl_15_rowPtr[] = {
   0,0
};
static const uint32_t JEl_15_colIdx[] = {
   0
};
static const double JEl_15_data[] = {
   0
};
static const uint32_t * const AEl_rowPtr[] = {
   AEl_0_rowPtr,AEl_1_rowPtr,AEl_2_rowPtr,AEl_3_rowPtr,AEl_4_rowPtr,
   AEl_5_rowPtr,AEl_6_rowPtr,AEl_7_rowPtr,AEl_8_rowPtr,AEl_9_rowPtr,
   AEl_10_rowPtr,AEl_11_rowPtr,AEl_12_rowPtr,AEl_13_rowPtr,AEl_14_rowPtr,
   AEl_15_rowPtr
};
static const uint32_t * const AEl_colIdx[] = {
   AEl_0_colIdx,AEl_1_colIdx,AEl_2_colIdx,AEl_3_colIdx,AEl_4_colIdx,
   AEl_5_colIdx,AEl_6_colIdx,AEl_7_colIdx,AEl_8_colIdx,AEl_9_colIdx,
   AEl_10_colIdx,AEl_11_colIdx,AEl_12_colIdx,AEl_13_colIdx,AEl_14_colIdx,
   AEl_15_colIdx
};
static const double * const AEl_data[] = {
   AEl_0_data,AEl_1_data,AEl_2_data,AEl_3_data,AEl_4_data,AEl_5_data,
   AEl_6_data,AEl_7_data,AEl_8_data,AEl_9_data,AEl_10_data,AEl_11_data,
   AEl_12_data,AEl_13_data,AEl_14_data,AEl_15_data
};
static const uint32_t * const BEl_rowPtr[] = {
   BEl_0_rowPtr,BEl_1_rowPtr,BEl_2_rowPtr,BEl_3_rowPtr,BEl_4_rowPtr,
   BEl_5_rowPtr,BEl_6_rowPtr,BEl_7_rowPtr,BEl_8_rowPtr,BEl_9_rowPtr,
   BEl_10_rowPtr,BEl_11_rowPtr,BEl_12_rowPtr,BEl_13_rowPtr,BEl_14_rowPtr,
   BEl_15_rowPtr
};
static const uint32_t * const BEl_colIdx[] = {
   BEl_0_colIdx,BEl_1_colIdx,BEl_2_colIdx,BEl_3_colIdx,BEl_4_colIdx,
   BEl_5_colIdx,BEl_6_colIdx,BEl_7_colIdx,BEl_8_colIdx,BEl_9_colIdx,
   BEl_10_colIdx,BEl_11_colIdx,BEl_12_colIdx,BEl_13_colIdx,BEl_14_colIdx,
   BEl_15_colIdx
};
static const double * const BEl_data[] = {
   BEl_0_data,BEl_1_data,BEl_2_data,BEl_3_data,BEl_4_data,BEl_5_data,
   BEl_6_data,BEl_7_data,BEl_8_data,BEl_9_data,BEl_10_data,BEl_11_data,
   BEl_12_data,BEl_13_data,BEl_14_data,BEl_15_data
};
static const uint32_t * const CEl_rowPtr[] = {
   CEl_0_rowPtr,CEl_1_rowPtr,CEl_2_rowPtr,CEl_3_rowPtr,CEl_4_rowPtr,
   CEl_5_rowPtr,CEl_6_rowPtr,CEl_7_rowPtr,CEl_8_rowPtr,CEl_9_rowPtr,
   CEl_10_rowPtr,CEl_11_rowPtr,CEl_12_rowPtr,CEl_13_rowPtr,CEl_14_rowPtr,
   CEl_15_rowPtr
};
static const uint32_t * const CEl_colIdx[] = {
   CEl_0_colIdx,CEl_1_colIdx,CEl_2_colIdx,CEl_3_colIdx,CEl_4_colIdx,
   CEl_5_colIdx,CEl_6_colIdx,CEl_7_colIdx,CEl_8_colIdx,CEl_9_colIdx,
   CEl_10_colIdx,CEl_11_colIdx,CEl_12_colIdx,CEl_13_colIdx,CEl_14_colIdx,
   CEl_15_colIdx
};
static const double * const CEl_data[] = {
   CEl_0_data,CEl_1_data,CEl_2_data,CEl_3_data,CEl_4_data,CEl_5_data,
   CEl_6_data,CEl_7_data,CEl_8_data,CEl_9_data,CEl_10_data,CEl_11_data,
   CEl_12_data,CEl_13_data,CEl_14_data,CEl_15_data
};
static const uint32_t * const DEl_rowPtr[] = {
   DEl_0_rowPtr,DEl_1_rowPtr,DEl_2_rowPtr,DEl_3_rowPtr,DEl_4_rowPtr,
   DEl_5_rowPtr,DEl_6_rowPtr,DEl_7_rowPtr,DEl_8_rowPtr,DEl_9_rowPtr,
   DEl_10_rowPtr,DEl_11_rowPtr,DEl_12_rowPtr,DEl_13_rowPtr,DEl_14_rowPtr,
   DEl_15_rowPtr
};
static const uint32_t * const DEl_colIdx[] = {
   DEl_0_colIdx,DEl_1_colIdx,DEl_2_colIdx,DEl_3_colIdx,DEl_4_colIdx,
   DEl_5_colIdx,DEl_6_colIdx,DEl_7_colIdx,DEl_8_colIdx,DEl_9_colIdx,
   DEl_10_colIdx,DEl_11_colIdx,DEl_12_colIdx,DEl_13_colIdx,DEl_14_colIdx,
   DEl_15_colIdx
};
static const double * const DEl_data[] = {
   DEl_0_data,DEl_1_data,DEl_2_data,DEl_3_data,DEl_4_data,DEl_5_data,
   DEl_6_data,DEl_7_data,DEl_8_data,DEl_9_data,DEl_10_data,DEl_11_data,
   DEl_12_data,DEl_13_data,DEl_14_data,DEl_15_data
};
static const uint32_t * const EEl_rowPtr[] = {
   EEl_0_rowPtr,EEl_1_rowPtr,EEl_2_rowPtr,EEl_3_rowPtr,EEl_4_rowPtr,
   EEl_5_rowPtr,EEl_6_rowPtr,EEl_7_rowPtr,EEl_8_rowPtr,EEl_9_rowPtr,
   EEl_10_rowPtr,EEl_11_rowPtr,EEl_12_rowPtr,EEl_13_rowPtr,EEl_14_rowPtr,
   EEl_15_rowPtr
};
static const uint32_t * const EEl_colIdx[] = {
   EEl_0_colIdx,EEl_1_colIdx,EEl_2_colIdx,EEl_3_colIdx,EEl_4_colIdx,
   EEl_5_colIdx,EEl_6_colIdx,EEl_7_colIdx,EEl_8_colIdx,EEl_9_colIdx,
   EEl_10_colIdx,EEl_11_colIdx,EEl_12_colIdx,EEl_13_colIdx,EEl_14_colIdx,
   EEl_15_colIdx
};
static const double * const EEl_data[] = {
   EEl_0_data,EEl_1_data,EEl_2_data,EEl_3_data,EEl_4_data,EEl_5_data,
   EEl_6_data,EEl_7_data,EEl_8_data,EEl_9_data,EEl_10_data,EEl_11_data,
   EEl_12_data,EEl_13_data,EEl_14_data,EEl_15_data
};
static const uint32_t * const FEl_rowPtr[] = {
   FEl_0_rowPtr,FEl_1_rowPtr,FEl_2_rowPtr,FEl_3_rowPtr,FEl_4_rowPtr,
   FEl_5_rowPtr,FEl_6_rowPtr,FEl_7_rowPtr,FEl_8_rowPtr,FEl_9_rowPtr,
   FEl_10_rowPtr,FEl_11_rowPtr,FEl_12_rowPtr,FEl_13_rowPtr,FEl_14_rowPtr,
   FEl_15_rowPtr
};
static const uint32_t * const FEl_colIdx[] = {
   FEl_0_colIdx,FEl_1_colIdx,FEl_2_colIdx,FEl_3_colIdx,FEl_4_colIdx,
   FEl_5_colIdx,FEl_6_colIdx,FEl_7_colIdx,FEl_8_colIdx,FEl_9_colIdx,
   FEl_10_colIdx,FEl_11_colIdx,FEl_12_colIdx,FEl_13_colIdx,FEl_14_colIdx,
   FEl_15_colIdx
};
static const double * const FEl_data[] = {
   FEl_0_data,FEl_1_data,FEl_2_data,FEl_3_data,FEl_4_data,FEl_5_data,
   FEl_6_data,FEl_7_data,FEl_8_data,FEl_9_data,FEl_10_data,FEl_11_data,
   FEl_12_data,FEl_13_data,FEl_14_data,FEl_15_data
};
static const uint32_t * const GEl_rowPtr[] = {
   GEl_0_rowPtr,GEl_1_rowPtr,GEl_2_rowPtr,GEl_3_rowPtr,GEl_4_rowPtr,
   GEl_5_rowPtr,GEl_6_rowPtr,GEl_7_rowPtr,GEl_8_rowPtr,GEl_9_rowPtr,
   GEl_10_rowPtr,GEl_11_rowPtr,GEl_12_rowPtr,GEl_13_rowPtr,GEl_14_rowPtr,
   GEl_15_rowPtr
};
static const uint32_t * const GEl_colIdx[] = {
   GEl_0_colIdx,GEl_1_colIdx,GEl_2_colIdx,GEl_3_colIdx,GEl_4_colIdx,
   GEl_5_colIdx,GEl_6_colIdx,GEl_7_colIdx,GEl_8_colIdx,GEl_9_colIdx,
   GEl_10_colIdx,GEl_11_colIdx,GEl_12_colIdx,GEl_13_colIdx,GEl_14_colIdx,
   GEl_15_colIdx
};
static const double * const GEl_data[] = {
   GEl_0_data,GEl_1_data,GEl_2_data,GEl_3_data,GEl_4_data,GEl_5_data,
   GEl_6_data,GEl_7_data,GEl_8_data,GEl_9_data,GEl_10_data,GEl_11_data,
   GEl_12_data,GEl_13_data,GEl_14_data,GEl_15_data
};
static const uint32_t * const HEl_rowPtr[] = {
   HEl_0_rowPtr,HEl_1_rowPtr,HEl_2_rowPtr,HEl_3_rowPtr,HEl_4_rowPtr,
   HEl_5_rowPtr,HEl_6_rowPtr,HEl_7_rowPtr,HEl_8_rowPtr,HEl_9_rowPtr,
   HEl_10_rowPtr,HEl_11_rowPtr,HEl_12_rowPtr,HEl_13_rowPtr,HEl_14_rowPtr,
   HEl_15_rowPtr
};
static const uint32_t * const HEl_colIdx[] = {
   HEl_0_colIdx,HEl_1_colIdx,HEl_2_colIdx,HEl_3_colIdx,HEl_4_colIdx,
   HEl_5_colIdx,HEl_6_colIdx,HEl_7_colIdx,HEl_8_colIdx,HEl_9_colIdx,
   HEl_10_colIdx,HEl_11_colIdx,HEl_12_colIdx,HEl_13_colIdx,HEl_14_colIdx,
   HEl_15_colIdx
};
static const double * const HEl_data[] = {
   HEl_0_data,HEl_1_data,HEl_2_data,HEl_3_data,HEl_4_data,HEl_5_data,
   HEl_6_data,HEl_7_data,HEl_8_data,HEl_9_data,HEl_10_data,HEl_11_data,
   HEl_12_data,HEl_13_data,HEl_14_data,HEl_15_data
};
static const uint32_t * const IEl_rowPtr[] = {
   IEl_0_rowPtr,IEl_1_rowPtr,IEl_2_rowPtr,IEl_3_rowPtr,IEl_4_rowPtr,
   IEl_5_rowPtr,IEl_6_rowPtr,IEl_7_rowPtr,IEl_8_rowPtr,IEl_9_rowPtr,
   IEl_10_rowPtr,IEl_11_rowPtr,IEl_12_rowPtr,IEl_13_rowPtr,IEl_14_rowPtr,
   IEl_15_rowPtr
};
static const uint32_t * const IEl_colIdx[] = {
   IEl_0_colIdx,IEl_1_colIdx,IEl_2_colIdx,IEl_3_colIdx,IEl_4_colIdx,
   IEl_5_colIdx,IEl_6_colIdx,IEl_7_colIdx,IEl_8_colIdx,IEl_9_colIdx,
   IEl_10_colIdx,IEl_11_colIdx,IEl_12_colIdx,IEl_13_colIdx,IEl_14_colIdx,
   IEl_15_colIdx
};
static const double * const IEl_data[] = {
   IEl_0_data,IEl_1_data,IEl_2_data,IEl_3_data,IEl_4_data,IEl_5_data,
   IEl_6_data,IEl_7_data,IEl_8_data,IEl_9_data,IEl_10_data,IEl_11_data,
   IEl_12_data,IEl_13_data,IEl_14_data,IEl_15_data
};
static const uint32_t * const KEl_rowPtr[] = {
   KEl_0_rowPtr,KEl_1_rowPtr,KEl_2_rowPtr,KEl_3_rowPtr,KEl_4_rowPtr,
   KEl_5_rowPtr,KEl_6_rowPtr,KEl_7_rowPtr,KEl_8_rowPtr,KEl_9_rowPtr,
   KEl_10_rowPtr,KEl_11_rowPtr,KEl_12_rowPtr,KEl_13_rowPtr,KEl_14_rowPtr,
   KEl_15_rowPtr
};
static const uint32_t * const KEl_colIdx[] = {
   KEl_0_colIdx,KEl_1_colIdx,KEl_2_colIdx,KEl_3_colIdx,KEl_4_colIdx,
   KEl_5_colIdx,KEl_6_colIdx,KEl_7_colIdx,KEl_8_colIdx,KEl_9_colIdx,
   KEl_10_colIdx,KEl_11_colIdx,KEl_12_colIdx,KEl_13_colIdx,KEl_14_colIdx,
   KEl_15_colIdx
};
static const double * const KEl_data[] = {
   KEl_0_data,KEl_1_data,KEl_2_data,KEl_3_data,KEl_4_data,KEl_5_data,
   KEl_6_data,KEl_7_data,KEl_8_data,KEl_9_data,KEl_10_data,KEl_11_data,
   KEl_12_data,KEl_13_data,KEl_14_data,KEl_15_data
};
static const uint32_t * const JEl_rowPtr[] = {
   JEl_0_rowPtr,JEl_1_rowPtr,JEl_2_rowPtr,JEl_3_rowPtr,JEl_4_rowPtr,
   JEl_5_rowPtr,JEl_6_rowPtr,JEl_7_rowPtr,JEl_8_rowPtr,JEl_9_rowPtr,
   JEl_10_rowPtr,JEl_11_rowPtr,JEl_12_rowPtr,JEl_13_rowPtr,JEl_14_rowPtr,
   JEl_15_rowPtr
};
static const uint32_t * const JEl_colIdx[] = {
   JEl_0_colIdx,JEl_1_colIdx,JEl_2_colIdx,JEl_3_colIdx,JEl_4_colIdx,
   JEl_5_colIdx,JEl_6_colIdx,JEl_7_colIdx,JEl_8_colIdx,JEl_9_colIdx,
   JEl_10_colIdx,JEl_11_colIdx,JEl_12_colIdx,JEl_13_colIdx,JEl_14_colIdx,
   JEl_15_colIdx
};
static const double * const JEl_data[] = {
   JEl_0_data,JEl_1_data,JEl_2_data,JEl_3_data,JEl_4_data,JEl_5_data,
   JEl_6_data,JEl_7_data,JEl_8_data,JEl_9_data,JEl_10_data,JEl_11_data,
   JEl_12_data,JEl_13_data,JEl_14_data,JEl_15_data
};
static uint32_t diode_4_topologiesEl[16]={
   0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
};
static void diode_4_initEl()
{
   uint32_t i;
   for (i = 0; i < 2; ++i)
   {
      diode_4_tmpXEl[i] = 0;
      {
         const uint32_t *rowPtr = IEl_rowPtr[diode_4_topoIdxEl];
         const uint32_t *colIdx = IEl_colIdx[diode_4_topoIdxEl];
         const double *data = IEl_data[diode_4_topoIdxEl];
         uint32_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(diode_4_tmpXEl+i) += data[j]*diode_4_xEl[colIdx[j]];
      }
   }
}
static void diode_4_collisionEl()
{
   double tol;
   uint32_t i;
   double xCollision[2];
   char isInconsistent[2];
   memset(isInconsistent, 0, 2);
   for (i = 0; i < 2; ++i)
   {
      const uint32_t *rowPtr;
      const uint32_t *colIdx;
      const double *data;
      uint32_t j;
      xCollision[i] = 0;
      rowPtr = KEl_rowPtr[diode_4_topoIdxEl];
      colIdx = KEl_colIdx[diode_4_topoIdxEl];
      data = KEl_data[diode_4_topoIdxEl];
      for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
         *(xCollision+i) += data[j]*diode_4_tmpXEl[colIdx[j]];
      diode_4_xEl[i] = 0;
      if (isInconsistent[i])
      {
         continue;
      }
      rowPtr = IEl_rowPtr[diode_4_topoIdxEl];
      colIdx = IEl_colIdx[diode_4_topoIdxEl];
      data = IEl_data[diode_4_topoIdxEl];
      for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
         *(diode_4_xEl+i) += data[j]*diode_4_tmpXEl[colIdx[j]];
      tol = 1e-3*fabs(diode_4_tmpXEl[i]);
      if (tol < 1e-6)
      {
         tol = 1e-6;
      }
      if (fabs(diode_4_xEl[i]-diode_4_tmpXEl[i]) <= tol)
      {
         continue;
      }
      else if ((xCollision[i] >= diode_4_prevXEl[i] && xCollision[i] <=
                diode_4_tmpXEl[i]) ||
               (xCollision[i] >= diode_4_tmpXEl[i] && xCollision[i] <=
                diode_4_prevXEl[i]))
      {
         isInconsistent[i] = -1;
         rowPtr = KEl_rowPtr[diode_4_topoIdxEl];
         colIdx = KEl_colIdx[diode_4_topoIdxEl];
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            isInconsistent[colIdx[j]] = -1;
      }
      else
      {
         isInconsistent[i] = 1;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            isInconsistent[colIdx[j]] = 1;
      }
   }
   for (i = 0; i < 2; ++i)
   {
      if (!isInconsistent[i])
      {
         diode_4_tmpXEl[i] = diode_4_xEl[i];
      }
      else
      {
         diode_4_xEl[i] = xCollision[i];
         if (isInconsistent[i] < 0)
         {
            diode_4_tmpXEl[i] = xCollision[i];
         }
      }
   }
}
static void diode_4_updateEl()
{
   uint32_t i;
   for (i = 0; i < 2; ++i)
   {
      diode_4_xEl[i] = 0;
      {
         const uint32_t *rowPtr = AEl_rowPtr[diode_4_topoIdxEl];
         const uint32_t *colIdx = AEl_colIdx[diode_4_topoIdxEl];
         const double *data = AEl_data[diode_4_topoIdxEl];
         uint32_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(diode_4_xEl+i) += data[j]*diode_4_prevXEl[colIdx[j]];
      }
      {
         const uint32_t *rowPtr = BEl_rowPtr[diode_4_topoIdxEl];
         const uint32_t *colIdx = BEl_colIdx[diode_4_topoIdxEl];
         const double *data = BEl_data[diode_4_topoIdxEl];
         uint32_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(diode_4_xEl+
              i) += data[j]*
                    (diode_4_uEl[colIdx[j]] + diode_4_prevUEl[colIdx[j]]);
      }
   }
}
static void diode_4_outputEl(uint32_t n, const uint32_t *idx)
{
   uint32_t i;
   for (i = 0; i < n; ++i)
   {
      uint32_t r = idx[i];
      diode_4_yEl[r] = 0;
      {
         const uint32_t *rowPtr = CEl_rowPtr[diode_4_topoIdxEl];
         const uint32_t *colIdx = CEl_colIdx[diode_4_topoIdxEl];
         const double *data = CEl_data[diode_4_topoIdxEl];
         uint32_t j;
         for (j = rowPtr[r]; j < rowPtr[r+1]; ++j)
            *(diode_4_yEl+r) += data[j]*diode_4_xEl[colIdx[j]];
      }
      {
         const uint32_t *rowPtr = DEl_rowPtr[diode_4_topoIdxEl];
         const uint32_t *colIdx = DEl_colIdx[diode_4_topoIdxEl];
         const double *data = DEl_data[diode_4_topoIdxEl];
         uint32_t j;
         for (j = rowPtr[r]; j < rowPtr[r+1]; ++j)
            *(diode_4_yEl+r) += data[j]*diode_4_uEl[colIdx[j]];
      }
   }
}
static void diode_4_switchOutputEl()
{
   uint32_t r;
   for (r = 0; r < 4; ++r)
   {
      diode_4_sEl[r] = 0;
      diode_4_sEl[r+4] = 0;
      diode_4_sTolEl[r] = 0;
      diode_4_sTolEl[r+4] = 0;
      if (!diode_4_withDiracs)
      {
         {
            const uint32_t *rowPtr = EEl_rowPtr[diode_4_topoIdxEl];
            const uint32_t *colIdx = EEl_colIdx[diode_4_topoIdxEl];
            const double *data = EEl_data[diode_4_topoIdxEl];
            uint32_t j;
            for (j = rowPtr[r]; j < rowPtr[r+1]; ++j)
               *(diode_4_sEl+r) += data[j]*diode_4_xEl[colIdx[j]];
         }
         {
            const uint32_t *rowPtr = FEl_rowPtr[diode_4_topoIdxEl];
            const uint32_t *colIdx = FEl_colIdx[diode_4_topoIdxEl];
            const double *data = FEl_data[diode_4_topoIdxEl];
            uint32_t j;
            for (j = rowPtr[r]; j < rowPtr[r+1]; ++j)
               *(diode_4_sEl+r) += data[j]*diode_4_uEl[colIdx[j]];
         }
      }
      else
      {
         {
            double maxAbsVal = 0;
            const uint32_t *rowPtr = EEl_rowPtr[diode_4_topoIdxEl];
            const uint32_t *colIdx = EEl_colIdx[diode_4_topoIdxEl];
            const double *data = EEl_data[diode_4_topoIdxEl];
            uint32_t j;
            for (j = rowPtr[r]; j < rowPtr[r+1]; ++j)
            {
               double absVal = fabs(diode_4_xEl[colIdx[j]]);
               if (maxAbsVal < absVal)
               {
                  maxAbsVal = absVal;
               }
               *(diode_4_sEl+r) += data[j]*diode_4_xEl[colIdx[j]];
            }
            *(diode_4_sTolEl+
              r) += (rowPtr[r+1]-rowPtr[r])*maxAbsVal*2.8421709430404007e-14;
         }
         {
            double maxAbsVal = 0;
            const uint32_t *rowPtr = GEl_rowPtr[diode_4_topoIdxEl];
            const uint32_t *colIdx = GEl_colIdx[diode_4_topoIdxEl];
            const double *data = GEl_data[diode_4_topoIdxEl];
            uint32_t j;
            for (j = rowPtr[r]; j < rowPtr[r+1]; ++j)
            {
               double absVal = fabs(diode_4_xEl[colIdx[j]]);
               if (maxAbsVal < absVal)
               {
                  maxAbsVal = absVal;
               }
               absVal = fabs(-diode_4_tmpXEl[colIdx[j]]);
               if (maxAbsVal < absVal)
               {
                  maxAbsVal = absVal;
               }
               *(diode_4_sEl+4+
                 r) += data[j]*
                       (diode_4_xEl[colIdx[j]] + -diode_4_tmpXEl[colIdx[j]]);
            }
            *(diode_4_sTolEl+4+
              r) += (rowPtr[r+1]-rowPtr[r])*maxAbsVal*5.6843418860808015e-14;
         }
         {
            double maxAbsVal = 0;
            const uint32_t *rowPtr = FEl_rowPtr[diode_4_topoIdxEl];
            const uint32_t *colIdx = FEl_colIdx[diode_4_topoIdxEl];
            const double *data = FEl_data[diode_4_topoIdxEl];
            uint32_t j;
            for (j = rowPtr[r]; j < rowPtr[r+1]; ++j)
            {
               double absVal = fabs(diode_4_uEl[colIdx[j]]);
               if (maxAbsVal < absVal)
               {
                  maxAbsVal = absVal;
               }
               *(diode_4_sEl+r) += data[j]*diode_4_uEl[colIdx[j]];
            }
            *(diode_4_sTolEl+
              r) += (rowPtr[r+1]-rowPtr[r])*maxAbsVal*2.8421709430404007e-14;
         }
         {
            double maxAbsVal = 0;
            const uint32_t *rowPtr = HEl_rowPtr[diode_4_topoIdxEl];
            const uint32_t *colIdx = HEl_colIdx[diode_4_topoIdxEl];
            const double *data = HEl_data[diode_4_topoIdxEl];
            uint32_t j;
            for (j = rowPtr[r]; j < rowPtr[r+1]; ++j)
            {
               double absVal = fabs(diode_4_uEl[colIdx[j]]);
               if (maxAbsVal < absVal)
               {
                  maxAbsVal = absVal;
               }
               *(diode_4_sEl+4+r) += data[j]*diode_4_uEl[colIdx[j]];
            }
            *(diode_4_sTolEl+4+
              r) += (rowPtr[r+1]-rowPtr[r])*maxAbsVal*2.8421709430404007e-14;
         }
      }
   }
}
static void diode_4_depEl()
{
   uint32_t i;
   for (i = 0; i < 1; ++i)
   {
      diode_4_prevUEl[i] = 0;
      {
         const uint32_t *rowPtr = JEl_rowPtr[diode_4_topoIdxEl];
         const uint32_t *colIdx = JEl_colIdx[diode_4_topoIdxEl];
         const double *data = JEl_data[diode_4_topoIdxEl];
         uint32_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(diode_4_prevUEl+i) += data[j]*diode_4_uEl[colIdx[j]];
      }
   }
}
diode_4_ModelStates diode_4_X;
const char * diode_4_errorStatus;
const double diode_4_sampleTime = 0.00100000000000000002;
const char * const diode_4_checksum =
   "5ce4a0143639c26df1dcdc5284ccfe122484868b";
void diode_4_initialize(double time)
{
   diode_4_errorStatus = NULL;
   diode_4_D_uint32_t[0] =
      (((int32_t) floor(time/0.00100000000000000002+.5)) % 20 + 20) % 20;
   diode_4_X[0] = 0;
   diode_4_X[1] = 0;
   diode_4_X[2] = 0;
   diode_4_X[3] = 0;
   diode_4_X[4] = 0;
   diode_4_X[5] = 0;
   diode_4_topoIdxEl = 0;
   diode_4_xEl = &diode_4_X[0];
   memcpy(diode_4_prevXEl,diode_4_xEl,2*sizeof(double));
   diode_4_first = 1;
   diode_4_withDiracs = 0;
}

void diode_4_step()
{
   if (diode_4_errorStatus)
   {
      return;
   }

   /* Electrical model input */
   /* Voltage Source AC : 'diode_4/V_ac' */
   diode_4_uEl[0]=325 * sin(0.314159265358979312 * diode_4_D_uint32_t[0] + 0);
   /* End of electrical model input */


   /* Update electrical model states */
   if (!diode_4_first)
   {
      memcpy(diode_4_prevXEl,diode_4_xEl,2*sizeof(double));
      diode_4_updateEl();
   }
   diode_4_switchOutputEl();

   /* Electrical model switch loop */
   {
      uint32_t mask = diode_4_topologiesEl[diode_4_topoIdxEl];
      uint32_t nextIdx = diode_4_topoIdxEl;
      uint32_t prevIdx = diode_4_topoIdxEl;
      char first = 1;
      uint32_t iter;
      for (iter=0; iter < 1000; iter++)
      {
         uint32_t bottom = 0;
         uint32_t top = 15;
         if (diode_4_X[2])
         {
            if (((diode_4_sEl[4]) > diode_4_sTolEl[4] ||
                 (fabs(diode_4_sEl[4]) <= diode_4_sTolEl[4] &&
                  (diode_4_sEl[0]) >
                  0+diode_4_sTolEl[0])))
            {
               diode_4_X[2] = 0;
               mask &= ~1;
            }
         }
         else
         {
            if (((diode_4_sEl[4]) < -diode_4_sTolEl[4] ||
                 (fabs(diode_4_sEl[4]) <= diode_4_sTolEl[4] &&
                  (diode_4_sEl[0]) <
                  0-diode_4_sTolEl[0])))
            {
               diode_4_X[2] = 1;
               mask |= 1;
            }
         }
         if (diode_4_X[3])
         {
            if (((diode_4_sEl[5]) > diode_4_sTolEl[5] ||
                 (fabs(diode_4_sEl[5]) <= diode_4_sTolEl[5] &&
                  (diode_4_sEl[1]) >
                  0+diode_4_sTolEl[1])))
            {
               diode_4_X[3] = 0;
               mask &= ~2;
            }
         }
         else
         {
            if (((diode_4_sEl[5]) < -diode_4_sTolEl[5] ||
                 (fabs(diode_4_sEl[5]) <= diode_4_sTolEl[5] &&
                  (diode_4_sEl[1]) <
                  0-diode_4_sTolEl[1])))
            {
               diode_4_X[3] = 1;
               mask |= 2;
            }
         }
         if (diode_4_X[4])
         {
            if (((diode_4_sEl[6]) > diode_4_sTolEl[6] ||
                 (fabs(diode_4_sEl[6]) <= diode_4_sTolEl[6] &&
                  (diode_4_sEl[2]) >
                  0+diode_4_sTolEl[2])))
            {
               diode_4_X[4] = 0;
               mask &= ~4;
            }
         }
         else
         {
            if (((diode_4_sEl[6]) < -diode_4_sTolEl[6] ||
                 (fabs(diode_4_sEl[6]) <= diode_4_sTolEl[6] &&
                  (diode_4_sEl[2]) <
                  0-diode_4_sTolEl[2])))
            {
               diode_4_X[4] = 1;
               mask |= 4;
            }
         }
         if (diode_4_X[5])
         {
            if (((diode_4_sEl[7]) > diode_4_sTolEl[7] ||
                 (fabs(diode_4_sEl[7]) <= diode_4_sTolEl[7] &&
                  (diode_4_sEl[3]) >
                  0+diode_4_sTolEl[3])))
            {
               diode_4_X[5] = 0;
               mask &= ~8;
            }
         }
         else
         {
            if (((diode_4_sEl[7]) < -diode_4_sTolEl[7] ||
                 (fabs(diode_4_sEl[7]) <= diode_4_sTolEl[7] &&
                  (diode_4_sEl[3]) <
                  0-diode_4_sTolEl[3])))
            {
               diode_4_X[5] = 1;
               mask |= 8;
            }
         }
         for (;; )
         {
            if (diode_4_topologiesEl[nextIdx] > mask && nextIdx > bottom)
            {
               top = nextIdx-1;
            }
            else if (diode_4_topologiesEl[nextIdx] < mask && nextIdx < top)
            {
               bottom = nextIdx+1;
            }
            else
               break;
            nextIdx = bottom+(top-bottom)/2;
            if (top == bottom)
            {
               break;
            }
         }
         if (diode_4_topologiesEl[nextIdx] != mask)
         {
            static char msg[]="Unknown topology: [0 0 0 0]";
            uint32_t i;
            for (i = 0; i < 4; ++i)
               if (mask & (1<<i))
               {
                  msg[19+2*i]='1';
               }

            PLECSRunTimeError(msg);
            return;
         }
         if (nextIdx == diode_4_topoIdxEl)
         {
            break;
         }
         if (first)
         {
            first = 0;
            diode_4_initEl();
            memcpy(&diode_4_X[0], diode_4_tmpXEl, 2*sizeof(double));
         }
         diode_4_topoIdxEl = nextIdx;
         diode_4_collisionEl();
         diode_4_withDiracs = 1;
         diode_4_switchOutputEl();
         diode_4_withDiracs = 0;
      }
      if (iter >= 1000)
      {
         PLECSRunTimeError("Switch loop");
         return;
      }
      if (diode_4_topoIdxEl != prevIdx)
      {
         if (diode_4_tmpXEl[0] != diode_4_X[0])
         {
            PLECSRunTimeError(
                              "State discontinuity in diode_4/L1 after switching");
            return;
         }
         if (diode_4_tmpXEl[1] != diode_4_X[1])
         {
            PLECSRunTimeError(
                              "State discontinuity in diode_4/C1 after switching");
            return;
         }
      }
      diode_4_depEl();
      if (diode_4_prevUEl[0])
      {
         PLECSRunTimeError("Input dependency in diode_4/V_ac");
         return;
      }
   }
   /* End of electrical model switch loop */


   /* Electrical model output */

   {
      const uint32_t meterIdx[]={
         0,1
      };
      diode_4_outputEl(2,meterIdx);
   }
   /* End of electrical model output */
   diode_4_first = 0;
   if (diode_4_errorStatus)
   {
      return;
   }

   /* Update for Voltage Source AC : 'diode_4/V_ac' */
   diode_4_D_uint32_t[0] += 1;
   if (diode_4_D_uint32_t[0] > 19)
   {
      diode_4_D_uint32_t[0] = 0;
   }
   memcpy(diode_4_prevUEl, diode_4_uEl, 1*sizeof(double));
}

void diode_4_terminate()
{
}
