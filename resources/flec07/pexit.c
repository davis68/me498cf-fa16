/**************************************************************/
/*                                                            */
/* User-Defined Function for Transient Flow in a Channel      */
/*                                                            */
/* Fluent 6                                                   */
/*                                                            */
/* Author: Frank Kelecy                                       */
/*   Date: January 2001                                       */
/*                                                            */
/* This function prescribes an oscillating static pressure    */
/* at the channel exit.                                       */
/*                                                            */
/**************************************************************/

#include "udf.h"

DEFINE_PROFILE(transient_pressure, thread, position)
{

  float t, pressure;
  face_t f;

  t = RP_Get_Real("flow-time");

  pressure = (0.12*sin(2200*t)+0.737)*101325.0;

  begin_f_loop(f, thread)
  {
   F_PROFILE(f, thread, position) = pressure;
  }
  end_f_loop(f, thread)

}
