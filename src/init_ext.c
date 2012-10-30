/*
** init_ext.c - initialize extend libraries
**
** See Copyright Notice in mruby.h
*/

#include "mruby.h"

void
mrb_init_ext(mrb_state *mrb)
{
#ifdef INCLUDE_SOCKET
  extern void mrb_init_socket(mrb_state *mrb);
  mrb_init_socket(mrb);
#endif

  extern void mrb_init_led(mrb_state *mrb);
  mrb_init_led(mrb);
  extern void mrb_init_sleep(mrb_state *mrb);
  mrb_init_sleep(mrb);
}
