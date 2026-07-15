#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_LINE 16

void print_binary(unsigned char byte) {
  for (int i = 7; i >= 0; i--) {
    putchar((byte >> i) & 1 ? '1' : '0');
  }
}

int main() {
  FILE* file = fopen("/proc/self/exe", "rb");

  printf("sumber: `/proc/self/exe`\n");
  printf("bytesnya: %d per baris\n\n", BYTES_PER_LINE);

  if (file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  unsigned char buffer[BYTES_PER_LINE];
  size_t offset = 0;
  size_t bytes_read;

  size_t total_bytes = 0;
  size_t line = 1;

  while ((bytes_read = fread(buffer, 1, BYTES_PER_LINE, file)) > 0) {
    printf("[%03zu] %08zx  ", line, offset);

    // heksadesimal
    for (size_t i = 0; i < BYTES_PER_LINE; i++) {
      if (i < bytes_read) {
        printf("%02X ", buffer[i]);
      } else {
        printf("  ");
      }

      if (i == 7) {
        printf("  ");
      }
    }

    printf("  |");

    // si ascii
    for (size_t i = 0; i < bytes_read; i++) {
      if (isprint(buffer[i])) {
        putchar(buffer[i]);
      } else {
        putchar('.');
      }
    }

    printf("|\n");
    offset += bytes_read;
    total_bytes += bytes_read;
    line++;
  }

  printf("\n\ntotal baris: %zu baris\n", line - 1);
  printf("total bytes: %zu bytes\n\n", total_bytes);
  
  printf("16 byte pertama dari binernya\n");
  rewind(file);

  fread(buffer, 1, BYTES_PER_LINE, file);

  for (size_t i = 0; i < BYTES_PER_LINE; i++) {
    printf("%02X : ", buffer[i]);
    print_binary(buffer[i]);
    printf("\n");
  }
  fclose(file);

  // 0 -> 255

  return 0;
}
