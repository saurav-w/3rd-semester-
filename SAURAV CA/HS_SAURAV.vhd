LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY HS_SAURAV IS
PORT(
    A : IN STD_LOGIC;
    B : IN STD_LOGIC;
    D : OUT STD_LOGIC;   -- Difference
    Bo : OUT STD_LOGIC   -- Borrow
);
END HS_SAURAV;

ARCHITECTURE Behaviour OF HS_SAURAV IS
BEGIN
    D  <= A XOR B;        -- Difference
    Bo <= (NOT A) AND B;  -- Borrow
END Behaviour;
