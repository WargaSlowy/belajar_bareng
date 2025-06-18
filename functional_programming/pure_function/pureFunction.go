package main

import "fmt"

func TambahAngka(a, b int) int {
	return a + b
}

func main() {
	hasil := TambahAngka(5, 7)
	fmt.Println("hasilnya adalah: ", hasil)
}
