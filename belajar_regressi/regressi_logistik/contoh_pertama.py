def sigmoid(z: float) -> float:
    return 1 / (1 + pow(2.71828, -z))

def logistik_regressi(fitur: dict[str, float], bobot: dict[str, float], bias: float) -> float:
    z = bias
    for fiturs in fitur:
        z += bobot[fiturs] * fitur[fiturs]
    probabilitas = sigmoid(z)
    return probabilitas

if __name__ == "__main__":
    fitur_user = {
        "email_per_minggu": 4,
        "rata_rata_buka_perjam": 3,
    }

    bobot = {
        "email_per_minggu": 0.3,
        "rata_rata_buka_perjam": -0.2,
    }

    bias = -1.5

    probabilitas = logistik_regressi(fitur_user, bobot, bias)
    print(f"probabilitas hasilnya adalah: {probabilitas:.3f}")
