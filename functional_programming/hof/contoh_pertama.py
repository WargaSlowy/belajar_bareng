from typing import Callable

def diskon_sepuluh_persen(harga: float) -> float:
    return harga * 0.9

def terapkan_diskon(harga: list[float], fungsi_diskon: Callable) -> list[float]:
    return [fungsi_diskon(harga_barang) for harga_barang in harga]

if __name__ == "__main__":
    harga: list[float] = [100, 200, 300]
    harga_diskon = terapkan_diskon(harga, diskon_sepuluh_persen)

    print(harga_diskon)

diskon_kita = diskon_sepuluh_persen
diskon_kita(100)
