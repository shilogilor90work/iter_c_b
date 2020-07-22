#include <iostream>
namespace itertools
{
    template<typename obj_vector , typename obj_vector_bool> class compress
    {
        obj_vector vec;
        obj_vector_bool bool_vec;
        public:
        explicit compress ( obj_vector c, obj_vector_bool bool_vec) : vec(vec),bool_vec(bool_vec){
           typename obj_vector::iterator start= vec.begin();
           typename obj_vector_bool::iterator bool_start= bool_vec.begin();
           int check_size_vec=0;
           int check_size_bool=0;
           while(start!=vec.end())
           {
               ++start;
               ++check_size_vec;
           }
             while(bool_start!=bool_vec.end())
           {
               ++bool_start;
               ++check_size_bool;
           }

           if(check_size_vec!=check_size_bool)
           throw std::invalid_argument ("containers must be same size");
    }
      class iterator{
         typename obj_vector :: iterator start;
         typename obj_vector :: iterator end;
         typename obj_vector_bool :: iterator bool_start;
         public:
         iterator(typename obj_vector :: iterator start,  typename obj_vector :: iterator end,  typename obj_vector_bool :: iterator bool_start) : start(start), end(end), bool_start(bool_start){
             while( start!=end&&!(*bool_start))
             {
                 ++start;
                 ++bool_start;
             }
         }
         bool operator == (const iterator& other)
         {
             return (start==other.start);
         }

         bool operator != (const iterator& other)
         {
             return (start!=other.start);
         }

         iterator& operator = (const iterator& other)
         {
             start=other.start;
             end=other.end;
             bool_start=other.bool_start;
         }
         iterator& operator ++()
         {
             do
             {
               ++start;
               ++bool_start;
             }
             while(start!=end && !(*bool_start));
             return *this;
         }

         iterator& operator ++(int)
         {
            return ++(*this);
         }
         auto operator *()
         {
           return *start;
         }
      };
    iterator begin()
    {
        return iterator(vec.begin(),vec.end(),bool_vec.begin());
    }
    iterator end()
    {
        return iterator(vec.end(),vec.end(),bool_vec.end());
    }

};
}
