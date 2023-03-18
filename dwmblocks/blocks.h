/* Modify this file to change what commands output to your statusbar, and recompile using the make command. */
static const Block blocks[] = {

/* These commands are stored in ~/.local/bin/statusbar/ */
/*Icon*/	/*Command*/		    /*Interval*/	/*Signal*/
//{"",        "moonphase.sh",     0,            0},
//{"",        "weather.sh",       3600,         0},
{"",        "cputemp.sh",       5,            0},
{"",        "cpu.sh",           5,            0},
{"",        "memory.sh",        5,            0},
{"",        "disk.sh",          60,           0},
{"",        "nettraf.sh",       1,            0},
{"",        "internet.sh",      5,            0},
{"",        "volume.sh",        0,            5},
{"",        "brightness.sh",    0,            6},
{"",        "battery.sh",       5,            0},
{"",        "clock.sh",         60,           0},
//{"",        "pacupdates.sh",    60,           0},
//{"",        "uname -r",         0,            0},
};

/* sets delimeter between status commands. NULL character ('\0') means no delimeter. */
static char delim[] = "  ";
static unsigned int delimLen = 5; /* idk what this is so keep it at 5 */
