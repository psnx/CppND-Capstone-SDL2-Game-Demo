#ifndef VECTOR2D_H
#define VECTOR2D_H

template<typename T>
class Vector2d {
  public:
    Vector2d() {}
    Vector2d(T x, T y): X(x), Y(y){}
    ~Vector2d() {}

    T X{0};
    T Y{0};
  
    static T DotProduct (const Vector2d<T> &one, const Vector2d<T> &two) {
      return (one.X * two.X + one.Y * two.Y);
    };

    Vector2d<T> operator+(const Vector2d<T> &right){
      Vector2d<T> v;
      v.X = this->X + right.X;
      v.Y = this->Y + right.Y;
      return v;
    };

    Vector2d<T> operator+=(const Vector2d<T> &right){
      this->X += right.X;
      this->Y += right.Y;
      return *this;
    };
    Vector2d<T> operator-=(const Vector2d<T> &right){
      this->X -= right.X;
      this->Y -= right.Y;
      return *this;
    };

    Vector2d<T> operator-(const Vector2d<T> &right){
      Vector2d<T> v;
      v.X = this->X - right.X;
      v.Y = this->Y - right.Y;
      return v;
    };
    /* 
    Dot product operator for Vector2d<T>
    */
    T operator*(const Vector2d<T> &right){
      return Vector2d<T>::DotProduct(*this, right);
    };

    Vector2d<T> Scale(T factor){
      this->X *= factor;
      this->Y *= factor;
      return *this;
    };
};

#endif