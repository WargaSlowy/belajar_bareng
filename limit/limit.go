package main

import (
	"fmt"
	"math"
)

type MathFunc func(float64) float64

func prediksiLimit(f MathFunc, a float64, epsilon float64) (float64, float64, float64) {
	kiri := f(a - epsilon)
	kanan := f(a + epsilon)
	rata := (kiri + kanan) / 2
	return kiri, kanan, rata
}

func f(x float64) float64 {
	if math.Abs(x - 4) < 1e-9 {
		panic("fungsi ini tidak terdefinisi karena pembagian dengan nol")
	}
	return (math.Pow(x, 2) - 16) / (x - 4)
}

func main() {
	a := 4.0
	epsilon := 1e-6

	defer func() {
		if r := recover(); r != nil {
			fmt.Println("ada error: ", r)
		}
}()

	kiri, kanan, rata := prediksiLimit(f, a, epsilon)

	fmt.Printf("prediksi limit saat x -> %.4f dari kiri: %.4f\n", a, kiri)
	fmt.Printf("prediksi limit saat x -> %.4f dari kanan: %.4f\n", a, kanan)
	fmt.Printf("estimasi rata-rata nilai limit adalah: %.2f\n", rata)
}
