#!/bin/bash

function f {
  local x="$1"
  echo "scale=10; ($x^2 - 16)/($x - 4)" | bc -l
}

a=4
epsilon="0.000001"

kiri=$(f "$(echo "$a - $epsilon" | bc -l)")
kanan=$(f "$(echo "$a + epsilon" | bc -l)")
rata=$(echo "scale=10; ($kiri + $kanan)/2" | bc -l)

printf "prediksi limit saat x -> %.4f dari kiri: %.4f\n" "$a" "$kiri"
printf "preikdisi limit x -> %.4f dari kanan: %.4f\n" "$a" "$kanan"
printf "hasil adalah: %.4f\n" "$rata"
