// RiverWM config on C by holos
#include <stdlib.h>
#include <stdio.h>

const char *term = "alacritty";
const char *menu = "wmenu-run";

int keymap() {
	// Base keybindings
	char tty[256];
    	snprintf(tty, sizeof(tty), "riverctl map normal Super Z spawn %s", term);
	system(tty);
	snprintf(tty, sizeof(tty), "riverctl map normal Super R spawn %s", menu);
	system(tty);
	system("riverctl map normal Super C close");
  	system("riverctl map normal Super+Shift Q exit");
  	system("riverctl map normal Super F toggle-float");
	// Keyboard bind
  	system("riverctl keyboard-layout -options \"grp:win_space_toggle\" \"us,ru\"");
	// Switch bind
	system("for i in $(seq 1 9); do "
        	"riverctl map normal Super $i set-focused-tags $((1 << ($i - 1))); "
        	"riverctl map normal Super+Shift $i set-view-tags $((1 << ($i - 1))); "
	    "done"
	);
}

int autostart() {
	// Start wlrandr
	system("wlr-randr --output HDMI-A-1 --mode 1366x768 &");
	// Start pipewire
  	system("pipewire &");
  	system("pipewire-alsa &");
	system("wireplumber &");
	// Start rivertile
	system("riverctl default-layout rivertile &");
	system("rivertile -view-padding 0 -outer-padding 0 &");
	// Start riverbar
	system("riverctl spawn \"$HOME/.config/river/status\"");
    	system("riverctl spawn \"$HOME/.config/river/bar\"");
}

int main() {
  	keymap();
	autostart();
}
