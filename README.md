SquareGen
======

The aim of this project is to write a simple AI that would generate strings of fixed length (called 'n') over binary alphabet ({0, 1}) that would contain the highest
amount of distinct squares possible. A square is such a substring *z* that the whole string contains at least one occurence of *zz* .

Highscores so far:
------

**Method: NMCS**    
n = 100   
Result: 74    
String: 1000000100000010000010000001000001000010000010001000010001000010011010110111011110111110111111011111   
String: 1000000100000001000000100000001000000100000100000010001001000100001000110011010110101101101011011010  

n = 200   
Result: 72  
String: 10000000000100000000000010000000000000100000000000000000010000100000010101011100111100000100000011010001100010111011110111100000100010100110001100100011111011111000100011011000000010000000001000000000

**Method: NRPA**  
n = 100   
Result: 82  
String: 0000010000010000000100000000100000001000000001000000000010000000001000000000010000000001000000100000  
String: 0000010000010000000100000000100000000010000000010000000001000000000010000000001000000000010000000000

n = 200  
Result: 169   
String: 00100100010000010000000010000000001000000000000000100000000000001000000000000000100000000000000001000000000000000000100000000000000000100000000000000000010000000000000000010000000000001000000010000000

n = 500
Result: 441   
String: 00001000000100000000001000000000000000010000000000000001000000000000000001000000000000000000001000000000000000000000010000000000000000000000010000000000000000000000001000000000000000000000000001000000000000000000000000000100000000000000000000000000001000000000000000000000000000000100000000000000000000000000000000010000000000000000000000000000000000100000000000000000000000000000000000010000000000000000000000000000000000000100000000000000000000000000000001000000000000000000000000010000000000000000

**Method: Beam-NRPA**    
n = 500   
Result: 444  
String: 00001000010001000010000010000000100000000100000001000000000100000000000001000000000000001000000000000000010000000000000000010000000000000000000100000000000000000000010000000000000000000000100000000000000000000000010000000000000000000000000100000000000000000000000000100000000000000000000000000000100000000000000000000000000000010000000000000000000000000000000100000000000000000000000000000000010000000000000000000000000000000000100000000000000000000000000000000010000000000000000000000000000000010000

**Method: Generating pattern**   
n = 200   
Result: 172   
String: 11001000100001000001000000100000001000000001000000000100000000001000000000001000000000000100000000000001000000000000001000000000000000100000000000000001000000000000000001000000000000000000100000000000

n = 500   
Result 454   
String: 11001000100001000001000000100000001000000001000000000100000000001000000000001000000000000100000000000001000000000000001000000000000000100000000000000001000000000000000001000000000000000000100000000000000000001000000000000000000001000000000000000000000100000000000000000000001000000000000000000000001000000000000000000000000100000000000000000000000001000000000000000000000000001000000000000000000000000000100000000000000000000000000001000000000000000000000000000001000000000000000000000000000000100000

