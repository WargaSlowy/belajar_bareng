#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_LINE 16

int main() {
  FILE* file = fopen("/proc/self/exe", "rb");

  if (file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  unsigned char buffer[BYTES_PER_LINE];
  size_t offset = 0;
  size_t bytes_read;

  while ((bytes_read = fread(buffer, 1, BYTES_PER_LINE, file)) > 0) {
    printf("%08zx   ", offset);
    offset++;

    // heksadesimal
    for (size_t i = 0; i < BYTES_PER_LINE; i++) {
      if (i < bytes_read) {
        printf("%02X  ", buffer[i]);
      } else {
        printf("    ");
      }

      if (i == 7) {
        printf("   ");
      }
    }

    printf("  |");

    // si ascii
    for (size_t i = 0; i < bytes_read; i++) {
      if (isprint(buffer[i])) {
        printf("%c", buffer[i]);
      } else {
        printf(".");
      }
    }

    printf("|\n");
    offset += bytes_read;
  }
  fclose(file);

  // 0 -> 255

  return 0;
}
