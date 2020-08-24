/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]        = "Source Code Pro:size=14";
static const char* normbgcolor  = "#111111";
static const char* normfgcolor  = "#ffffff";
static const char* selbgcolor   = "#333333";
static const char* selfgcolor   = "#ffffff";
static const char* urgbgcolor   = "#111111";
static const char* urgfgcolor   = "#cc0000";
static const char before[]      = "<";
static const char after[]       = ">";
static const char titletrim[]   = "";
static const int  tabwidth      = 20;
static const Bool foreground    = True;
static       Bool urgentswitch  = False;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int  newposition   = 0;
static Bool npisrelative  = False;

#define SETPROP(p) { \
        .v = (char *[]){ "/bin/sh", "-c", \
                "prop=\"`xwininfo -children -id $1 | grep '^     0x' |" \
                "sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' |" \
                "xargs -0 printf %b | dmenu -l 30 -w $1`\" &&" \
                "xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
                p, winid, NULL \
        } \
}

#define SETPROPNEW() { \
        .v = (char *[]){ "/bin/sh", "-c", \
        "xprop -id \"$0\" WM_NAME | cut -d '\"' -f2 | xargs dirname | xargs /usr/bin/find | dmenu -l 30 | xargs -r zathura -e \"$0\"", \
        winid, NULL \
        } \
}

#define SETPROPDET() { \
        .v = (char *[]){ "/bin/sh", "-c", \
        "xprop -id \"$0\" WM_NAME | cut -d '\"' -f2 | xargs zathura --fork", \
        winid, NULL \
        } \
}


#define MODKEY Mod1Mask
static Key keys[] = {
	/* modifier             key        function     argument */
	{ MODKEY,       	XK_Right,    rotate,      { .i = +1 } },
	{ MODKEY|ShiftMask,  	XK_Left,    rotate,      { .i = -1 } },
	{ MODKEY,       	XK_p,      spawn,       SETPROP("_TABBED_SELECT_TAB") },
	{ MODKEY,    		XK_o,      spawn,       SETPROPNEW() },
	{ MODKEY,    		XK_d,      spawn,       SETPROPDET() },
	{ MODKEY,    		XK_d,      killclient,  { 0 } },
        { MODKEY,    		XK_1,      move,        { .i = 0 } },
	{ MODKEY,    		XK_2,      move,        { .i = 1 } },
	{ MODKEY,    		XK_3,      move,        { .i = 2 } },
	{ MODKEY,    		XK_4,      move,        { .i = 3 } },
	{ MODKEY,    		XK_5,      move,        { .i = 4 } },
	{ MODKEY,    		XK_6,      move,        { .i = 5 } },
	{ MODKEY,    		XK_7,      move,        { .i = 6 } },
	{ MODKEY,    		XK_8,      move,        { .i = 7 } },
	{ MODKEY,    		XK_9,      move,        { .i = 8 } },
	{ MODKEY,    		XK_0,      move,        { .i = 9 } },
};
static Key keyreleases[] = {
	/* modifier             key          function     argument */
	{ MODKEY,     XK_q,      killclient,  { 0 } },
};
