#pragma once

#include <Imlib2.h>
#include <X11/X.h>
#include <X11/Xlib.h>


/* menu item structure */
struct Item {
	char*        label;      /* string to be drawed on menu */
	char*        output;     /* string to be outputed when item is clicked */
	char*        file;       /* filename of the icon */
	int          y;          /* item y position relative to menu */
	int          h;          /* item height */
	int          textw;      /* text width */
	struct Item* prev;       /* previous item */
	struct Item* next;       /* next item */
	struct Menu* submenu;    /* submenu spawned by clicking on item */
	Drawable     sel, unsel; /* pixmap for selected and unselected item */
	Imlib_Image  icon;
};

/* menu structure */
struct Menu {
	struct Menu* parent;     /* parent menu */
	struct Item* caller;     /* item that spawned the menu */
	struct Item* list;       /* list of items contained by the menu */
	struct Item* first;      /* first item displayed on the menu */
	struct Item* selected;   /* item currently selected in the menu */
	int          x, y, w, h; /* menu geometry */
	int          hasicon;    /* whether the menu has item with icons */
	int          drawn;      /* whether the menu was already drawn */
	int          maxtextw;   /* maximum text width */
	int          level;      /* menu level relative to root */
	int          overflow;   /* whether the menu is higher than the monitor */
	Window       win;        /* menu window to map on the screen */
	XIC          xic;        /* input context */
};


struct Menu* xmenu_init(void);
void         xmenu_runloop(struct Menu* rootmenu);
void         xmenu_cleanup(struct Menu* rootmenu);