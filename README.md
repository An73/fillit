# About Fillit
Fillit it's program
will take a file as parameter, which contains a list of Tetriminos, and arrange them
in order to create the smallest square possible.

Executable take only one parameter, a file which contains a list of Tetriminos
to assemble. This file has a very specific format : every Tetrimino must exactly fit in a
4 by 4 chars square and all Tetrimino are separated by an newline each.
If the number of parameters sent to executable is not 1, program display
its usage and exit properly. File should contain
between 1 and 26 Tetriminos.

The description of a Tetriminos must respect the following rules:
- Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).
- A Tetrimino is a classic piece of Tetris composed of 4 blocks.
- Each character must be either a block character(’#’ ) or an empty character (’.’).
- Each block of a Tetrimino must touch at least one other block on any of his 4 sides
(up, down, left and right).

A few examples of valid descriptions of Tetriminos:
<img width="602" alt="2018-07-03 17 20 55" src="https://user-images.githubusercontent.com/33597605/42225560-7c625d20-7ee5-11e8-9031-80af2069c1d3.png">

A few examples of invalid descriptions of Tetriminos:
<img width="602" alt="2018-07-03 17 21 55" src="https://user-images.githubusercontent.com/33597605/42225601-9cac3466-7ee5-11e8-9ba6-4169fc07f4eb.png">

Because each Tetrimino fills only 4 of the 16 available boxes, it is possible to describe
the same Tetrimino in multiple ways. However, a rotated Tetrimino describes a different
Tetrimino from the original, in the case of this project. This means no rotation is possible
on a Tetrimino, when you will arrange it with the others.

Those Tetriminos are then perfectly equivalents on every aspect:
<img width="602" alt="2018-07-03 17 25 50" src="https://user-images.githubusercontent.com/33597605/42225846-28f8003a-7ee6-11e8-9165-1015e81ada5f.png">

Finally, here is an example of a valid file this program must resolve:
<img width="601" alt="2018-07-03 17 26 52" src="https://user-images.githubusercontent.com/33597605/42225942-6621ed40-7ee6-11e8-96e1-8b670f787e42.png">

The goal of this project is to arrange every Tetriminos with each others in order to make
the smallest possible square. But in some cases, this square should contains holes when
some given pieces won’t fit in perfectly with others.
Even if they are embedded in a 4x4 square, each Tetrimino is defined by its minimal
boundaries (their ’#’). The 12 remaining empty characters will be ignored for the
Tetriminos assemble process.
Tetriminos are ordered by they apparition order in the file. Among all the possible
candidates for the smallest square, we only accept the one where Tetriminos is placed on
their most upper-left position.

# Program output
To start with a program using a makefile
<img width="786" alt="2018-07-03 17 33 47" src="https://user-images.githubusercontent.com/33597605/42226291-49ad6f3a-7ee7-11e8-8623-0415456a320e.png">

This program display the smallest assembled square (for this I used backtrack algorithm) on the standard output. To
identify each Tetrimino in the square solution, i assigned a capital letter to each
Tetrimino, starting with ’A’ and increasing for each new Tetrimino.
<img width="776" alt="2018-07-03 17 40 55" src="https://user-images.githubusercontent.com/33597605/42226697-4d221732-7ee8-11e8-8499-c21f5e3adfb8.png">

