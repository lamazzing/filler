# filler
In this project I had to create a player to fight other students on the famous (or infamous) Filler board.
The concept is simple: two players gain points by placing on a board, one after the other,
the game piece obtained by the game master (in the form of an executable Ruby program called filler_vm).
The game ends when the game piece cannot be placed anymore.

You can find some programs to fight my algorithm against in the palyers folder, and a set of different maps in the maps folder.
Both those resources and the virtual machine were provided by 42.

usage:
```
$ >./filler_vm -f maps/map -p1 user1 -p2 user2
```
-f for the kind of board
-p1 first player
-p2 second player

