#ifndef VECN_H
#define VECN_H

struct VecN {
    int N;
    float* data;

    VecN();
    VecN(int N);
    VecN(const VecN& v);
    ~VecN();

    //dot product
    float Dot(const VecN& v) const;

    //make all elements zero
    void Zero();

    //add, subtract, scale op overloads
    VecN& operator = (const VecN& v);
    VecN operator + (const VecN& v) const;
    VecN operator - (const VecN& v) const;
    VecN operator * (const float n) const;

    //equal op overloads
    const VecN& operator += (const VecN& v);
    const VecN& operator -= (const VecN& v);
    const VecN& operator *= (const float n);

    //get value square bracket op overload
    float operator [] (const int index) const;
    float& operator [] (const int index);
};

#endif