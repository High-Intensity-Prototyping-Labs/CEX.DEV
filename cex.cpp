#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

struct Vec3D {
        float x, y, z;

        static Vec3D make(void);
        Vec3D copy(void);

        float abs(void);
        void normalize(void);
};

Vec3D Vec3D::make() {
        return (struct Vec3D) {
                .x = 0,
                .y = 0,
                .z = 0,
        };
}

Vec3D Vec3D::copy() {
        return *this;
}

float Vec3D::abs() {
        float x,y,z;
        x = this->x;
        y = this->y;
        z = this->z;

        return sqrt(x*x + y*y + z*z);
}

void Vec3D::normalize() {
        this->x = this->x / abs();
        this->y = this->y / abs();
        this->z = this->z / abs();
}

ostream& operator<<(ostream& os, Vec3D& pos) {
        os << "struct Vec3D {" << endl;
        os << "\t.x = " << pos.x << endl;
        os << "\t.y = " << pos.y << endl;
        os << "\t.z = " << pos.z << endl;
        os << "}" << endl;

        return os;
}

int main(void) {

        Vec3D pos1 = Vec3D::make();
        Vec3D pos2;

        cout << "Before:" << endl;
        cout << pos1 << endl;

        pos1.x += 1.3f;
        pos1.y -= 9.8f;
        pos1.normalize();

        cout << "After:" << endl;
        cout << pos1 << endl;

        pos2 = pos1.copy();

        cout << "Vec3D2:" << endl;
        cout << pos2 << endl;

        return 0;
}
