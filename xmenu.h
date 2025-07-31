#pragma once

struct XMenu* xmenu_init(int argc, char** argv);
struct Menu*  xmenu_parsestdin(struct XMenu* xmenu);
void          xmenu_runloop(struct XMenu* xmenu, struct Menu* rootmenu);
void          xmenu_cleanup(struct XMenu* xmenu, struct Menu* rootmenu);