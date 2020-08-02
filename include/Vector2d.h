#ifndef VECTOR2D_H
#define VECTOR2D_H

/*
Custom 2D vector that implements basic vector arithmetics
*/

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
    /*
    Vectorial sum. 
    */
    Vector2d<T> operator+(const Vector2d<T> &right){
      Vector2d<T> v;
      v.X = this->X + right.X;
      v.Y = this->Y + right.Y;
      return v;
    };
    /*
    Vectorial sum. 
    */
    Vector2d<T> operator+=(const Vector2d<T> &right){
      this->X += right.X;
      this->Y += right.Y;
      return *this;
    };
    /*
    Vectorial substraction
    */
    Vector2d<T> operator-=(const Vector2d<T> &right){
      this->X -= right.X;
      this->Y -= right.Y;
      return *this;
    };
   /*
    Vectorial substraction
    */

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

    /*
    Scales a vector by the given factor. Returns a 2D vector
    */
    Vector2d<T> Scale(const T &factor){
      this->X *= factor;
      this->Y *= factor;
      return *this;
    };
};

#endif