import math, strformat

proc prediksiLimit(f: proc(x: float): float, a: float, epsilon: float): tuple[kiri, kanan, rata: float] =
  let kiri = f(a - epsilon)
  let kanan = f(a + epsilon)
  let rata = (kiri + kanan) / 2.0
  return (kiri, kanan, rata)

proc f(x: float): float =
  if abs(x - 4.0) < 1e-9:
    raise newException(ValueError, "fungsi ini dibagikan dengan nol")
  return (x.pow(2) - 16.0) / (x - 4.0)
  
try:
  let a = 4.0
  let epsilon = 1e-6
  let (kiri, kanan, rata) = prediksiLimit(f, a, epsilon)

  echo &"Prediksi limit x -> {a:.4f} dari kiri {kiri:.4f}"
  echo &"prediksi limit x -> {a:.4f} dari kanan: {kanan:.4f}"
  echo &"estimasi hasil: {rata:.3f}"

except ValueError as error:
  echo "Error nih: ", error.msg
