#include <stdlib.h>
#include <argp.h>
#include <string.h>
#include <stdbool.h>

#include "args.h"
#include "cstock.h"

int process_args(int argc, char *argv[])
{
  // No argument flag.
  bool flag_l = false;
  bool flag_C = false;
  bool flag_E = false;
  bool flag_A = false;
  bool flag_R = false;

  // Flags that require agument.
  bool flag_s = false;
  char *flag_s_value = NULL;
    
  bool flag_n = false;
  char *flag_n_value = NULL;

  bool flag_c = false;
  item_code flag_c_value = 0; 

  bool flag_q = false;
  int flag_q_value = 0;

  char opt = 0;
  while((opt = getopt(argc, argv, "lCEARs:n:c:q:")) != -1)
  {
    switch(opt)
    {
      // Flags without arguments.
      case 'l':
        printf("option -l.\n");
        flag_l = true;
        break;

      case 'C':
        printf("option -C.\n");
        flag_C = true;
        break;

      case 'E':
        printf("option -E.\n");
        flag_E = true;
        break;

      case 'A':
        printf("option -A.\n");
        flag_A = true;
        break;

      case 'R':
        printf("option -R.\n");
        flag_R = true;
        break;

      // Flags with flags.
      case 's':
        printf("option -s.\n");
        flag_s = true;
        flag_s_value = optarg;
        break;

      case 'n':
        printf("option -n.\n");
        flag_n = true;
        flag_n_value = optarg;
        break;

      case 'c':
        printf("option -c.\n");
        flag_c = true;
        flag_c_value = (item_code) atoi(optarg);
        break;

      case 'q':
        printf("option -q.\n");
        flag_q = true;
        flag_q_value = (item_code) atoi(optarg);
        break;

      case '?':
        if(optopt == 'n')
        {
          fprintf(stderr, "Option -n requires an argument. [NAME]\n");
          return argument_required;
        }
        else if(optopt == 's')
        {
          fprintf(stderr, "Option -s requires an argument. [NAME]\n");
          return argument_required;
        }
        else if(optopt == 'c')
        {
          fprintf(stderr, "Option -c requires an argument. [CODE]\n");
          return argument_required;
        }
        else if(optopt == 'q')
        {
          fprintf(stderr, "Option -q requiers an argument. [AMOUNT]\n");
          return argument_required;
        }
        else
        {
          //fprintf(stderr, "Unknown option -%c.\n", optopt);
          return invalid_argument;
        }
    }
  }


  // Making sure that the user just passed only one flag on command line.
  if ((flag_C + flag_E + flag_A + flag_R) > 1)
  {
    fprintf(stderr, "[%d] You can make only one operation.\n", (flag_C + flag_E + flag_A + flag_R));
    return fatal;
  }

  // Making the calls for the options.
  if(flag_l)
  {
    return list_all();
  }

  if(flag_s)
  {
    return search_by_name(flag_s_value);
  }

  if(flag_c)
  {
    if((!flag_C) && (!flag_E) && (!flag_A) && (!flag_R))
      return search_by_code(flag_c_value);
  }

  if(flag_C)
  {
    if(flag_n && flag_q)
    {
      return register_item(flag_q_value, flag_n_value);
    }
    else
    {
      fprintf(stderr, "Something where wrong with command lines processing.\n");
      return fatal;
    }
  }

  if (flag_E)
  {
    if(flag_n)
      return delete_item_by_name(flag_n_value);
    else if (flag_c)
      return delete_item_by_code(flag_c_value);
    else
    {
      fprintf(stderr, "Something where wrong with command lines processing.\n");
      return fatal;
    }
  }

  if(flag_A)
  {
    if(flag_n && flag_q)
      return add_item_by_name(flag_q_value, flag_n_value);
    else if(flag_c && flag_q)
      return add_item_by_code(flag_q_value, flag_c_value);
    else
    {
      fprintf(stderr, "Something where wrong with command lines processing.\n");
      return fatal;
    }
  }

  if(flag_R)
  {
    if(flag_n && flag_q)
      return withdrawal_item_by_name(flag_q_value, flag_n_value);
    else if(flag_c && flag_q)
      return withdrawal_item_by_code(flag_q_value, flag_c_value);
    else
    {
      fprintf(stderr, "Something where wrong with command lines processing.\n");
      return fatal;
    }
  }
}

