#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* 显示进度条 */
void progres()
{
  char s[101] = {0};
  memset(s, 0, sizeof s); /* -1 reserve for '\0' */
  const char ch[] = "\\|/-";
  for (size_t i = 0; i < 100; i++) {
    s[i] = '#';
    printf("\r[%-100s][%zu%%][%c]", s, i+1, ch[i%4]);
    fflush(stdout);
    usleep(10000);
  }
  printf("\n");
}


int main(void)
{

  progres();
  return 0;
}
