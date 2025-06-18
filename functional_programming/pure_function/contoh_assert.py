x: int = 200
assert x == 5, "nilai x harus 5 gkboleh 200"

if x <= 5:
    raise AssertionError("x harus wajib positif")
