/* configuration file for iverson's build of dwm */

/* installed programs:
 * dmenu, st,
 * firefox, ranger
 * ttf-hack-nerd, ttf-joypixels (emojis)
 */

/* appearance */
static const unsigned int borderpx  = 1;    /* border pixel of windows */
static const unsigned int snap      = 16;   /* snap pixel */
static const unsigned int gappih    = 0;    /* horiz inner gap between windows */
static const unsigned int gappiv    = 0;    /* vert inner gap between windows */
static const unsigned int gappoh    = 0;    /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 0;    /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;    /* 1 means no outer gap when there is only one window */
static const int swallowfloating    = 1;    /* 1 means swallow floating windows */
static const int showbar            = 1;    /* 0 means no bar */
static const int topbar             = 0;    /* 0 means bottom bar */
static unsigned int baralpha        = 255;  /* choose values from 0 - 255 */
static unsigned int borderalpha     = 255;  /* 255 is opaque */

/* fonts */
static const char *fonts[]          = { "Hack Nerd Font:size=10:antialias=true:autohint=true",
                                        "JoyPixels:size=8:antialias=true:autohint=true" };
static const char dmenufont[]       =   "Hack Nerd Font:size=10:antialias=true:autohint=true";

/* colors */
#include "/home/iverson/.local/src/dwm/themes/default.h" /* importing theme */
static const char *colors[][3] =
{   /*               fg     bg     border */
    [SchemeNorm] = { col_3, col_1, col_2 },
    [SchemeSel]  = { col_4, col_a, col_b },
};

/* scratchpads */
typedef struct {
    const char *name;
    const void *cmd;
} Sp;
const char *spcmd1[] = { "st", "-n", "spterm", "-g", "120x40", NULL };
const char *spcmd2[] = { "st", "-n", "spfm", "-g", "120x40", "-e", "ranger", NULL };
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm",       spcmd1},
    {"spfm",       spcmd2},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Rule rules[] = {
   /* xprop(1):
    * WM_CLASS(STRING) = instance, class
    * WM_NAME(STRING) = title
    */
/*                                                                (swallow)                      */
/* class         instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
{ "st-256color", NULL,     NULL,           0,         0,          1,           0,        -1 },
{ "st-256color", "spterm", NULL,           SPTAG(0),  1,          1,           0,        -1 }, /* scratchpad 1 */
{ "st-256color", "spfm",   NULL,           SPTAG(1),  1,          1,           0,        -1 }, /* scratchpad 2 */
{ "Pcmanfm",     NULL,     NULL,           0,         0,          1,           0,        -1 },
{ NULL,          NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
#include "gridmode.c"
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* master window on left, slave stacks on right */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle }, /* windows stacked in front of each other */
    { "HHH",      grid },    /* all windows laid out in a grid */
};

/* key definitions for tags */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont,
                                  "-nb", col_1, "-nf", col_3,
                                  "-sb", col_4, "-sf", col_a, NULL };
static const char *termcmd[]     = { "st", NULL };
static const char *browser[]     = { "firefox", NULL };
static const char *filemanager[] = { "pcmanfm", NULL };

/* keyboard bindings */
static const Key keys[] = {
    /* modifier                     key        function        argument */
    
    /* open apps */
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_i,      spawn,          {.v = browser } },
    { MODKEY,                       XK_f,      spawn,          {.v = filemanager } },
    
    /* window management */
    { MODKEY,                       XK_q,      killclient,     {0} }, /* quit window */
    { MODKEY,                       XK_m,      zoom,           {0} }, /* move focused window to master */
    { MODKEY,                       XK_Tab,    view,           {0} }, /* goes to most recently viewed tag */

    /* bar */
    { MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },

    /* stack */
    { MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } }, /* rotate windows in the stack */
    { MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } }, /* change focus in the stack */
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.02} }, /* change master stack size */
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.02} },

    /* gaps */
    { MODKEY|ControlMask,           XK_j,      incrgaps,       {.i = +1 } }, /* change gap size */
    { MODKEY|ControlMask,           XK_k,      incrgaps,       {.i = -1 } },
    { MODKEY|ControlMask,           XK_g,      togglegaps,     {0} },
    { MODKEY|ControlMask|ShiftMask, XK_g,      defaultgaps,    {0} }, /* resets gaps to default settings */

    /* layouts */
    { MODKEY|ShiftMask,             XK_z,      setlayout,      {.v = &layouts[0]} }, /* tile */
    { MODKEY|ShiftMask,             XK_x,      setlayout,      {.v = &layouts[1]} }, /* floating */
    { MODKEY|ShiftMask,             XK_c,      setlayout,      {.v = &layouts[2]} }, /* monacle */
    { MODKEY|ShiftMask,             XK_v,      setlayout,      {.v = &layouts[3]} }, /* grid */
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} }, /* floating behavior for focused window */

    /* monitors */
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    
    /* scratchpads */
    { MODKEY|ShiftMask,             XK_Return, togglescratch,  {.ui = 0 } }, /* open first scratchpad */
    { MODKEY|ShiftMask,             XK_f,      togglescratch,  {.ui = 1 } }, /* open second scratchpad */
    
    /* tags */
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    
    /* exit dwm */
    { ControlMask|Mod1Mask,         XK_Delete, quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

