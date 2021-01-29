//MSH_BEGIN
template <T> class MyTemplate2 {
public:
  T data;      /* MSH: predefined
   [elementType:
    (MSH_IsSameClass<T,int>) => int
    | true => Bar2]
  */
};
//MSH_END
//MSH_BEGIN
class Bar2{
    double x; //MSH: primitive
    double y; //MSH: primitive
}
//MSH_END
