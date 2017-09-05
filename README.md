# filler
In this project I had to create a player to fight other students on the famous (or infamous) Filler board.
The concept is simple: two players gain points by placing on a board, one after the other,
the game piece obtained by the game master (in the form of an executable Ruby program called filler_vm).
The game ends when the game piece cannot be placed anymore.

You can find some programs to fight my algorithm against in the palyers folder, and a set of different maps in the maps folder.
Both those resources and the virtual machine were provided by 42.

In order to find a solving algorithm I took inspiration from the Go game. 
I compute every turn the center of influence for both myself and the opponent and
I generally chose the position that max my influence and min the opponent influence.
I then added 4 different functions to improve the chances of winning when my player gains a positional advantage on the board.
To do that I divide the board in 4 sectors and each time my algorithm gains a substantial advantage in one of the sectors
it tries to isolate the opponent in that sector, thus making it harder and harder for him to place his piece.

The result is that often the opponent player is surrounded quite rapidly blocking his choices.

usage:
```
$ >./filler_vm -f maps/map -p1 user1 -p2 user2
```
-f for the kind of board
-p1 first player
-p2 second player

