library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity subbit4_Garima is
    port(
        A, B      : in  std_logic_vector(3 downto 0);
        Diff      : out std_logic_vector(3 downto 0);
        Cout      : out std_logic;
        OVERFLOW  : out std_logic
    );
end subbit4_Garima;

architecture easy of subbit4_Garima is
    signal result_ext : signed(4 downto 0);
begin
    process(A, B)
    begin
        -- Signed extension before subtraction (A - B)
        result_ext <= signed(A(3) & A) - signed(B(3) & B);

        Diff <= std_logic_vector(result_ext(3 downto 0));
        Cout <= result_ext(4);

        -- Signed overflow detection for subtraction
        OVERFLOW <= (A(3) xor B(3)) and
                    (A(3) xor result_ext(3));
    end process;
end easy;
