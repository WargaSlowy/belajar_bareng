from typing import Callable


def fungsi_posisi(t: float) -> float:
    return t**3 - 6 * t**2 + 9 * t


def fungsi_turunan(t: float) -> float:
    return 3 * t**2 - 12 * t + 9


def hitung(fungsi_turunan: Callable[[float], float], waktu: float) -> float:
    return fungsi_turunan(waktu)

if __name__ == "__main__":
    target_waktu: float = 2.0
    hasil = hitung(fungsi_turunan, target_waktu)
    print(f"kecepatannya adalah = {int(hasil)} blabla/detik")
