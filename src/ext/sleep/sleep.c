#include "mruby.h"
#include "kernel.h"

extern ER dly_tsk(RELTIM dlytim);


static mrb_value
sleep_sleep(mrb_state *mrb, mrb_value obj)
{
  int n;
  mrb_get_args(mrb, "i", &n);
  dly_tsk(n);
  return mrb_true_value();
}

void
mrb_init_sleep(mrb_state *mrb)
{
  struct RClass *mrb_sleep;
  mrb_sleep = mrb_define_module(mrb, "Sleep");
  mrb_define_module_function(mrb, mrb_sleep, "sleep", sleep_sleep, ARGS_REQ(1));
}

