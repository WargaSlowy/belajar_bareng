angka: list[int] = [1, 2, 3, 4]
angka_genap = filter(lambda x: x % 2 == 0, angka)
print(list(angka_genap))
