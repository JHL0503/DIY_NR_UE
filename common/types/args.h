#ifndef ARGS_H
#define ARGS_H

typedef struct {
    int nof_channels;
    float base_srate;
} rf_dev_args_t;

typedef struct {
    rf_dev_args_t rf_dev_args;
} rf_args_t;

typedef struct {
    rf_args_t rf_args;
} all_args_t;
  

#endif