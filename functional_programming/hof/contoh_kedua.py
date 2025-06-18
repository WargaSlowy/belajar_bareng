from typing import Callable

def buat_diskon(persen: float) -> Callable:
    def terapkan_diskon(harga: float) -> float:
        return harga * (1 - persen / 100)
    return terapkan_diskon

def panggil(nama: str) -> None:
    print("wello", nama)

if __name__ == "__main__":
    diskon_dua_puluh_persen = buat_diskon(20)

    print(diskon_dua_puluh_persen(100))
