#!/bin/bash

kali() {
  local a=$1
  local b=$2
  echo $((a * b))
}

hasil=$(kali 10 10)
echo "hasil: $hasil"
