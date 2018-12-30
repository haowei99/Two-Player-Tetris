# Biquadris-Two-Player-Tetris

## Intro
This game is similar to Tetris, except it is turn-based, and is controlled via text commands. 
It is a local multiplayer game where two players can play head to head.
You have as much time as you want to plan your move.

Note: A complete UML and a detailed report regarding design techniques are provided (in PDF).

## Compilation
To compile this game in a Linux enviorment. Copy over the interface folder (the Makefile is included) and type the command make.
An executable will be created called biquadris.

## Running the Program 
To run the program with graphics, make sure you have graphics set up on your computer (for window users going through a linux 
terminal, Xming is a great tool for setting the windows up). Simple run ./biquadris

## Comand line interface
./biquadris [-text][-seed xxx][-scriptfile1 xxx][-scriptfile2 xxx][-startlevel n]

-text runs the program in text only instead of both text and graphics
-seed xxx sets the random number generator's seed to xxx. If you don't set the seed, you
 always get the same random sequence every time you run the program.
-scriptfile1 xxx Uses xxx instead of sequence1.txt as a source of blocks for level 0, for
 player 1.
-scriptfile2 xxx Uses xxx instead of sequence2.txt as a source of blocks for level 0, for
 player 2.
-startlevel n Starts the game in level n. The game starts in level 0 if this option is not
 supplied.

## Commands


## Level Breakdown

### Level 0: 
Takes its blocks in sequence from the files sequence1.txt (for player 1) and sequence2.txt (for player 2) 
or from other files, whose names are supplied on the command line.

### Level 1: 
The block selector will randomly choose a block with probabilities skewed such that
S and Z blocks are selected with probability 1/12 each, and the other blocks are selected with
probability 1/6 each.

### Level 2: 
All blocks are selected with equal probability.

### Level 3: 
The block selector will randomly choose a block with probabilities skewed such that
S and Z blocks are selected with probability 2/9 each, and the other blocks are selected with
probability 1/9 each. Moreover, blocks generated in level 3 are "heavy": every command to
move or rotate the block will be followed immediately and automatically by a downward move
of one row (if possible).

### Level 4:
In addition to the rules of Level 3, in Level 4 there is an external constructive force:
every time you place 5 (and also 10, 15, etc.) blocks without clearing at least one row, a
1x1 block (indicated by * in text, and by the colour brown in graphics) is dropped onto your
game board in the centre column. Once dropped, it acts like any other block: if it completes
a row, the row disappears. 
