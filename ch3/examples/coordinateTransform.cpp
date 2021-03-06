#include <iostream>
#include <vector>
#include <algorithm>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
    // define the q1 and q2 in world coordinate system using quaterniond.
    Quaterniond q1(0.35, 0.2, 0.3, 0.1), q2(-0.5, 0.4, -0.1, 0.2);
    // normalize before using.
    q1.normalize();
    q2.normalize();
    //define the coordinate of q1, q2 of itselves.
    Vector3d t1(0.3, 0.1, 0.1), t2(-0.1, 0.5, 0.3);
    Vector3d p1(0.5, 0, 0.2);
    Vector3d p2;
    // Quaterniond  Solution
    // pw means the coordinate in world coordinate system.
    // p1 = q1*pw + t1;
    // p2 = q2*pw + t2;
    // so p2 = q2 * q1^{-1} *(p1 - t1)  + t2 
    // Mention: in Eigen, Quaterniond times is q*P, while q*P*q^{-1} in math.
    p2 = q2 * q1.inverse() * (p1 - t1 ) + t2;
    cout << p2.transpose()<<endl;
    
    //Rotation Matirx Solution
    //Euler transformation matrix initialize.
    Isometry3d T1w = Isometry3d::Identity(), T2w = Isometry3d::Identity();
    T1w.rotate(q1);
    T2w.rotate(q2);
    T1w.pretranslate(t1);
    T2w.pretranslate(t2);
    Vector3d  p2_ = T2w * T1w.inverse() * p1;
    cout << p2_.transpose()<<endl;

    // Isometry3d T1w(q1), T2w(q2);

    // T1w.pretranslate(t1);
    // T2w.pretranslate(t2);

    // Vector3d p2 = T2w * T1w.inverse() * p1;
    // cout << endl<< p2.transpose() << endl;
    return 0;
}