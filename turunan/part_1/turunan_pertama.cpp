#include <iostream>
#include <functional>

double posisi(double t) {
  return t * t * t - 6 * t * t * 9 * t;
}

double fungsi_turunan(double t) {
  return 3 * t * t - 12 * t + 9;
}

double hitung(std::function<double(double)> fungsi_turunan, double waktu) {
  return fungsi_turunan(waktu);
}

int main() {
  const double waktu_target = 2.0;
  double hasil = hitung(fungsi_turunan, waktu_target);
  
  std::cout.precision(3);
  std::cout << "hasilnya adalah: " << hasil << " blablabla / detik" << std::endl;
  return 0;
}
