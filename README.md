# BattleshipPositions
c++ program to calculate the num of positions possible in battleship

the idea is to create a program that calculates all possible positions

other stuff
  also put in the ability to enter specific dots(misses), then calculate the number of ways to arrange ships so that there are no hits

big goals currently:
reduce the number of iterations by as much as possible

ways to create a recursive loop: have a vector with the ships, then have a recursive loop function that goes through the vector holding ships, that way i can keep track of  which ship to reference



next attempt:
try w/o a physical board, just record 2 lists to compare to?
use ships to hold values, and use anti-collision distances to keep from going out of bounds?
this is b/c reseting the board each time takes a really long time