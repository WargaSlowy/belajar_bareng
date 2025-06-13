const std = @import("std");

fn prediksiLimit(
    func: fn(f64) f64,
    a: f64,
    epsilon: f64,
) struct { kiri: f64, kanan: f64, rata: f64} {
    const kiri = func(a - epsilon);
    const kanan = func(a + epsilon);
    const rata = (kiri + kanan) / 2.0;

    return .{ .kiri = kiri, .kanan = kanan, .rata = rata };
}

fn f(x: f64) f64 {
    if (std.math.approxEqAbs(f64, x, 4.0, 1e-9)) {
        std.debug.panic("fungsi ini tidak terdefinisi karena pembagian nol", .{});
    }
    return (std.math.pow(f64, x, 2) - 16.0) / (x - 4.0);
}

pub fn main() void {
    const a: f64 = 4.0;
    const epsilon: f64 = 1e-6;

    const hasil = prediksiLimit(f, a, epsilon);

    std.log.info("prediksi limit x {d:.4} dari kiri: {d:.4}", .{a, hasil.kiri});
    std.log.info("prediksi limit x {d:.4} dari kanan: {d:.4}", .{a, hasil.kanan});
    std.log.info("prediksi hasil: {d:.4}", .{hasil.rata});
}
