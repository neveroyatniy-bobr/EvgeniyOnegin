#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <getopt.h>
#include <stdlib.h>

/// @brief Хоанит имена опций
static const option long_options[] = {
    { .name = "file", .has_arg = required_argument, .flag = NULL, 'f' },
    { .name = "speedtest", .has_arg = no_argument, .flag = NULL, 's' },
    { .name = "generatetext", .has_arg = required_argument, .flag = NULL, 'g' },
    { .name = "help", .has_arg = no_argument, .flag = NULL, 'h' }
};

#endif // OPTIONS_H_