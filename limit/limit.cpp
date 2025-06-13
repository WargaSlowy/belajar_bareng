#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>

using MathFunc = double (*)(double);

void prediksi_limit(MathFunc f, double a, double epsilon, double &kiri,
                    double &kanan, double &rata) {
  kiri = f(a - epsilon);
  kanan = f(a + epsilon);
  rata = (kiri + kanan) / 2.0;
}

double f(double x) {
  if (std::abs(x - 4.0) < 1e-9) {
    throw std::runtime_error("dibagi dengan nol");
  }
  return (std::pow(x, 2) - 16.0) / (x - 4.0);
}

int main() {
  double a = 4.0;
  double epsilon = 1e-6;
  double kiri, kanan, rata;

  try {
    prediksi_limit(f, a, epsilon, kiri, kanan, rata);
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "prediksi limit saat x " << a << " dari kiri adalah: " << kiri
              << std::endl;
    std::cout << "prediksi limit saat x " << a
              << " dari kanan adalah: " << kanan << std::endl;
    std::cout << "hasilnya adalah: " << rata << std::endl;
  } catch (std::exception &error) {
    std::cerr << "error bang: " << error.what() << std::endl;
  }

  return 0;
}
