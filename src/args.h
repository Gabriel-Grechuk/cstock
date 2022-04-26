#ifndef _ARGS_H_
#define _ARGS_H_


enum error_codes
{
  ok = 0,
  invalid_argument = 1,
  argument_required = 2,
  fatal = -1
};


int process_args(int argc, char *argv[]);

#endif // _ARGS_H_

