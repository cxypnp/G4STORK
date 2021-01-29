//MSH_BEGIN
template <class T> class MyTemplate1 {
public:
  T data;      /* MSH: primitive
   [elementType:
    (MSH_IsSameClass<T,int>) => int
    | true => double]
  */
};
//MSH_END
