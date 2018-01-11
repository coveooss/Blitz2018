import blitz2k18
from blitz2k18 import NORTH, EAST, SOUTH, WEST, STILL, Move, Square
import random


myID, game_map = blitz2k18.get_init()
blitz2k18.send_init("MyPythonBot")

while True:
    game_map.get_frame()
    moves = [Move(square, random.choice((NORTH, EAST, SOUTH, WEST, STILL))) for square in game_map if square.owner == myID]
    blitz2k18.send_frame(moves)
