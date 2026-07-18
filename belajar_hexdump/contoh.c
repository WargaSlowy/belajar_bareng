#include <ctype.h>
#include <limits.h>
#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ELF_HEADER_SIZE 64

enum { BYTES_PER_LINE = 16 };

typedef struct {
  size_t total_bytes;
  size_t total_lines;
} DumpStatistik;

static FILE* open_file(const char* filename) {
  FILE* file = fopen(filename, "rb");

  if (file == NULL) {
    perror(filename);
  }

  return file;
}

static char printable_char(unsigned char c) {
  return isprint(c) ? (char)c : '.';
}

static void print_offset(size_t offset) {
  printf("%08zx  ", offset);
}

static void print_hex(const unsigned char* buffer, size_t bytes_read) {
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
}

static void print_ascii(const unsigned char* buffer, size_t bytes_read) {
  putchar('|');

  for (size_t i = 0; i < bytes_read; i++) {
    putchar(printable_char(buffer[i]));
  }

  for (size_t i = bytes_read; i < BYTES_PER_LINE; i++) {
    putchar(' ');
  }

  putchar('|');
}

static void print_line(const unsigned char* buffer, size_t bytes_read, size_t offset) {
  print_offset(offset);
  print_hex(buffer, bytes_read);
  print_ascii(buffer, bytes_read);
  putchar('\n');
}

static void dump_file(FILE* file, DumpStatistik* stats) {
  unsigned char buffer[BYTES_PER_LINE];

  size_t offset = 0;
  size_t bytes_read;

  while ((bytes_read = fread(buffer, 1, BYTES_PER_LINE, file)) > 0) {
    print_line(buffer, bytes_read, offset);

    offset += bytes_read;

    stats->total_bytes += bytes_read;
    stats->total_lines++;
  }
}

static void print_hasil(const char* filename, const DumpStatistik* stats) {
  printf("filenya: %s\n", filename);
  printf("total bytesnya: %zu\n", stats->total_bytes);
  printf("total line: %zu\n", stats->total_lines);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "penggunaan: %s [file]\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE* file = open_file(argv[1]);

  if (file == NULL) {
    return EXIT_FAILURE;
  }

  DumpStatistik stats = {0};

  dump_file(file, &stats);

  fclose(file);

  print_hasil(argv[1], &stats);

  return 0;
}
