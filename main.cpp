#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

float CalculateBiggestRadius(const std::vector<Point>& points) {
    std::vector<std::pair<float, const Point*>> distances;
    for (const auto& point : points) {
        float distance = std::sqrt(point.x * point.x + point.y * point.y);
        distances.emplace_back(distance, &point);
    }

    std::sort(distances.begin(), distances.end());
    float radius = 0;
    std::set<std::string> ids;
    for (const auto& distance : distances) {
        if (ids.find(distance.second->id) != ids.end()) { //if id is already in there, stop
            break;
        }
        ids.insert(distance.second->id);
        radius = distance.first;
    }
    return radius;
}