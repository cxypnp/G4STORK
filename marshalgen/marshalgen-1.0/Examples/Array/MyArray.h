//MSH_BEGIN
class MyArray
{
public:
   int count = 0;
   double *HC; /* MSH: ptr_as_array
             [elementType: double ]
             [elementCount: { $ELE_COUNT = $THIS->count; }]
             [elementGet: { $ELEMENT = $THIS->HC[$ELE_INDEX]; }]
             [elementSet: { $THIS->HC[$ELE_INDEX] = $ELEMENT; }]
   */
   inline void add(double val) {
      this->HC = new double(val);
   };
}
//MSH_END
