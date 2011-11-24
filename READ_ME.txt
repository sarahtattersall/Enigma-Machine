Design Decisions:
ROTORS:
When reading in the rotor files because memory is not an issue I have decided
to store mappings and reverse mappings seperatly. This is beacuse it makes
map and reverse_map easy to compute. If I was to store the exact values of
the rotor file when I chose to inversely map I would have to find the
int in the vector and then perform calculations to compute the inverse int.
Doing it this was is not as efficient as just indexing the rev_mappings array
which is O(1).
When rotating the rotors I understand that it is the wiring that rotates. Thus
for I.rot the first mapping is 0 to 1. When it rotates 0 will still map to 1 because
1's mapping was to 2 which is an offset of 1. It is the offset that rotates.


Enigma Extensions:
NOTCHES:
After researching the notches I have decided to implement a notch system for each rotor.
In order to make this work I have chosen to modify the .rot files so that after a number
they have " N". I.e. 0 N 1 would mean that the rotor has a notch at A. Similarly
0 1 2 N 3 4 5 N 6 7 would imply notches at C and F. I have chosen to implement it this
way so that the original rotor files also still work. Thus if after being read in
no notches have been seen it will add a notch at A.


