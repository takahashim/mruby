#include "mruby.h"
#include "fm3_mb9bxxx.h"

static mrb_value
led_led(mrb_state *mrb, mrb_value obj)
{
  int n;
  mrb_get_args(mrb, "i", &n);
  if (n==0) {
    *(volatile uint32_t *)FM3_GPIO_PDORF &= ~(1<<3);
  } else if (n == 1) {
    *(volatile uint32_t *)FM3_GPIO_PDORF |= (1<<3);
  }

  return mrb_fixnum_value(n);
}



void
mrb_init_led(mrb_state *mrb)
{
  struct RClass *mrb_led;

  mrb_led = mrb_define_module(mrb, "LED");
  mrb_define_const(mrb, mrb_led, "ON", mrb_fixnum_value(1));
  mrb_define_const(mrb, mrb_led, "OFF", mrb_fixnum_value(0));
  /* LED.led(0) #=> LED OFF */
  /* LED.led(1) #=> LED ON */
  mrb_define_module_function(mrb, mrb_led, "led", led_led, ARGS_REQ(1));
}

