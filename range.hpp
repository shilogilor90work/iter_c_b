namespace itertools{
    class range{
        int start_range;
        int end_range;
    public:
        range(int start_point, int end_point){
          this->start_range = start_point;
          this->end_range = end_point;
        }
    typedef  int value_type;
        class iterator{
            int start_iter;
        public:
            explicit iterator(int st){
              this->start_iter=st;
            };
            iterator& operator=(const iterator& other){
                if(this != &other)
                    this->start_iter = other.start_iter;
                return *this;
            };
            iterator& operator ++(){
                ++start_iter;
                return *this;
            }
            iterator operator ++(int){
                iterator tmp = *this;
                ++start_iter;
                return tmp;
            }
            bool operator ==(const iterator& other) {
                return (start_iter == other.start_iter);
            }
            bool operator !=(const iterator& other) {
                return (start_iter != other.start_iter);
            }
            int operator *(){
                return start_iter;
            }
        };
        iterator begin(){
            return iterator(start_range);
        }
        iterator end(){
            return iterator(end_range);
        }
    };
}
