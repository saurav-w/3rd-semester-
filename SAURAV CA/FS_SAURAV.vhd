LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY  FS_SAURAV IS
PORT(
    A   : IN  STD_LOGIC;
    B   : IN  STD_LOGIC;
    Bin : IN  STD_LOGIC;
    D   : OUT STD_LOGIC;  -- Difference
    Bo  : OUT STD_LOGIC   -- Borrow out
);
END FS_SAURAV;

ARCHITECTURE Behaviour OF FS_SAURAV IS
BEGIN
    D  <= A XOR B XOR Bin;
    Bo <= ((NOT A) AND B) OR ((NOT A) AND Bin) OR (B AND Bin);
END Behaviour;
