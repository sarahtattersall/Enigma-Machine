#ifndef MAPPER_HPP
#define MAPPER_HPP

class Mapper{
    public:
  // Not a nice interface. In general, avoid passing small things by reference,
  // The main reason for passing by reference is to avoid copying, it's an
  // optimisation. Its also not a good optimisation in the case of things that are not
  // bigger than a pointer.
  // It is also not a very nice design for an API, mutalble parameters are always hard
  // to reason about.
  // virtual int map (int) = 0;
  // Would be a lot cleaner.
 /* VERY EXPENSIVE!!!! */
        virtual int map( int ) = 0;
};

#endif
