Readme file for Backgammon   ---   Version 1.0 Beta 5  |  Date: 7/15/98

-----------------------

PLEASE MAXIMIZE THIS WINDOW

Welcome to my experimental version of Backgammon! In this early stage of development, the program still has a low-tech, text-based engine and contains many bugs. It is meant purely for quality control testing and in no way resembles the final product.

Gameplay:

In this early version of Backgammon, text prompts are used to input moves. To roll, hit the 'r' key at the prompt. To move, simply input the column number of the checker you want to move in the 'from' prompt and where you want to move it in the 'to' prompt. To move from the bar, type in '0' in the 'from' prompt and where you want to move it in the 'to' prompt. To bear off a checker, type what checker you want to bear off in the 'from' prompt and '0' in the 'to' prompt. 

Player database:

Once you have fully completed one game of Backgammon, a file called 'stats.txt' will appear in the Backgammon directory. This contains the statistics of all players who have completed a game. Future games using the same name (case-sensitive) will automatically updates the scores for that particular player. If a player is not found in the database, they will be automatically added and their scores will default to '0-0' (wins/losses)

Future Feature List (none will definitely be added):

1. Glide (3dfx) graphics support (I really want to do this one)
2. DirectX support (possibly)
3. OpenGL support (unlikely)
4. Improved gameplay engine
5. More compact code
6. More robust file I/O engine. If there is enough interest, I will add support for       easily-managed tournament play

Bug list:

1. Some invalid moves are accepted. More information would be appreciated.
2. What I call the 'mid-move-no-go' code just doesn't work. This should be fixed in future          versions. A work-around has been implemented until this code works. Simply type '25' for both    the 'from' and 'to' inquiries.
3. Possible infinite loops caused by inputing non-letter characters, such as '\'. I don't know of    a way to fix this.
4. Both 'X' and 'O' cannot be on the bar at once. This would cause strange things to happen. This    will be fixed in a future version.


Developer Information:

Game engine/lead programmer: David Kahler (dkahler@dol.net)
Honored beta testers: David Lowery, Jeff Killmer