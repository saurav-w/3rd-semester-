
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity FULL_ADDER_SAURAV is
    Port (
        A    : in  STD_LOGIC;
        B    : in  STD_LOGIC;
        Cin  : in  STD_LOGIC;
        SUM  : out STD_LOGIC;
        Cout : out STD_LOGIC
    );
end FULL_ADDER_SAURAV;

architecture Behavioral of FULL_ADDER_SAURAV is
begin
    SUM  <= A xor B xor Cin;
    Cout <= (A and B) or (B and Cin) or (A and Cin);
end Behavioral;
