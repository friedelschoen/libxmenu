#include "xmenu.h"

int main(int argc, char** argv) {
	struct XMenu* xmenu = xmenu_init(argc, argv);
	struct Menu*  root  = xmenu_parsestdin(xmenu);
	xmenu_runloop(xmenu, root);
	xmenu_cleanup(xmenu, root);
}