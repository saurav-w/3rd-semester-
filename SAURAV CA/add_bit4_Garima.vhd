library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity add_bit4_garima is
    port(
        A, B      : in  std_logic_vector(3 downto 0);
        Sum       : out std_logic_vector(3 downto 0);
        Cout      : out std_logic;
        OVERFLOW  : out std_logic
    );
end add_bit4_garima;

architecture easy of add_bit4_garima is
    signal result_ext : signed(4 downto 0);
begin
    process(A, B)
    begin
        -- Signed extension before addition
        result_ext <= signed(A(3) & A) + signed(B(3) & B);

        Sum  <= std_logic_vector(result_ext(3 downto 0));
        Cout <= result_ext(4);

        -- Signed overflow detection
        OVERFLOW <= (A(3) xor result_ext(3)) and
                    (B(3) xor result_ext(3));
    end process;
end easy;

