namespace itertools{
    template<typename func, typename iter_obj>
    class filterfalse {
        func f;
        iter_obj& this_iter_obj;
        typedef typename iter_obj::value_type value_type;
    public:
        filterfalse(func f, iter_obj& container): f(f), this_iter_obj(container){}

        class iterator{
            typename iter_obj::iterator start;
            typename iter_obj::iterator end;
            func f;
        public:
            explicit iterator(typename iter_obj::iterator iter, typename iter_obj::iterator end, func f): start(iter), end(end), f(f){
              while (start != end && f(*start))
              {
                ++start;
              }
            }
            iterator(const iterator& other) = default;

            iterator& operator=(const iterator& other){
                if(this != &other) {
                    this->start = other.start;
                    this->end = other.end;
                    this->f = other.f;
                }
                return *this;
            };
            iterator& operator ++(){
                do{
                    ++start;
                } while (start != end && f(*start));
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
            value_type operator *(){
                return *start;
            }
        };
        iterator begin(){
            return iterator(this_iter_obj.begin(), this_iter_obj.end(), f);
        }
        iterator end(){
            return iterator(this_iter_obj.end(), this_iter_obj.end(), f);
        }
    };
}
