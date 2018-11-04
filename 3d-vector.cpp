#include <bits/stdc++.h>
#define db double
class Vector3D {
    
    public:
    
       
        db x,y,z;
        // Constructors

        // Vector3Dtors default to 0, 0, 0.
        Vector3D() {
            x = 0;
            y = 0;
            z = 0;
        }

        // Construct with values
        Vector3D(db ax, db ay, db az) {
            x = ax;
            y = ay;
            z = az;
        }

        // Copy another Vector
        Vector3D(const Vector3D& o) {
            x = o.x;
            y = o.y;
            z = o.z;
        }

        // Addition
        
        Vector3D operator+(const Vector3D& o) {
            return Vector3D(x + o.x, y + o.y, z + o.z);
        }

        // Subtraction

        Vector3D operator-(const Vector3D& o) {
            return Vector3D(x - o.x, y - o.y, z - o.z);
        }


        // Multiplication by scalars

        Vector3D operator*(const db s) {
            return Vector3D(x * s, y * s, z * s);
        }

        // Division by scalars

        Vector3D operator/(const db s) {
            return Vector3D(x / s, y / s, z / s);
        }
        
        // Dot product

        db operator*(const Vector3D& o) {
            return (x * o.x) + (y * o.y) + (z * o.z);
        }

        // Cross product

        Vector3D operator^(const Vector3D& o) {
            db new_x = y * o.z - o.y * z;
            db new_y = z * o.x - o.z * x;
            db new_z = x * o.y - o.x * y;
            return Vector3D(new_x, new_y, new_z);
        }

        
        // magnitude
        db magnitude() {
            return sqrt((x * x) + (y * y) + (z * z));
        }
        
        //noramlize vector
        Vector3D normalised() {
            return Vector3D(*this) / magnitude();
        }
        
};
 
 
