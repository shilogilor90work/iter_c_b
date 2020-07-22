namespace itertools{
   typedef struct{
       template <typename T>
       T operator ()(T first_value, T second_value) const{
           return first_value+second_value;
       }
   } sum;
   template <typename obj, typename  accumulate_func = sum>
   class accumulate{
       accumulate_func func;
       obj iter_obj;
    public:
       explicit accumulate(obj iter_obj, accumulate_func func = sum()): iter_obj(iter_obj), func(func){};
       class iterator{
          typename obj::value_type data;
          typename obj::iterator start;
          typename obj::iterator end;
           accumulate_func function;
       public:
           explicit iterator ( typename  obj::iterator start,typename  obj::iterator end, accumulate_func f): start(start),end(end) , function(f), data(*start){};
           iterator(const iterator& other) = default;
           iterator& operator=(const iterator& other){
               if(this != &other) {
                   this->data = other.data;
                   this->start = other.start;
                   this->end = other.end;
                   this->function = other.function;
               }
               return *this;
           };
           iterator& operator ++(){
               ++start;
               if(start != end)
                   data = function(data, *start);
               return *this;
           }
           iterator operator ++(int){
               iterator tmp = *this;
               ++(*this);
               return tmp;
           }
           bool operator ==(const iterator& other) {
               return (start == other.start);
           }
           bool operator !=(const iterator& other) {
               return (start != other.start);
           }

           auto operator *(){
               return data;
           }
       };
       iterator begin(){
           return iterator(iter_obj.begin(),iter_obj.end(), func);
       }
       iterator end(){
           return iterator(iter_obj.end(),iter_obj.end(), func);
       }

   };
}
