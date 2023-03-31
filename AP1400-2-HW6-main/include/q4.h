#ifndef Q4_H
#define Q4_H
#include <vector>
#include <algorithm>
#include <numeric>

namespace q4 {
struct Vector2D {
    Vector2D(double xx, double yy) : x(xx), y(yy) {}
    Vector2D() : Vector2D(0, 0) {}
    double x{};
    double y{};
};

struct Sensor {
    Sensor(double x, double y, double acc) : accuracy(acc) {
        pos.x = x;
        pos.y = y;
    }
    Sensor(const Vector2D& v, double acc) : pos(v), accuracy(acc) {}
    Vector2D pos;
    double accuracy;
};

Vector2D kalman_filter(std::vector<Sensor> sensors) {
    double sum = 0;
    auto accumulater = [&sum](const Sensor& s) -> void {sum += s.accuracy;};
    for_each(sensors.begin(), sensors.end(), accumulater);

    std::vector<double> weight;
    auto weight_builder = [&weight, sum](const Sensor& s) -> void {weight.push_back(s.accuracy / sum);};
    for_each(sensors.begin(), sensors.end(), weight_builder);

    double X = 0;
    size_t i = 0;
    auto w_x = [weight, sensors, &X, &i](const Sensor& s) -> void { X += weight[i] * sensors[i].pos.x; ++i;};
    for_each(sensors.begin(), sensors.end(), w_x);

    double Y = 0;
    i = 0;
    auto w_y = [weight, sensors, &Y, &i](const Sensor& s) -> void { Y += weight[i] * sensors[i].pos.y; ++i;};
    for_each(sensors.begin(), sensors.end(), w_y);

    return Vector2D{X, Y};
}

}  // namespace q4

#endif  // Q4_H