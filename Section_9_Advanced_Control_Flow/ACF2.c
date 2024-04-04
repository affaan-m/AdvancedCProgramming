#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery() {
    printf("detected an undrecoverable error\n");
    longjmp(buf, 1);
}

main()  {

  while (1) {
      if (setjmp(buf)) {
          printf("back in main\n");
          break;
      }
      else {
          error_recovery();
      }
  }
}