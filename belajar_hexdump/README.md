# Warga slowy HexDump

implement dasar dari hexdump dengan C.

## Tujuannya

- binary file i/o
- hex dump
- baca elf header
- baca arsitektur cpu
- ngeparsing biner
- baca little endian

## Cara Menjalankannya

```
gcc -o contoh contoh.c
./contoh
```

## Output result

```
total baris: 1037 baris
total bytes: 16584 bytes


frekuensi bytenya
16 byte pertama dari binernya
7F (127) : 01111111
45 ( 69) : 01000101
4C ( 76) : 01001100
46 ( 70) : 01000110
02 (  2) : 00000010
01 (  1) : 00000001
01 (  1) : 00000001
00 (  0) : 00000000
00 (  0) : 00000000
00 (  0) : 00000000
00 (  0) : 00000000
00 (  0) : 00000000
00 (  0) : 00000000
00 (  0) : 00000000
00 (  0) : 00000000
00 (  0) : 00000000
```
