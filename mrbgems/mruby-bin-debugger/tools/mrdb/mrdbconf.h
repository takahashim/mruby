/*
** mrdbconf.h - mruby debugger configuration
**
*/

#ifndef MRDBCONF_H
#define MRDBCONF_H

#ifndef MRB_ENABLE_DEBUG_HOOK
# error Need 'MRB_ENABLE_DEBUG_HOOK' configuration in your 'build_config.rb'
#endif

/* configuration options: */
/* maximum size for command buffer */
#define MAX_COMMAND_LINE 1024

/* maximum number of setable breakpoint */
#define MAX_BREAKPOINT 5

#endif
