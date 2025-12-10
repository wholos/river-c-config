// RiverWM config on C by holos
#include <stdlib.h>

int term = alacritty;
int menu = wmenu-run;

int main() {
  system("riverctl map normal Super Z spawn ", term);
  system("riverctl map normal Super C close");
  system("riverctl map normal Super R spawn ", menu);
  system("iverctl map normal Super+Shift Q exit");
  system("riverctl default-layout rivertile");
  system("rivertile -view-padding 0 -outer-padding 0 &");
  system("riverctl map normal Super F toggle-float");
  system("riverctl spawn \"$HOME/.config/river/status\"");
  system("riverctl spawn \"$HOME/.config/river/bar\"");
  system("riverctl keyboard-layout -options \"grp:win_space_toggle\" \"us,ru\"");
}
