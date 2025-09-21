#ifndef SETTINGS_H_
#define SETTINGS_H_

struct Settings {
    const char* input_file_name;
    const char* output_file_name;
};

void SettingsInit(Settings* settings);

int SettingsFromCmdOpt(Settings* settings, int argc, char** argv);

#endif // SETTINGS_H_