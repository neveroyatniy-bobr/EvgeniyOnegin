#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <stdlib.h>

struct Settings {
    const char* input_file_name;
    const char* output_file_name;
    bool is_speedtest;
    bool is_generate_text;
    size_t generate_text_size;
};

void SettingsInit(Settings* settings);

int SettingsFromCmdOpt(Settings* settings, int argc, char** argv);

#endif // SETTINGS_H_