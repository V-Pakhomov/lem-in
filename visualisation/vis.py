#!/usr/bin/python3.8

import sys
import networkx as nx
import matplotlib.pyplot as plt

def is_room(line):
	line = line.split()
	if len(line) != 3:
		return False
	try:
		x = int(line[1])
		y = int(line[2])
		return True
	except Exception:
		return False 

def is_link(line):
	if line[0] == '#' or line[0] == 'L':
		return False
	return len(line.split('-')) == 2

ants = input()
if ants == 'Error':
	print(ants)
	exit(1)
G = nx.Graph()
for line in sys.stdin:
	if is_room(line):
		G.add_node(line.split()[0])
	elif is_link(line):
		G.add_edge(line.split('-')[0],line.split('-')[1])
nx.draw_kamada_kawai(G, node_color='black',edge_color='b', node_size=30, width=0.15)
# nx.draw_spring(G, node_color='black',edge_color='b', node_size = 30)
# nx.draw_circular(G, node_color='black',edge_color='b', node_size = 30)
# nx.draw_random(G, node_color='black',edge_color='b', node_size = 30)
plt.show()