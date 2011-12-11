#ifndef ENIGMA_LETTER_HPP
#define ENIGMA_LETTER_HPP

class EnigmaLetter{
    public:
        // Constructs letter from char
        // 
        EnigmaLetter( char value );
        
        // Constructs letter from integer representation
        // EnigmaLetter( int value );

        
        // Overrides + operator
        EnigmaLetter operator+(const EnigmaLetter& letter) const;
        
        // Overrides - operator
        // type of this is const
        EnigmaLetter operator-(const EnigmaLetter& letter) const;
        
        // Overrides = operator
        EnigmaLetter operator=(const EnigmaLetter& letter);
        
        // Overrides ++ operator
        void operator++(int value);

        char to_char() const;
        int to_int() const;
        
    private:
        EnigmaLetter();
        static const int m_error_value;
        int m_representation;
        int mod( int value, int mod_value ) const;
};

#endif