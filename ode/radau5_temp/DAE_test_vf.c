/*  Vector field function and events for Radau integrator.
  This code was automatically generated by PyDSTool, but may be modified by hand. */

#include <math.h>
#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "events.h"
#include "maxmin.h"
#include "signum.h"
#include "vfield.h"

extern double *gICs;
extern double **gBds;
extern double globalt0;

static double pi = 3.1415926535897931;

double signum(double x)
{
  if (x<0) {
    return -1;
  }
  else if (x==0) {
    return 0;
  }
  else if (x>0) {
    return 1;
  }
  else {
    /* must be that x is Not-a-Number */
    return x;
  }
}


/* Variable, aux variable, parameter, and input definitions: */ 
#define G	p_[0]
#define K_d	p_[1]
#define L	p_[2]
#define M	p_[3]
#define v_x	Y_[0]
#define v_y	Y_[1]
#define x	Y_[2]
#define x_g	Y_[3]
#define y	Y_[4]


double __maxof2(double e1_, double e2_, double *p_, double *wk_, double *xv_);
double __maxof3(double e1_, double e2_, double e3_, double *p_, double *wk_, double *xv_);
double __maxof4(double e1_, double e2_, double e3_, double e4_, double *p_, double *wk_, double *xv_);
double __minof2(double e1_, double e2_, double *p_, double *wk_, double *xv_);
double __minof3(double e1_, double e2_, double e3_, double *p_, double *wk_, double *xv_);
double __minof4(double e1_, double e2_, double e3_, double e4_, double *p_, double *wk_, double *xv_);
double __rhs_if(int cond_, double e1_, double e2_, double *p_, double *wk_, double *xv_);
double getbound(char *name, int which_bd, double *p_, double *wk_, double *xv_);
double globalindepvar(double t, double *p_, double *wk_, double *xv_);
double initcond(char *varname, double *p_, double *wk_, double *xv_);
int getindex(char *name, double *p_, double *wk_, double *xv_);
int heav(double x_, double *p_, double *wk_, double *xv_);
void massMatrix(unsigned n_, unsigned np_, double t, double *Y_, double *p_, double **f_, unsigned wkn_, double *wk_, unsigned xvn_, double *xv_);

int N_EVENTS = 0;
void assignEvents(EvFunType *events){
 
}

void auxvars(unsigned, unsigned, double, double*, double*, double*, unsigned, double*, unsigned, double*);
void jacobian(unsigned, unsigned, double, double*, double*, double**, unsigned, double*, unsigned, double*);
void jacobianParam(unsigned, unsigned, double, double*, double*, double**, unsigned, double*, unsigned, double*);
int N_AUXVARS = 0;


int N_EXTINPUTS = 0;


void vfieldfunc(unsigned n_, unsigned np_, double t, double *Y_, double *p_, double *f_, unsigned wkn_, double *wk_, unsigned xvn_, double *xv_){

f_[0] = 1.0/M*(-K_d*v_x);
f_[1] = 1.0/M*(-K_d*v_y+M*G);
f_[2] = v_x;
f_[3] = x*x+y*y-L*L;
f_[4] = v_y;

}




double __maxof2(double e1_, double e2_, double *p_, double *wk_, double *xv_) {
if (e1_ > e2_) {return e1_;} else {return e2_;};
}


double __maxof3(double e1_, double e2_, double e3_, double *p_, double *wk_, double *xv_) {
double temp_;
if (e1_ > e2_) {temp_ = e1_;} else {temp_ = e2_;};
if (e3_ > temp_) {return e3_;} else {return temp_;};
}


double __maxof4(double e1_, double e2_, double e3_, double e4_, double *p_, double *wk_, double *xv_) {
double temp_;
if (e1_ > e2_) {temp_ = e1_;} else {temp_ = e2_;};
if (e3_ > temp_) {temp_ = e3_;};
if (e4_ > temp_) {return e4_;} else {return temp_;};
}


double __minof2(double e1_, double e2_, double *p_, double *wk_, double *xv_) {
if (e1_ < e2_) {return e1_;} else {return e2_;};
}


double __minof3(double e1_, double e2_, double e3_, double *p_, double *wk_, double *xv_) {
double temp_;
if (e1_ < e2_) {temp_ = e1_;} else {temp_ = e2_;};
if (e3_ < temp_) {return e3_;} else {return temp_;};
}


double __minof4(double e1_, double e2_, double e3_, double e4_, double *p_, double *wk_, double *xv_) {
double temp_;
if (e1_ < e2_) {temp_ = e1_;} else {temp_ = e2_;};
if (e3_ < temp_) {temp_ = e3_;};
if (e4_ < temp_) {return e4_;} else {return temp_;};
}


double __rhs_if(int cond_, double e1_, double e2_, double *p_, double *wk_, double *xv_) {
  if (cond_) {return e1_;} else {return e2_;};
}


double getbound(char *name, int which_bd, double *p_, double *wk_, double *xv_) {
  return gBds[which_bd][getindex(name, p_, wk_, xv_)];
}


double globalindepvar(double t, double *p_, double *wk_, double *xv_) {
  return globalt0+t;
}


double initcond(char *varname, double *p_, double *wk_, double *xv_) {

  if (strcmp(varname, "v_x")==0)
	return gICs[0];
  else if (strcmp(varname, "v_y")==0)
	return gICs[1];
  else if (strcmp(varname, "x")==0)
	return gICs[2];
  else if (strcmp(varname, "x_g")==0)
	return gICs[3];
  else if (strcmp(varname, "y")==0)
	return gICs[4];
  else {
	fprintf(stderr, "Invalid variable name %s for initcond call\n", varname);
	return 0.0/0.0;
	}
}


int getindex(char *name, double *p_, double *wk_, double *xv_) {

  if (strcmp(name, "v_x")==0)
	return 0;
  else if (strcmp(name, "v_y")==0)
	return 1;
  else if (strcmp(name, "x")==0)
	return 2;
  else if (strcmp(name, "x_g")==0)
	return 3;
  else if (strcmp(name, "y")==0)
	return 4;
  else if (strcmp(name, "G")==0)
	return 5;
  else if (strcmp(name, "K_d")==0)
	return 6;
  else if (strcmp(name, "L")==0)
	return 7;
  else if (strcmp(name, "M")==0)
	return 8;
  else {
	fprintf(stderr, "Invalid name %s for getindex call\n", name);
	return 0.0/0.0;
	}
}


int heav(double x_, double *p_, double *wk_, double *xv_) {
  if (x_>0.0) {return 1;} else {return 0;}
}


void massMatrix(unsigned n_, unsigned np_, double t, double *Y_, double *p_, double **f_, unsigned wkn_, double *wk_, unsigned xvn_, double *xv_) {


f_[0][0] = 1;
f_[0][1] = 0;
f_[0][2] = 0;
f_[0][3] = 0;
f_[0][4] = 0;
f_[1][0] = 0;
f_[1][1] = 1;
f_[1][2] = 0;
f_[1][3] = 0;
f_[1][4] = 0;
f_[2][0] = 0;
f_[2][1] = 0;
f_[2][2] = 1;
f_[2][3] = 0;
f_[2][4] = 0;
f_[3][0] = 0;
f_[3][1] = 0;
f_[3][2] = 0;
f_[3][3] = 1;
f_[3][4] = 0;
f_[4][0] = 0;
f_[4][1] = 0;
f_[4][2] = 0;
f_[4][3] = 0;
f_[4][4] = 0;

 ;

}

void auxvars(unsigned n_, unsigned np_, double t, double *Y_, double *p_, double *f_, unsigned wkn_, double *wk_, unsigned xvn_, double *xv_){


}


void jacobian(unsigned n_, unsigned np_, double t, double *Y_, double *p_, double **f_, unsigned wkn_, double *wk_, unsigned xvn_, double *xv_) {
}

void jacobianParam(unsigned n_, unsigned np_, double t, double *Y_, double *p_, double **f_, unsigned wkn_, double *wk_, unsigned xvn_, double *xv_) {
}
