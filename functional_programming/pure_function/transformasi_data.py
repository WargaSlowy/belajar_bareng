from functools import lru_cache

def list_angka_double(angka: list[int]) -> list[int]:
    return [x * 2 for x in angka]

def cek_angka(angka: int) -> bool:
    return angka % 2 == 0

def panggil_nama(nama: str) -> str:
    return f"wello, {nama}"

def cek_umur(umur: int) -> bool:
    return umur >= 18

assert cek_umur(16) == False
assert cek_umur(19) == True

@lru_cache
def faktorial(n: int) -> int:
    if n == 0:
        return 1
    return n * faktorial(n - 1)



if __name__ == "__main__":
    data_utama: list[int] = [1, 2, 3]
    data_double = list_angka_double(data_utama)
    print(data_double)
